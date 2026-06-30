# Blimp Design & Setup Guide

**Status:** Copter-mode bench-tested. Plane-mode bench-validated but not flight-tested (helium cost). Avatar flight validation carries over to blimp subsystems.
**Firmware base:** ArduPlane (QuadPlane backend), `ACTIVE_CONFIG = CONFIG_TYPE_BLIMP`
**Primary board:** MicoAir H743. MatekH743 is a documented alternative with different pin/UART assignments.

---

## 1. Physics & Design Rationale

The blimp is **95% buoyant** and **nose-heavy** (CG forward of center of lift). Without active control it naturally pitches down. It requires constant lift — aerodynamic or powered — to maintain altitude and attitude.

Key physical constraints that drive every design decision:

- **No roll control.** The blimp is pendularly stable in roll. Roll PIDs are disabled.
- **No pitch PID in copter mode.** High rotational inertia makes closed-loop pitch PIDs oscillatory and unusable. Pitch attitude is managed by the TVC tilt angle, not a PID loop.
- **Zero stall speed.** The aircraft must fly from 0 m/s (pure hover) to cruise. Standard ArduPlane assumptions about minimum airspeed have to be removed.
- **Bidirectional throttle.** The tail yaw motor is reversible. Throttle stick centered = idle.
- **Emergency downward thrust.** The 270° servo range allows motors to point straight down for active descent, fighting strong updrafts.

Why ArduPlane (QuadPlane) rather than ArduBlimp or ArduCopter:
- ArduBlimp lacks TECS, L1 navigation, and energy management needed for long-duration flight.
- Pure ArduCopter has no plane-mode transition or fixed-wing energy controller.
- QuadPlane gives us both worlds: VTOL (Q) modes for hover, and plane modes with TECS for forward flight.

---

## 2. Architecture: "Vectoring as Virtual Elevator"

The blimp uses a **split-range mixer** that makes ArduPlane's pitch controller act on two actuators in sequence, without the controller needing to know about either.

ArduPlane generates a single normalized pitch demand. The mixer maps it across two actuators:

```
Pitch demand 0 → elevator_tilt_handoff_point (0.5):
    Elevator fills proportionally to full deflection.
    Motors remain at forward cruise angle (90°).

Pitch demand handoff_point → 1.0:
    Elevator holds saturated.
    Motors tilt from forward (90°) toward vertical (0°) or reverse (-90°).
```

**Why this works for the blimp specifically:**
- At zero airspeed the elevator generates no force. TECS naturally produces a large pitch-up demand. The mixer saturates the elevator and tilts the motors up, providing powered lift.
- As airspeed builds the `surface_speed_scaler` drops, pitch demand decreases, motors unwind toward forward, and the blimp flies "on the wing" efficiently.
- TECS "pitch down to accelerate" naturally tilts motors back toward forward. Energy management aligns with physical actuator state without any special logic.

**Why the blimp differs from Avatar here:**
The Avatar has a rear motor that actively provides nose-down pitch authority. The elevator must not fight the rear motor, so Avatar uses direct tilt control. The blimp has no rear motor contribution in this role, and its nose-heavy CG means the elevator wants to be permanently at full-up — making the split-range approach natural.

**Implementation:** `AP_Motors6DOF_BlimpMixer::mix()` plane-mode branch, via `elevator_tilt_split()` in `AP_Motors6DOF_Mixer.h`. The handoff point is `g_config.elevator_tilt_handoff_point = 0.5f` from `blimpConfig`.

### Elevator in copter mode

In copter mode the elevator is a **passive trim**, not a control signal:

```cpp
outputs.elevator_out = cosf(radians(state.current_tilt_deg));
```

- Motors vertical (0°): `cos(0°) = 1.0` → elevator full up → nose-up bias counteracts nose-heavy CG.
- Motors horizontal (90°): `cos(90°) = 0.0` → elevator neutral.

This is the opposite sign from Avatar, which uses a nose-down elevator bias because the rear motor creates a nose-up pitching moment.

### Motor vectoring geometry

`blimpConfig.forward_flight_physical_angle_deg = 180.0f` and `reverse_flight_physical_angle_deg = -90.0f`. The full 270° servo range:

| Angle | Position | Use |
|-------|----------|-----|
| -90° | Reverse | Braking / backward |
| 0° | Vertical up | Hover / max lift |
| +90° | Forward cruise | Normal forward flight |
| +180° | Vertical down | Emergency descent |

Servo TRIM is calibrated to the 0° (vertical) position — this ensures a hardware-verified hover reference even if the mechanism is asymmetric.

### Non-obvious code behaviors

**`transition_progress` is a binary flag, not a gradient.** In `quadplane.cpp`:
```cpp
plane_inputs.transition_progress = in_vtol_mode() ? 0.0f : 1.0f;
```
The value jumps directly from 0 to 1 when switching flight modes. The `> 0.5f` check in `BlimpMixer::mix()` is simply testing whether the mode is currently a plane mode — there is no intermediate state or gradual transition animation.

**Forward input scaling (`× 2.0f`).** `BlimpMixer` doubles `inputs.forward` before feeding the TVC:
```cpp
tvc_in.rc_in[FORWARD_CHANNEL] = f2pwm(inputs.forward * 2.0f, -1.0f, 1.0f);
```
ArduPlane's `Q_ANGLE_MAX` (e.g., 30°) caps the pilot pitch demand fed into the 6DOF attitude controller, so `_forward_in` never reaches 1.0 at full stick. The `2.0f` re-normalises full-stick to 1.0 for the TVC. Avatar handles the same issue with the named constant `AVATAR_FORWARD_INPUT_MAX = 0.42f` and a comment explaining the reason. The blimp's factor has no comment.

**Throttle channel mapping (`−1..1`, not `0..1`).** Because `tricopter_is_blimp = true`, `AP_Motors6DOF::output_armed_stabilizing()` calls `get_throttle_bidirectional()` instead of `get_throttle()`. `inputs.throttle` is therefore in `−1..1`. The TVC maps this with `f2pwm(inputs.throttle, -1.0f, 1.0f)`: zero throttle → 1500 PWM (idle), full throttle → 2000, full reverse → 1000. Avatar uses unidirectional motors and maps `0..1` to `1500..2000` (positive half only) — a different encoding of the same THRUST_CHANNEL.

**Tilt servo tracking — `[BL-INVAR:tilt-servo-tracking]`.** After the TVC call, `outputs.tilt_angle` is set to the TVC target immediately — the servo moves as fast as it physically can. `state.current_tilt_deg` is a separate software model of the servo's physical position, updated each loop at the rate given by `Q_TILT_RATE_UP`. Motor thrust (`throttle_thrust *= cos(error_deg)`) and elevator trim (`outputs.elevator_out = cos(state.current_tilt_deg)`) both use the model, not the target. The problem this solves: commanding forward thrust tilts the motors toward horizontal, but while the servo is still near-vertical the thrust vector is mostly upward — if the mixer used the target angle, it would compute roll and throttle for a tilt that hasn't happened yet, producing an altitude spike and wrong roll authority. The elevator trim has the same concern: jumping to the trim value for the target angle before the servo reaches it causes a transient pitch disturbance. The blimp's mechanism range is 270° (vertical up through forward cruise to vertical down for emergency descent). **`Q_TILT_RATE_UP` is a dependent variable** — it must be calibrated to the measured physical slew rate of the tilt mechanism in degrees/second of gondola travel (not servo shaft degrees, if geared). Calibration: command a full-range tilt, measure seconds, set `Q_TILT_RATE_UP = range_deg / seconds`. The identical mechanism exists in the Avatar mixer (`[AV-INVAR:tilt-servo-tracking]`), where the range is 90° and the correct value will be proportionally different.

**Throttle suppression bypass.** `QuadPlane::update_throttle_suppression()` returns immediately for blimp:
```cpp
if (g_config.tricopter_is_blimp) { return; }
```
ArduPlane normally suppresses copter motor outputs when in fixed-wing flight. The blimp bypasses this because it needs motors running at all times — without powered lift it pitches down uncontrollably (nose-heavy CG, no aerodynamic surface authority at low speed).

---

## 3. TECS & Airspeed Modifications (Implemented)

These changes are live in the codebase:

- **`MIN_AIRSPEED_MIN = 0`** in `ArduPlane/defines.h` — removes the 5 m/s floor on `AIRSPEED_MIN`, allowing the system to accept 0 m/s as a valid flight state.
- **TECS `_TAS_state` floor** — the hardcoded 3.0 m/s minimum has been replaced with `aparm.airspeed_min * EAS2TAS` (with a 0.1 m/s division guard). With `AIRSPEED_MIN = 0` this allows the estimator to reach zero without resetting.

Without these changes TECS would see hover as a chronic underspeed condition and command aggressive pitch-down to recover airspeed, destabilizing the aircraft.

### Navigation yaw (parameter approach)

The blimp cannot roll, so standard bank-to-turn navigation fails. These parameters implement "phantom bank" — the nav controller commands a roll (which moves ailerons) and `KFF_RDDRMIX` routes that aileron command directly to the rudder:

| Parameter | Value | Purpose |
|-----------|-------|---------|
| `ROLL_LIMIT_DEG` | 45 | Allow nav to command phantom bank |
| `KFF_RDDRMIX` | 1.0 | Route aileron command → rudder |
| `RUDDER_ONLY` | 1 | Prioritize rudder for heading |

Alternative (not yet implemented): override `calc_nav_yaw_coordinated()` in `ArduPlane/Attitude.cpp` to compute yaw rate from lateral acceleration directly, bypassing the bank angle check.

---

## 4. Build

Switch to blimp in `libraries/AP_CustomConfig/AP_CustomConfig.h`:
```cpp
#define ACTIVE_CONFIG CONFIG_TYPE_BLIMP
```

```bash
./waf configure --board MicoAir743 --enable-scripting --disable-crsf
./waf plane
```

**MatekH743 alternative:**
```bash
./waf configure --board MatekH743 --enable-scripting --disable-crsf
./waf plane
```

`--enable-scripting` is required — `AC_AttitudeControl_Multi_6DoF` is gated behind `AP_SCRIPTING_ENABLED`. `--disable-crsf` frees enough flash to fit within the 2 MB limit.

---

## 5. Hardware Wiring (MicoAir H743)

### Serial ports

| ArduPilot Serial | Hardware | Role |
|-----------------|----------|------|
| SERIAL1 | UART1 | SBUS Bus A output (`PROTOCOL=30`) |
| SERIAL4 | UART4 | Debug/logging (`PROTOCOL=19`) |
| SERIAL5 | UART6 | RC Input from receiver (`PROTOCOL=23`) |

### Motor & servo outputs

| Pin | Function | Protocol | Timer | Param |
|-----|----------|----------|-------|-------|
| 1 | Right lift motor | DShot | TIM1 | `SERVO1_FUNCTION=33` |
| 2 | Left lift motor | DShot | TIM1 | `SERVO3_FUNCTION=35` |
| 3 | Tail yaw motor (reversible) | Bi-Dir DShot | TIM1 | `SERVO4_FUNCTION=34` |
| 5 | Tilt servo | PWM | TIM3 | `SERVO5_FUNCTION=95` (Scripting2) |
| 6 | Rudder servo | PWM | TIM3 | `SERVO6_FUNCTION=96` (Scripting3) |
| 7 | Elevator servo | PWM | TIM3 | `SERVO7_FUNCTION=97` (Scripting4) |
| 8 | Aileron left | PWM | TIM3 | `SERVO8_FUNCTION=98` (Scripting5) |
| 9 | Aileron right | PWM | TIM3 | `SERVO9_FUNCTION=99` (Scripting6) |

All surface outputs use Scripting channels. ArduPlane's mixing pipeline writes to named channels (`k_aileron`, `k_elevator`, `k_rudder`) in plane modes and would overwrite a custom mixer using those functions.

**Dummy captures required** (enable ArduPlane plane-mixer logic without physical connections):
```
SERVO13_FUNCTION = 21   (Rudder)
SERVO14_FUNCTION = 19   (Elevator)
SERVO15_FUNCTION = 70   (Throttle)
```

**DShot / PWM separation:** DShot and PWM cannot share a timer. TIM1 (pins 1–4) → DShot only. TIM3 (pins 5–6) → PWM only.
- `SERVO_BLH_MASK = 15` — DShot on outputs 1–4 only
- `SERVO_BLH_AUTO = 0` — disable auto-detection
- `SERVO_BLH_3DMASK` — must include the tail yaw motor channel for bi-directional 3D DShot

### MatekH743 serial ports (alternative board)

| Port | Protocol | Device | Baud |
|------|----------|--------|------|
| SERIAL1 | 9 (Lidar) | Benewake TF02-Pro | 115200 |
| SERIAL4 | 32 (MSP) | Matek 3901-L0X optical flow | 115200 |

---

## 6. Parameter Configuration

### QuadPlane setup
```
Q_ENABLE = 1
Q_FRAME_CLASS = 1   (Quad)
Q_FRAME_TYPE = 1    (X)
Q_TILT_RATE_UP = <measured>   (physical slew rate of tilt mechanism in deg/s — see [BL-INVAR:tilt-servo-tracking])
```

`Q_TILT_RATE_UP` is **not a tuning knob** — it must equal the measured physical speed of the tilt gondola mechanism. Calibrate by commanding a full-range tilt and timing it: `Q_TILT_RATE_UP = 270 / seconds`. Wrong values cause altitude spikes and incorrect roll authority during tilt transients.

### ESC & DShot
```
MOT_PWM_TYPE = 5        (DShot300)
SERVO_BLH_AUTO = 0
SERVO_BLH_MASK = 15
SERVO_BLH_BDMASK = 0    (disable bi-dir DShot RPM unless needed)
SERVO_BLH_OTYPE = 5     (DShot300)
```

### Arming & throttle
```
PILOT_THR_BHV = 1       (center stick = idle; disables low-throttle arming check)
ARMING_RUDDER = 0       (disable rudder arming)
RC9_OPTION = 153        (arm/disarm switch)
Q_ASSIST_SPEED = -1     (required to disable assist — would cause loss of control on tilt-rotor)
```

`ARMING_CHECK` must exclude the RC check (or set to 0 for testing). Standard ArduPilot requires throttle at minimum PWM to arm; on the blimp minimum PWM is full reverse, not idle.

### Airspeed (critical)
```
AIRSPEED_MIN = 0        (allows hover; requires custom firmware with MIN_AIRSPEED_MIN=0)
ARSPD_USE = 0           (if no physical airspeed sensor)
ARSPD_TYPE = 0          (if no physical airspeed sensor)
```

If airspeed sensor is enabled but not physically connected, EKF reports unhealthy in plane modes and prevents arming.

### Flight modes
```
FLTMODE_CH = 6
Mode 1: QSTABILIZE     (manual VTOL)
Mode 2: QLOITER        (position hold — requires optical flow)
Mode 3: QHOVER         (altitude hold)
```

### Weathervaning (QLOITER)
```
WVANE_DIRECTION = 1     (nose into wind)
WVANE_GAIN = 1.0
WVANE_ANG_MIN = 1.0
```

Note: When testing with ArduCopter binary (not ArduPlane), weathervaning in LOITER also requires `custom_weathervane = true` in `AP_CustomConfig.cpp`. The WVANE params alone are insufficient in the copter build.

### Hover & descent speeds (blimp inertia — conservative)
```
Q_WP_SPD_DN = 30        (30 cm/s auto descent)
Q_WP_SPD_UP = 30        (30 cm/s auto climb)
Q_PILOT_SPD_DN = 0
Q_PILOT_SPD_UP = 30
Q_PILOT_ACCEL_Z = 50
Q_M_THST_HOVER = 0.3   (adjust for buoyancy)
```

Descent speed must be below the blimp's natural unpowered terminal velocity so the autopilot never needs active downward thrust in auto modes.

### Loiter (high inertia tuning)
```
Q_LOIT_SPEED = 200          (2 m/s max)
Q_LOIT_ACC_MAX = 50
Q_LOIT_BRK_ACCEL = 25
Q_LOIT_BRK_JERK = 100
Q_LOIT_ANG_MAX = 20
WP_RADIUS = 10
Q_WP_RADIUS = 10
```

Large waypoint radius prevents oscillation around waypoints the blimp cannot physically turn sharp enough to hit.

**`Q_LOIT_ACC_MAX` / `Q_LOIT_BRK_ACCEL` / `Q_LOIT_BRK_JERK` are the deliberate "accelerate/brake slowly" levers (indoor blimp case).** They form a trio that shapes loiter motion — defaults are 500 / 250 / 500; the blimp values above (50 / 25 / 100) are much gentler so the airship eases into and out of motion indoors without overshooting:
- `Q_LOIT_ACC_MAX` — bounds the commanded velocity ramp (lower = slower forward acceleration)
- `Q_LOIT_BRK_ACCEL` — bounds stick-release braking (lower = gentler stop)
- `Q_LOIT_BRK_JERK` — bounds how fast braking ramps in (lower = softer onset of the stop)

⚠️ **All three MUST be raised back toward default (500 / 250 / 500) on any normal-inertia aircraft.** Leaving them low caps how hard the vehicle can accelerate. On a tilt-rotor (Avatar) this also caps forward wing tilt in QLOITER: a low accel ceiling means the loiter controller never demands enough lean → the 6DoF `−sin(lean)` forward command stays small → the wings never tilt fully forward. A leftover low value here was traced as the cause of "QLOITER won't tilt the wings forward" on the Avatar (June 2026).

### PID tuning (blimp-specific starting points)
```
Q_A_RAT_RLL_P = 0.05
Q_A_RAT_RLL_I = 0.05
Q_A_RAT_RLL_D = 0
Q_A_RAT_PIT_P = 0.05
Q_A_RAT_PIT_I = 0.05
Q_A_RAT_PIT_D = 0
Q_A_RAT_YAW_P = 0.1
Q_A_RAT_YAW_I = 0.01
Q_A_RAT_YAW_D = 0
Q_A_RAT_YAW_FF = 0.5    (primary yaw authority — direct stick to motor)
Q_A_RATE_Y_MAX = 30
```

High rotational inertia: start very low on P/I, use FF for yaw authority.

### Takeoff & landing (plane modes — not yet flight-tested)
```
TKOFF_THR_MINACC = 0    (disable launch acceleration check)
TKOFF_ROTATE_SPD = 0    (allow immediate vectoring)
LAND_PITCH_DEG = 15     (triggers vectoring for powered hover-settle)
LAND_FLARE_ALT = 5      (higher than typical; allows time for motor tilt)
LAND_SLOPE_RCALC = 2.0
PTCH_LIM_MAX_DEG = 45-60   (allow large pitch for hover/braking transients)
```

### Navigation yaw (plane modes — parameter approach)
```
ROLL_LIMIT_DEG = 45
KFF_RDDRMIX = 1.0
RUDDER_ONLY = 1
```

### Failsafe
```
FS_THR_ENABLE = 1
FS_EKF_ACTION = 1       (QLand)
FS_EKF_THRESH = 0.8
BATT_FS_LOW_ACT = 2     (QLand)
```

`FAILSAFE_KILL_MOTORS = true` in `blimpConfig` — on RC failsafe the blimp immediately disarms, allowing safe drift on buoyancy.

### Tilt servo calibration
1. Set `SERVO5_FUNCTION = 0` (disabled)
2. Use Mission Planner servo tab to find PWM values for vertical, forward, backward
3. Set `SERVO5_TRIM` = vertical (0°), `SERVO5_MAX` = forward (90°), `SERVO5_MIN` = backward (-90°)
4. Restore `SERVO5_FUNCTION = 95`

TRIM must be at the physical midpoint of total servo travel. If TRIM is off-center, positive and negative tilt ranges will be unequal.

---

## 7. Platform Stabilization (Payload Gimbal)

Active 2-axis stabilization keeps a payload platform level regardless of blimp pitch/roll. Output = −attitude, so a +45° blimp pitch → −100% servo command.

- Enabled via `optical_flow_stabilized_roll` and `optical_flow_stabilized_pitch` in `blimpConfig`
- Platform roll servo: `SERVOn_FUNCTION = 98` (Scripting5)
- Platform pitch servo: `SERVOn_FUNCTION = 99` (Scripting6)
- Default scaling: ±45° = ±100% servo travel

---

## 8. Peripherals

### Rangefinder (Benewake TF02-Pro)
```
SERIAL1_PROTOCOL = 9
SERIAL1_BAUD = 115
RNGFND1_TYPE = 27
RNGFND1_MIN_CM = 1
RNGFND1_MAX_CM = 4000
RNGFND1_ORIENT = 25     (down)
```

### Optical flow (Matek 3901-L0X, MSP)
```
SERIAL4_PROTOCOL = 32
SERIAL4_BAUD = 115
FLOW_TYPE = 6
FLOW_ADDR = 0
```

### EKF3 (GPS + optical flow + lidar fusion)
```
EK3_ENABLE = 1
EK3_FLOW_USE = 1        (Navigation — must change from default of 2/Terrain)
EK3_SRC1_POSXY = 3      (GPS)
EK3_SRC1_VELXY = 3      (GPS)
EK3_SRC1_POSZ = 2       (RangeFinder)
EK3_SRC1_YAW = 1        (Compass)
EK3_SRC2_VELXY = 5      (Optical Flow)
EK3_SRC_OPTIONS = 1     (FuseAllVelocities)
EK3_RNG_USE_HGT = 70
EK3_RNG_USE_SPD = 2.0
FLOW_POS_X/Y/Z          (measure sensor offset from CG in meters)
```

---

## 9. Pre-Flight Verification

1. **Tilt servo:** calibrate TRIM/MIN/MAX as described in Section 6
2. **Motor direction:** motor test — lift motors blow down, tail motor spins both directions
3. **Vectoring (QSTABILIZE):** arm, raise throttle slightly
   - Pitch stick forward → servos tilt forward
   - Pitch stick back → servos tilt back
   - Pitch nose up manually → servos compensate forward (pitch compensation)
4. **Plane transition ground test:** arm in QSTABILIZE → switch to FBWA → motors stay spinning, pitch stick tilts motors, yaw stick moves rudder → switch back

---

## 10. Flight Test Notes

Plane-mode behavior has been bench-validated through logic review but **not yet flight-tested**. Helium cost makes iteration expensive. Avatar flight validation provides confidence in:
- TVC brain (`tvc_run_main_logic`) — shared code path
- Elevator-tilt split mechanics — same `elevator_tilt_split()` function
- TECS zero-airspeed modifications — same ArduPlane codebase

Unknowns specific to the blimp:
- Actual `PTCH_RATE_I` value needed for hover equilibrium (I-term must wind up to hold nose up against gravity)
- `elevator_tilt_handoff_point` tuning (currently 0.5f)
- Servo slew rate limit (`SERVOx_RATE`) to prevent reaction torque oscillations
- `surface_speed_scaler` ceiling needed (proposed `BLIMP_MAX_SPEED_SCALER ≈ 4.0x` in Attitude.cpp to prevent infinite gain as airspeed approaches zero — not yet implemented)
