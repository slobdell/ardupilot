# Design Document: Avatar Tilt-Rotor Fixed-Wing Aircraft

**Status:** AvatarMixer implemented and bench-tested on Zoh Altus VTOL (MicoAir H743, June 2026)
**Test Airframe:** Zoh Altus VTOL

---

## 1. Concept & Mission

The Avatar is a zero-stall-speed fixed-wing aircraft. The core idea is that the aircraft's wings themselves rotate on a servo-driven axis, carrying the motors with them. At low speeds or during stall conditions, the wings tilt upward toward vertical, converting the motors into a hover-capable lift system. At cruise speed, the wings are horizontal and the motors provide forward thrust in the conventional sense.

The design goal is that this transition happens **automatically and continuously** — it is not a discrete mode switch. The aircraft should always be trying to fly as a plane, and the motor tilt naturally adjusts to whatever the aerodynamics require.

---

## 2. Hardware Layout

### 2.1 Motors
- **Motor 1 (Left Wing):** Fixed to the left wing, tilts with the wing. Provides lift and/or forward thrust depending on wing angle.
- **Motor 2 (Right Wing):** Fixed to the right wing, tilts with the wing. Always commanded identical thrust to Motor 1.
- **Motor 3 (Rear Right Yaw):** Spring-lever mounted rear motor. Differential thrust with Motor 4 produces lateral (yaw) force via the spring-lever mechanism. Also contributes lift as wings tilt toward vertical.
- **Motor 4 (Rear Left Yaw):** Spring-lever mounted rear motor, paired with Motor 3 for differential yaw.

### 2.2 Servos
- **Single Tilt Servo:** Drives both wings simultaneously via a shared mechanical linkage. Controls the pitch axis of the thrust vector only. **Roll axis tilt is mechanically impossible** and is not implemented.

### 2.3 Yaw
Two rear motors on spring-loaded levers provide yaw authority at low speeds and in copter mode. Differential thrust causes the higher-thrust motor to swing outward and deliver lateral side force. **This mechanism is implemented on the T1 Ranger test airframe** (Motor 3 = right rear on SERVO3, Motor 4 = left rear on SERVO2).

**Sign convention:** positive `inputs.yaw` = right yaw. In the mixer: `YAW_LEFT = rear + yaw_delta`, `YAW_RIGHT = rear - yaw_delta`. Note this is opposite to the intuition from torque-based copter yaw — the differential here is thrust, not torque.

**PID tuning:** `Q_A_RAT_YAW_P` and `Q_A_RAT_YAW_I` use standard positive values (start at 0.05 / 0.005). `Q_A_RAT_YAW_FF = 0.5` provides direct stick feedthrough. The attitude controller's yaw rate PID sign is correct with the current motor assignment.

### 2.4 Roll Control
Roll is achieved via differential thrust between the two wing motors. Effectiveness scales with `cos(wing_tilt_angle)`:

- **Wings vertical (hover, 0°):** `cos(0°) = 1.0` — full roll authority
- **Wings horizontal (forward flight, 90°):** `cos(90°) = 0.0` — no roll authority
- **Intermediate angles:** proportional authority (e.g., 45° → 0.7)

This is physically motivated: motors pointing upward produce roll when thrust is differential; motors pointing forward produce yaw instead. The yaw side effect from prop torque imbalance is accepted as a known limitation. Roll authority smoothly fades to zero as the aircraft transitions to forward flight, at which point aerodynamic surfaces take over.

---

## 3. Relationship to the Blimp

The Avatar and the Blimp share the same fundamental control philosophy and the same TVC brain (`tvc_run_main_logic`). The pattern match is direct:

| Concept | Blimp | Avatar |
|---------|-------|--------|
| Thrust-vectored motors | 2 on a tilting gondola | 2 on tilting wings |
| Tilt servo | 1 (pitch only) | 1 (pitch only) |
| Default position | Motors face forward | Wings horizontal |
| Elevator saturation response | Gondola tilts upward | Wings tilt upward |
| Emergency downward thrust | Yes (fly-away recovery) | No |
| Yaw motor | 1 tail motor | 1 rear motor (optional) |
| Roll control | None | Differential thrust, scaled by `cos(tilt_angle)` |
| TVC core | `tvc_run_main_logic` | `tvc_run_main_logic` (reused) |

The key difference is geometry: the blimp's tilt range spans past vertical (up to 180° for downward emergency thrust), while the Avatar's range is 0° (wings vertical = hover) to 90° (wings horizontal = forward flight). This is reflected in `avatarConfig`:

```cpp
.forward_flight_physical_angle_deg = 90.0f,   // Wings horizontal
.reverse_flight_physical_angle_deg = 0.0f,    // No downward thrust
```

---

## 4. Control Architecture

### 4.1 The 6DOF Motor Mixer Philosophy

This is a critical distinction from a conventional fixed-wing. The Avatar uses the ArduPilot 6DOF motor mixer, which means:

- **Forward stick** → forward thrust vector (wings tilt slightly forward) — **not** a pitch command
- **Throttle** → vertical thrust component
- **ArduPilot's attitude controller** maintains level flight by adjusting throttle, not by pitching the nose

This means the aircraft can fly forward while remaining aerodynamically level. The intended base test case is: arm in copter mode, apply forward stick, aircraft moves forward slowly via motors tilting slightly forward, ArduPilot increases throttle to compensate for the reduced vertical component.

### 4.2 Wing Tilt Logic (The TVC Brain)

Wing tilt is computed by `tvc_run_main_logic` and is identical to the blimp. The key formula:

```cpp
float target_pitch_deg = atan2(forward_cmd, thrust_cmd);
target_pitch_deg += current_pitch_deg;  // Pitch compensation
```

The `atan2` converts the pilot's 2D thrust intent (forward + vertical) into a target wing angle. The pitch compensation offsets this by the aircraft's actual pitch, ensuring the absolute thrust vector stays in the intended direction regardless of aircraft orientation.

**This is also the stall-prevention mechanism** (see section 4.3).

The output `pitch_angle_norm` drives the single tilt servo via `outputs.tilt_angle` in the mixer.

The code runs in `OPEN_LOOP_SERVO_MODE = true`, meaning stick position maps directly to servo angle with no PID. This is simpler and appropriate for initial testing.

### 4.3 Automatic Stall Prevention

The stall-prevention behavior is a natural consequence of the pitch compensation — it is not a separate feature or mode switch.

**Sequence at low-speed/stall:**
1. Aircraft starts to pitch up (nose rises) due to lack of airspeed or aerodynamic instability
2. Elevator is already saturated — conventional pitch control is exhausted
3. `current_pitch_deg` increases (aircraft is pitched up)
4. `target_pitch_deg += current_pitch_deg` causes the TVC to command a larger tilt angle
5. Wings tilt upward toward vertical
6. More of the motor thrust is directed upward → lift increases → aircraft is stabilized

**Sequence during normal cruise:**
1. Aircraft has airspeed, elevator is effective, ArduPilot maintains level attitude
2. `current_pitch_deg ≈ 0°`
3. Compensation adds ~0° to the target
4. Wings stay near horizontal → normal forward flight

This is a continuous, proportional response. There is no threshold or mode switch. The wings tilt as much as the pitch deviation demands.

### 4.4 Plane Mode Pitch Control

The Avatar is optimised for maintaining a **level fuselage at all times** — it carries advertising signage and stability matters more than pitch agility. This drives a design that differs from both the blimp and standard ArduPlane.

**Single copter controller drives both elevator and rear motor in FBWA:** Both the elevator surface and the rear motor are driven by the same copter attitude PID output (`inputs.pitch`). The ArduPlane fixed-wing pitch PID (`elevator_input`) is discarded for Avatar in plane mode.

`nav_pitch_cd` (set by FBWA stick mapping and modified by TECS stall recovery) drives the **tilt angle** — not the elevator. When TECS wants more pitch-up, the wings tilt upward, which is the Avatar equivalent of a conventional aircraft pitching up. The elevator's sole job is to hold the fuselage level.

#### Tilt rotors — driven by nav_pitch_cd (TECS + pilot)

Tilt angle is derived from `nav_pitch_cd`, which combines pilot pitch stick input (via FBWA stick mapping in `mode_fbwa.cpp`) with TECS modifications (stall recovery, energy management):

```cpp
// quadplane.cpp — PlaneInputs injection
// [AV-INVAR:tilt-follows-nav-pitch] — see § 9
plane_inputs.pitch_tilt_demand = in_vtol_mode() ? 0.0f :
    constrain_float(plane.nav_pitch_cd / (plane.aparm.pitch_limit_max * 100.0f), -1.0f, 1.0f);

// AP_Motors6DOF_AvatarMixer.cpp, plane mode block
outputs.tilt_angle = constrain_float(1.0f - inputs.plane.pitch_tilt_demand, 0.0f, 1.0f);
```

Pitch-up demand (positive `nav_pitch_cd`) tilts rotors toward vertical. Pitch-down is a no-op — `tilt_angle` is clamped at 1.0 (horizontal). See section 4.4.3 for the TODO to add past-horizontal tilt.

**Why `nav_pitch_cd` and not raw pilot stick?** TECS can modify `nav_pitch_cd` for stall recovery — if the aircraft loses airspeed, TECS demands more pitch-up, which tilts the wings upward to recover lift. Raw pilot stick would bypass this safety mechanism.

**Why not elevator-first (blimp approach)?** The blimp design tilts rotors only after elevator saturation. The Avatar has a rear motor and is optimised for level station-keeping, so tilt responds directly to demand. The elevator's job is entirely separate.

#### Elevator — copter attitude PID output

The elevator has one job: hold the fuselage level. It is driven by the copter attitude controller's pitch output — the same signal that drives the rear motor:

```cpp
// [AV-INVAR:elevator-follows-pitch-pid] — see § 9
outputs.elevator_out = inputs.pitch;
```

`inputs.pitch` is generated by the copter rate PID targeting `0° - actual_pitch`. When nose-up, `inputs.pitch` is negative → elevator goes down → nose down ✓. The ArduPlane pitch PID (`elevator_input`) is ignored.

**Why not the ArduPlane pitch PID?** `elevator_input` is computed from `nav_pitch_cd`, which now drives tilt angle. Using `elevator_input` would make the elevator try to pitch the nose to match the tilt demand — exactly wrong.

**Elevator and rear motor cooperation:** Both `elevator_out` and `rear_demand` are driven by `inputs.pitch`. In hover (cos_tilt=1): both actuators cooperate. At cruise (cos_tilt=0): rear motor is zero, elevator carries full pitch authority. No explicit scaling on the elevator — aerodynamic authority increases with airspeed naturally as the rear motor fades.

**Roll differential in plane mode:**
```cpp
float roll_delta = inputs.roll * cos_tilt_b;  // [AV-INVAR:ang-vel-roll-tracking]
outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = throttle_pct + roll_delta;
outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = throttle_pct - roll_delta;
```
Driven by the copter roll PID targeting `nav_roll_cd` (same bank angle the FBWA autopilot commands). Fades to zero at wings-horizontal where ailerons take over.

**`PTCH_LIM_MAX_DEG` must remain at 90°:** `pitch_tilt_demand` is normalized as `nav_pitch_cd / (pitch_limit_max * 100)`. A typical fixed-wing value (e.g. 20°) would cap `nav_pitch_cd` at 2000 cd, meaning `pitch_tilt_demand` maxes at 0.22 — motors can never reach fully vertical. 90° maps full pitch demand to full vertical tilt.

**`PTCH_LIM_MAX_DEG` must remain at 90°:** `pitch_tilt_demand` is normalized as `nav_pitch_cd / (pitch_limit_max * 100)`. A typical fixed-wing value (e.g. 20°) would cap `nav_pitch_cd` at 2000 cd, meaning `pitch_tilt_demand` maxes at 0.22 — motors can never reach fully vertical. 90° maps full pitch demand to full vertical tilt. Tune to whatever attitude range makes sense for the mission.

**V-tail mixing:** Avatar owns all V-tail servo outputs. Mixing is computed in `AP_Motors6DOF::output_to_motors()`: `vtail_left = elevator_out + rudder_out`, `vtail_right = elevator_out - rudder_out`. This runs in both copter and plane modes — in copter mode `elevator_out = 0`, so the V-tail provides yaw authority only.

### 4.4.1 Rear Motor Pitch Stabilisation During Tilt (Plane Mode)

**The problem:** As the wing motors tilt from horizontal toward vertical, their thrust vector rotates. This rotation generates an uncontrolled pitch-up moment on the airframe. The elevator is already saturated at this point (that is what triggered the tilt in the first place), so it has no headroom left to resist this moment. Without active counteraction the aircraft will pitch up uncontrollably as the wings rotate.

**The solution:** The rear motor provides a nose-down pitching moment proportional to the aircraft's pitch deviation from level:

```cpp
float tilt_deg_b = outputs.tilt_angle * g_config.forward_flight_physical_angle_deg;
float cos_tilt_b = fmaxf(0.0f, cosf(radians(tilt_deg_b)));
rear_motor = (throttle_pct - inputs.pitch) * cos_tilt_b;
```

`inputs.pitch` is negative when the aircraft is nose-up (correction wanted), making `throttle - negative = more than throttle`, so the rear motor increases to push the nose down. The `cos(tilt_deg)` factor gates the rear motor authority: zero when wings are horizontal (forward flight), full when wings are vertical (hover).

**Why `cos(tilt_deg)` not `tilt_delta`:** `tilt_delta` was a linear function of excess pitch demand from the old elevator-split design — not the actual physical motor angle. Using `cos(tilt_angle × 90°)` matches the geometry and is consistent with copter mode: `rear = (throttle - inputs.pitch) × cos_tilt`.

**`limit.pitch` anti-windup:** The rear motor demand is clipped by `constrain_float(..., 0, 1)`. When clipping occurs the copter pitch integrator (which produces `inputs.pitch`) must be told to stop winding up:

```cpp
float rear_demand = (throttle_pct - inputs.pitch) * cos_tilt_b;
outputs.limit.pitch = (rear_demand > 1.0f || rear_demand < 0.0f);
outputs.motor_thrust[AVATAR_MOT_YAW] = constrain_float(rear_demand, 0.0f, 1.0f);
```

`outputs.limit.pitch` flows to `AC_AttitudeControl_Multi` as the anti-windup flag for the copter pitch rate PID. It has no effect on ArduPlane's elevator PID, which manages its own limits internally.

---

**Implementation — how `inputs.pitch` is correctly generated in plane mode:**

The copter attitude controller (`AC_AttitudeControl_Multi`) produces `inputs.pitch` (= `_pitch_in`) via its rate PID. Getting a correct, responsive signal required solving several non-obvious problems:

**Problem 1 — `_attitude_target` slewing:** The angle controller (`input_euler_angle_roll_pitch_euler_rate_yaw`) internally maintains a `_attitude_target` quaternion that slews toward the commanded angle. During FBWA transition with max pitch-up stick, `_attitude_target` gets set to `nav_pitch_cd` (≈90°). Even after commanding 0°, it slews back slowly — so `_ang_vel_body.y` (the rate target fed to the rate PID) remains large and positive for many seconds, giving wrong-sign `inputs.pitch`.

**Problem 2 — `attitude_controller_run_quat()` side effects:** `input_rate_bf_roll_pitch_yaw()` also calls `attitude_controller_run_quat()` internally, which recomputes `_ang_vel_body` from the slewing `_attitude_target`. Overriding `_ang_vel_body.y` after the call still doesn't help because `attitude_controller_run_quat()` also corrupts `_pd_scale` and other state that feeds `rate_controller_run()`.

**Problem 3 — `multicopter_attitude_rate_update()` interference:** `transition->update()` calls `hold_hover()` or `hold_stabilize()` depending on transition state, which call `multicopter_attitude_rate_update()`, which calls `attitude_controller_run_quat()` again — corrupting the state even after our corrections.

**The fix — three parts:**

**(a)** Add `rate_bf_pitch_target()` to `AC_AttitudeControl.h` (mirrors existing `rate_bf_yaw_target()`). This directly writes `_ang_vel_body.y` without invoking `attitude_controller_run_quat()`:

```cpp
void rate_bf_pitch_target(float rate_cds) { _ang_vel_body.y = radians(rate_cds * 0.01f); }
```

**(b)** Skip `transition->update()` for Avatar in plane mode (use `force_transition_complete()` instead). This prevents `multicopter_attitude_rate_update()` from ever running and corrupting attitude controller state.

**(c)** Compute the pitch rate target directly from AHRS pitch, bypassing the angle controller entirely:

```cpp
// In QuadPlane::update(), ENABLE_TRICOPTER_VTOL_BACKEND block, plane mode, Avatar only:
// [AV-INVAR:cos-tilt-i-zero] — I scale: full at <=45° (hover), zero at >=90° (cruise)
const float tilt_deg = ((AP_Motors6DOF*)motors)->get_tilt_deg();
const float i_scale = constrain_float(1.0f - (tilt_deg - 45.0f) / 45.0f, 0.0f, 1.0f);

AC_PID& pitch_pid = attitude_control->get_rate_pitch_pid();
if (i_scale < 1.0f) { pitch_pid.set_integrator(pitch_pid.get_i() * i_scale); }
const float pitch_error_rad = -ahrs.get_pitch();   // 0° - actual_pitch
const float pitch_kP = attitude_control->get_angle_pitch_p().kP();
const float pitch_rate_cds = degrees(pitch_kP * pitch_error_rad) * 100.0f;
attitude_control->rate_bf_pitch_target(pitch_rate_cds);   // [AV-INVAR:ang-vel-pitch-bypass]

AC_PID& roll_pid = attitude_control->get_rate_roll_pid();
if (i_scale < 1.0f) { roll_pid.set_integrator(roll_pid.get_i() * i_scale); }
const float roll_error_rad = radians(plane.nav_roll_cd * 0.01f) - ahrs.get_roll();
const float roll_kP = attitude_control->get_angle_roll_p().kP();
const float roll_rate_cds = degrees(roll_kP * roll_error_rad) * 100.0f;
attitude_control->rate_bf_roll_target(roll_rate_cds);     // [AV-INVAR:ang-vel-roll-tracking]

attitude_control->set_throttle_out(get_pilot_throttle(), false, 0);
motors_output(true);
```

The pitch rate target is `pitch_kP × (0° - actual_pitch)`: negative when nose-up, positive when nose-down. The I-term is not reset unconditionally — instead it decays proportionally as tilt increases past 45°, reaching zero at 90° (cruise). This prevents windup when `cos_tilt_b` zeros the rear motor in cruise, while allowing the I-term to accumulate in hover where it's needed for steady-state correction. The surface PID I-terms (`rollController`, `pitchController`) have the complementary behaviour — they decay when tilt is *below* 45° (see `[AV-INVAR:surface-i-decay-tilt45]`).

**Files changed:**
- `ArduPlane/quadplane.cpp` — skip `transition->update()`; pitch+roll rate target computation; I-term scaled decay
- `libraries/AC_AttitudeControl/AC_AttitudeControl.h` — add `rate_bf_pitch_target()` and `rate_bf_roll_target()`
- `libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp` — rear motor and roll differential use `inputs.pitch`/`inputs.roll` with `cos_tilt_b`; elevator uses `inputs.pitch`

### 4.4.2 Future: Reverse Flight in Plane Mode

Reverse tilt (motors past vertical into a backward-facing position) while in FBWA is currently architecturally blocked. Three things would need to change:

**1. Plane mode formula clamp.** `constrain_float(1.0f - pitch_tilt_demand, 0.0f, 1.0f)` lower-bounds at `0.0`. Full pitch-up stick gives `tilt_angle = 0.0` (vertical) — it cannot go negative. To reach reverse angles, the formula needs to change. For example: `1.0f - (1.0f + k) * pitch_tilt_demand` would map full pitch-up to a configurable negative tilt. This is a one-line change in `AvatarMixer::mix()`.

**2. TECS throttle model.** TECS manages total energy assuming positive throttle = forward thrust. With motors reversed, positive throttle produces backward thrust — TECS's control law inverts. It would see low airspeed → increase throttle → more reverse thrust → further speed loss (positive feedback). Mitigation options: disable TECS when `tilt_angle < 0` (switch to direct pilot throttle-stick control), or invert the throttle-to-energy mapping for the reverse region.

**3. Copter pitch controller sign.** In FBWA, `inputs.pitch` from the copter attitude controller drives the rear motor and front motor pitch mixing to hold the fuselage level. When front motors face backward, the sign of throttle-to-pitch coupling inverts — positive `inputs.pitch` (nose-up correction) increases front motor thrust, which now pushes the nose down rather than up. The correction loop becomes a destabilisation loop. Fix: negate `inputs.pitch` contribution when `tilt_angle < 0`, or suppress the copter attitude contribution in reverse and rely solely on the elevator PID.

### 4.4.3 TODO: Past-Horizontal Tilt for Pitch-Down Descent (Needs Aircraft)

**Use case:** In FBWA, pilot pitch-down → rotors tilt a few degrees past horizontal → motors produce a small downward force component → aircraft descends while elevator PID holds the fuselage level. Gives the pilot direct descent control without needing to reduce throttle or pitch the nose.

**All plane mode abstractions hold.** At 95° physical tilt, `cos(95°) ≈ -0.09` → floored to zero by `fmaxf`. Rear motor contribution is zero. TECS throttle model is unaffected (5° past horizontal produces negligible reverse thrust). Elevator PID continues to drive attitude independently. The copter pitch sign inversion problem (section 4.4.2) does not apply — rear motor is already gated off before the sign would matter.

**What needs to change — three things:**

**1. Add `cruise_physical_angle_deg` to `CustomConfig`.** This separates "servo physical max" from "equilibrium cruise angle." The blimp already makes this distinction: `BLIMP_PLANE_FWD_ANGLE = 90.0f` (cruise) is separate from `forward_flight_physical_angle_deg = 180.0f` (servo max). For Avatar: `forward_flight_physical_angle_deg = 95.0f` (new servo max), `cruise_physical_angle_deg = 90.0f` (horizontal cruise). `cruise_norm = cruise_physical_angle_deg / forward_flight_physical_angle_deg = 0.947`.

**2. Update `AvatarMixer` plane mode formula (one line).** Change:
```cpp
outputs.tilt_angle = constrain_float(1.0f - inputs.plane.pitch_tilt_demand, 0.0f, 1.0f);
```
to:
```cpp
float cruise_norm = g_config.cruise_physical_angle_deg / g_config.forward_flight_physical_angle_deg;
outputs.tilt_angle = constrain_float(cruise_norm * (1.0f - inputs.plane.pitch_tilt_demand), 0.0f, 1.0f);
```
Neutral stick → `cruise_norm` (90° horizontal). Full pitch-up → 0.0 (vertical). Full pitch-down → `cruise_norm * 2.0` clamped to 1.0 (95°). Pitch-down authority is proportionally small (~5% of stick travel for 5°), which is correct for the gentle descent use case.

**3. Cap copter mode TVC output at `cruise_norm` (one line).** After the TVC call in copter mode, add:
```cpp
outputs.tilt_angle = constrain_float(tvc_out.pitch_angle_norm, -1.0f, cruise_norm);
```
This prevents the TVC from commanding past horizontal in copter mode, where there is no use case for past-horizontal tilt.

**Servo calibration (needs aircraft).** Horizontal has no hardware reference point (unlike vertical, which uses `SERVO5_TRIM`). Calibration procedure: physically set wings to exact horizontal, read the servo PWM, set `SERVO5_MIN` to that value. Then set the new physical max (e.g., 95°) as the actual MIN after extending travel. Keep `SERVO5_TRIM` at the vertical (hover) position — this is the invariant the TVC normalization depends on. FBWA equilibrium pitch is found by the ArduPlane pitch PID integrator, not by a static trim value, so there is no equivalent "horizontal trim" needed in the firmware.

### 4.4.4 CRUISE/AUTO Tilt Demand Chain and Its Two Tuning Parameters

In TECS modes (CRUISE, AUTO, …) with no airspeed sensor, the pilot/mission never commands tilt directly. The chain is:

```
pitch stick → target-altitude ramp (±FBWB_CLIMB_RATE m/s at full stick)
           → TECS altitude/climb-rate error
           → nav_pitch_cd  (γ ≈ v_z_demand / AIRSPEED_CRUISE radians, + error/integrator terms)
           → tilt angle    ([AV-INVAR:tilt-follows-nav-pitch])
```

**`FBWB_CLIMB_RATE`** — the full-stick climb-rate demand. NOT a tilt limit. Sets the initial tilt response via the ratio below, and the rate at which escalation winds up.

**`AIRSPEED_CRUISE`** — the airspeed TECS *assumes* when converting climb demands to pitch angles (`gain = 1/(V·g)`); with no sensor it is also the `_TAS_state` fallback. NOT a speed target (the airspeed demand path is inert with `SKE_weighting = 0`). See `[AV-INVAR:airspeed-cruise-gain]`.

**Full-stick initial tilt-up ≈ `FBWB_CLIMB_RATE / AIRSPEED_CRUISE` radians** (clipped by `TECS_CLMB_MAX` and `PTCH_LIM_MAX_DEG`). Current values 2/3 rad ≈ 38°. Raising `FBWB_CLIMB_RATE` to 5 (= `TECS_CLMB_MAX`) makes full stick demand ≥90° immediately — FBWA-bench-test feel. This ratio is the CRUISE stick-feel knob.

**90° tilt is reachable but earned, not commanded:** if the demanded climb is not achieved, altitude error adds ~4°/m of lag and the integrator is allowed to wind the demand to `PTCH_LIM_MAX`+5° within ~4–6 s. With `[AV-INVAR:tecs-synth-pitch]` raising throttle alongside tilt, the aircraft normally settles at the minimum tilt that delivers the climb — vertical is the last resort, which is the intended energy-manager behaviour.

### 4.5 Copter Mode Elevator Behavior

In copter mode the elevator (V-tail pitch surface) tracks the wing tilt angle via `cos(tilt_deg)`:

- Wings vertical (hover, 0°): `cos(0°) = 1.0` → elevator full up
- Wings horizontal (forward, 90°): `cos(90°) = 0.0` → elevator neutral

**Why the bias is nose-down:** The rear motor runs at throttle-proportional thrust in hover, generating a nose-up pitching moment. The elevator counters this with a passive nose-down bias (`-cos_tilt`). This is the opposite sign from the blimp, which has no rear motor and uses a nose-up bias as a passive headwind trim. The `cos(tilt_deg)` scaling ensures the bias fades naturally to zero as the wings rotate horizontal toward plane mode, at which point ArduPlane's pitch controller takes over active control.

**Key distinction:** The elevator in copter mode is a trim schedule, not a feedback control signal. Pitch stabilization is handled by the 6DOF attitude controller via motor thrust (rear motor + wing motor differential). The elevator `-cos_tilt` curve is purely a feedforward trim and does not conflict with the attitude controller.

### 4.6 Tilt Trig Factors

All tilt-dependent calculations use one pre-computed value:

```cpp
float cos_tilt = fmaxf(0.0f, cosf(radians(state.current_tilt_deg)));
```

`cos_tilt` is floored at zero so that cos-dependent quantities (motor roll, elevator, rear motor) fade cleanly to zero at 90° and stay at zero if the servo range is ever extended past 90°. Without the floor, cos goes negative past 90° which would invert roll authority and elevator direction.

`sin_tilt` was removed. Ailerons no longer scale by `sin_tilt`; they use the pilot roll stick input directly (see section 4.10).

**Extending the servo range — forward (past 90°):** Change `forward_flight_physical_angle_deg` in `avatarConfig`. TVC normalization and servo output are fully parametric. The mixer's `fmaxf(0.0f, cos(...))` floor handles past-90° naturally — roll authority, rear motor, and elevator trim all fade to zero at 90° and stay there.

**Extending the servo range — backward (braking / reverse, copter mode only):** To allow motors to tilt past vertical into a backward position:
1. Set `avatarConfig.reverse_flight_physical_angle_deg` to a negative value matching the physical limit (e.g., `-20.0f` for 20° backward). Currently `0.0f`, which falls back to a 0.1f division guard and clamps all backward commands to `tilt_angle = -1.0` → `SERVO5_MAX` (currently = TRIM = vertical, no movement).
2. Calibrate `SERVO5_MAX` to the PWM at the backward limit. With `SERVO5_REVERSED=1`, negative `tilt_angle` drives toward MAX via `set_output_norm`. Currently `SERVO5_MAX = SERVO5_TRIM = 1827`, which prevents any backward travel.
3. Keep `SERVO5_TRIM` at the physical vertical position — this is the invariant that the whole normalization depends on.

**Negative tilt and `cos_tilt`:** `cos` is an even function (`cos(-x) = cos(x)`), so `cos_tilt` at -20° equals `cos_tilt` at +20° ≈ 0.94. Roll authority, rear motor, and elevator trim all behave symmetrically around vertical. The `fmaxf(0.0f, ...)` floor never activates for backward angles less than 90° — it only guards the forward-past-90° case.

**Plane mode and backward tilt:** The plane mode formula `constrain_float(1.0f - pitch_tilt_demand, 0.0f, 1.0f)` has a lower bound of `0.0` — plane mode can never command negative `tilt_angle` regardless of servo range. Backward extension is copter-mode-only. See section 4.4.2 for what would need to change to enable reverse in plane mode.

### 4.7 Front Motor Pitch Mixing

The autopilot pitch term (`inputs.pitch`) is added directly to both front motors without tilt-angle scaling:

```cpp
float base_thrust = throttle_thrust + inputs.pitch;
outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = base_thrust + scaled_roll;
outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = base_thrust - scaled_roll;
```

- `inputs.pitch > 0` (nose up): front motors increase → more upward force at front → nose up ✓
- No `cos(tilt_deg)` scaling — the front motors are thrust-vectored, so the TVC brain adapts the tilt angle in response to the resulting attitude change. The pitch PID and TVC operate on orthogonal actuators (thrust magnitude vs. thrust direction) and converge to equilibrium independently.

**Why not scale by `cos(tilt_deg)`**: Scaling would suppress pitch authority as wings rotate horizontal. Instead, as tilt increases the TVC naturally adjusts thrust direction, and the pitch PID finds a new equilibrium. The tilt angle becomes a function of pitch demand rather than pitch demand being constrained by tilt angle.

**Contrast with blimp**: The BlimpMixer deliberately omits pitch from the front motors. The blimp has high rotational inertia and oscillates at a very low frequency, making active pitch mixing destabilising. The Avatar's lighter, stiffer airframe does not have this problem.

### 4.8 Roll Thrust Headroom

Differential roll thrust is pre-scaled to the available motor headroom before being applied, preventing asymmetric clipping. Headroom is computed around the pitch-shifted base so that pitch corrections don't steal roll authority asymmetrically:

```cpp
float base_thrust = throttle_thrust + inputs.pitch;
float roll_headroom = fminf(1.0f - base_thrust, base_thrust);
float scaled_roll = constrain_float(inputs.roll * roll_effectiveness, -roll_headroom, roll_headroom);
```

At full throttle: headroom = 0 → roll authority gracefully zeroed, thrust preserved.
At hover (0.5, pitch=0): headroom = 0.5 → full roll available.

Without this, naive clipping would produce asymmetric motor outputs causing simultaneous thrust loss and unintended yaw.

### 4.9 Rear Motor Mixing

The rear motor acts as a tricopter-style tail motor — mixing throttle and pitch — scaled by the wing tilt position so it contributes nothing when wings are horizontal and full contribution at hover.

**Copter mode:**
```cpp
rear = (throttle_thrust - inputs.pitch) * cosf(radians(state.current_tilt_deg))
```
- `inputs.pitch > 0` (nose up): rear motor decreases → tail drops → nose up ✓
- `cos(0°) = 1` at hover: full authority
- `cos(90°) = 0` in forward flight: rear motor off

**Why `cos(tilt_deg)` here but not on the front motors**: The rear motor has no thrust vectoring — its thrust direction is fixed. As the aircraft transitions to forward flight the rear motor becomes geometrically misaligned with the pitch axis, so its contribution is explicitly faded out. The front motors are thrust-vectored and self-correct via the TVC.

**Plane mode:**
```cpp
rear = (throttle_pct - pitch_in) * tilt_delta
```
- Zero when wings are horizontal (`tilt_delta = 0`)
- Scales up only as stall-prevention tilt engages
- Same sign convention: pitch-up demand reduces rear motor thrust

Output is clamped to `[0, 1]` — rear motor is non-reversible.

### 4.8 Rear Motor Activation (Production Design)

The rear motor has two components:

1. **Base thrust**: Proportional to `sin(wing_angle_rad)`. At 0° (wings horizontal), rear motor contributes nothing to lift. At 90° (wings vertical), rear motor is at full base lift.
2. **Pitch delta**: The ArduPilot yaw command is mixed in for directional authority at low speeds.

```
rear_motor_thrust = base_lift * sin(wing_angle) ± pitch_input
```

The `sin` scaling is physically motivated: as the wing motors tilt away from vertical, the rear motor progressively compensates for the reduced vertical component.

---

## 5. Configuration System

### 5.1 Switching to Avatar

Change one line in `libraries/AP_CustomConfig/AP_CustomConfig.h`:

```cpp
#define ACTIVE_CONFIG CONFIG_TYPE_AVATAR  // was CONFIG_TYPE_BLIMP
```

This switches `g_config` to `avatarConfig`, selects `AvatarMixer` in `AP_Motors6DOF::init()`, and changes the preprocessor defines (`EMERGENCY_BLIMP_MANUAL_MODE = false`, etc.).

### 5.2 Weathervaning

Avatar uses two distinct weathervaning mechanisms depending on mode.

**QLOITER — active weathervaning via AC_WeatherVane:**
ArduPlane's stock `AC_WeatherVane` library handles this — no custom code required. The position controller's roll lean demand (the aircraft tilts to hold position against wind drift) is used as the wind-direction signal. Activates 2 seconds after entering QLOITER with no rudder input; deactivates immediately on pilot yaw input.

*   `Q_WVANE_ENABLE`: **1** (Nose into wind)
*   `Q_WVANE_GAIN`: **1.0** (Start here; increase for more aggressive response)
*   `Q_WVANE_ANG_MIN`: **1.0** (Deadzone in degrees; prevents hunting when nearly aligned)

**STABILIZE and QSTABILIZE — passive weathervaning via I-term release:**
In these modes there is no position controller, so the lean-based wind signal is unavailable. Instead, when the pilot has no rudder input, the yaw rate PID I-term is reset to zero each control loop. P and D continue running for yaw damping, but the I-term cannot accumulate to resist sustained aerodynamic yaw rotation. Avatar's fixed-wing fuselage has a natural weathercock stability moment; releasing the I-term allows this moment to slowly rotate the nose into the wind without active wind estimation or GPS. See `[AV-INVAR:passive-weathervane]`.

This behaviour is gated by `g_config.custom_weathervane = true` (set in `avatarConfig`). It does not apply to QLOITER (which has active weathervaning) or CRUISE (which aerodynamically self-weathervanes via the vertical tail).

### 5.3 Avatar Config Values (`AP_CustomConfig.cpp`)

| Field | Value | Rationale |
|-------|-------|-----------|
| `tricopter_is_blimp` | false | Selects AvatarMixer |
| `forward_flight_physical_angle_deg` | 90.0° | Wings horizontal = max forward |
| `reverse_flight_physical_angle_deg` | -15.0° | 15° past vertical for braking |
| `platform_max_angle_deg` | 90.0° | Full tilt range |
| `mot_spin_neutral` | 1000 | Non-reversible motors |
| `diff_yaw_enabled` | 1 | Differential yaw (for rear motor) |
| `lifting_motors_reversible` | false | Wing motors are unidirectional |
| `emergency_blimp_manual_mode` | false | Blimp-specific feature, not needed |
| `optical_flow_stabilized_roll/pitch` | false | Not applicable |

---

## 6. Implementation Status

### 6.1 Already Working (Reused from Blimp)
- `tvc_run_main_logic` — full TVC brain with pitch compensation, gain scheduling, VTOL blending
- `AP_CustomConfig` selector pattern — flip one `#define` to switch vehicles
- `AP_Motors6DOF` backend — mixer dispatch, output routing, spool state handling
- `MixerInputs` / `MixerOutputs` / `MixerState` data contracts

### 4.10 Surface Control Architecture (Copter Mode)

Control surfaces (ailerons, V-tail) in QSTABILIZE receive pilot stick input directly — not the rate PID feed-forward component. This is because `_roll_in_ff` / `_yaw_in_ff` are proportional to `Q_A_RAT_*_FF` gains, which are zero by default, giving no surface authority.

The fix adds explicit setters `set_pilot_roll()`, `set_pilot_pitch()`, `set_pilot_yaw()` to `AP_Motors_Class`, called from `ModeQStabilize::update()` behind `#if ENABLE_TRICOPTER_VTOL_BACKEND`. The normalized stick values (-1..1) feed directly into `mixer_in.surface_roll / surface_pitch / surface_yaw`.

**These are the only callers of `set_pilot_*`.** In QHOVER, QLOITER, FBWA, and all other modes, the setters are never called and `surface_roll/pitch/yaw` remains zero. Surface authority in those modes comes entirely from the copter PID outputs (`inputs.roll`, `inputs.yaw`) — not direct stick passthrough.

`AP_Motors6DOF.cpp` uses:
```cpp
mixer_in.surface_roll  = _pilot_roll;
mixer_in.surface_yaw   = _pilot_yaw;
mixer_in.surface_pitch = _pilot_pitch;
```

**For plane mode (future):** Call the same setters with ArduPlane's computed aileron/rudder outputs from the relevant fixed-wing mode. The interface is ready.

**Motors vs surfaces:** Motors use the closed-loop PID inputs (`_roll_in + _roll_in_ff`) for stability. Surfaces use direct pilot intent for authority. These are intentionally separate paths.

---

## 6. Implementation Status

### 6.1 Already Working (Reused from Blimp)
- `tvc_run_main_logic` — full TVC brain with pitch compensation, gain scheduling, VTOL blending
- `AP_CustomConfig` selector pattern — flip one `#define` to switch vehicles
- `AP_Motors6DOF` backend — mixer dispatch, output routing, spool state handling
- `MixerInputs` / `MixerOutputs` / `MixerState` data contracts

### 6.2 Implemented and Bench-Verified (Zoh Altus VTOL, June 2026)

**`AvatarMixer::setup_motors()`** — 4 motors: left wing, right wing, right rear yaw, left rear yaw.

**`AvatarMixer::mix()` — Copter mode:**
- TVC brain (`tvc_run_main_logic`) — same as blimp, full pitch compensation and stall prevention
- Both wing motors get equal throttle from TVC output plus differential roll
- Differential roll via `cos(tilt_deg)` scaling on motor differential
- Ailerons use `surface_roll` (pilot stick directly, not `sin_tilt` scaled)
- Elevator uses `cos_tilt` trim schedule
- Rudder uses `surface_yaw` (pilot stick directly)
- Dual rear motors get differential yaw: `YAW_LEFT = rear - yaw_delta`, `YAW_RIGHT = rear + yaw_delta` where `yaw_delta = inputs.yaw * cos_tilt`

**`AvatarMixer::mix()` — Plane mode:**
- Direct tilt control via pilot pitch stick; elevator is driven by ArduPlane's fixed-wing pitch PID (see section 4.4)
- V-tail mixing computed in mixer output stage

**Surface control:** Pilot stick fed via `set_pilot_roll/pitch/yaw` setters from `ModeQStabilize::update()` (see section 4.10).

**Motor count fix** — `wantMotors` is 4 for Avatar, 3 for blimp.

**Forward input normalization** — `AVATAR_FORWARD_INPUT_MAX = 0.42f`. `Q_ANGLE_MAX = 30°` caps pilot pitch demand so `_forward_in` never reaches 1.0 at full stick. Dividing by 0.42 re-normalises full stick to 1.0 for the TVC.

**Throttle channel encoding** — Avatar maps throttle to `1500..2000` (positive half only), not the full `1000..2000` range. TVC_Core always decodes THRUST_CHANNEL with `sbus_pwm_to_float(..., -1.0f, 1.0f)`, so 1500 → 0.0 and 2000 → 1.0. Using the full range would make zero stick (1000 PWM) look like full reverse thrust to the TVC's `sqrtf` magnitude calculation, producing `total_throttle = 1.0` at both extremes and incorrect tilt angles. Blimp uses the full range because its motors are genuinely bidirectional. This asymmetry is intentional and was validated during testing.

### 6.3 Not Required for Zoh Altus VTOL Test
- Rear motor `sin(wing_angle)` formula — rear motor absent on test airframe
- Spring-lever yaw mechanism — not present on Zoh Altus VTOL

---

## 7. Test Plan (Zoh Altus VTOL)

### 7.1 Servo Output Assignments (Zoh Altus VTOL — 8 outputs)

**Zoh Altus VTOL connector labels:**
- `Aux` — tilt servo for the rotating wing motors
- `Servo` — ailerons

| Pin | Physical connection | ArduPilot function | Param | Mixer output |
|-----|--------------------|--------------------|-------|--------------|
| 1 | Left wing motor ESC | Motor 1 | `SERVO1_FUNCTION = 33` | — |
| 2 | Left rear yaw motor ESC | Motor 4 | `SERVO2_FUNCTION = 36` | — |
| 3 | Right rear yaw motor ESC | Motor 3 | `SERVO3_FUNCTION = 35` | — |
| 4 | Right wing motor ESC | Motor 2 | `SERVO4_FUNCTION = 34` | — |
| 5 | Wing tilt servo | Scripting2 | `SERVO5_FUNCTION = 95` | `tilt_angle` |
| 6 | Aileron left | Scripting3 | `SERVO6_FUNCTION = 96` | `aileron_out` |
| 7 | Aileron right | Scripting4 | `SERVO7_FUNCTION = 97` | `-aileron_out` |
| 8 | V-tail left | Scripting5 | `SERVO8_FUNCTION = 98` | `elevator_out + rudder_out` |
| 9 | V-tail right | Scripting6 | `SERVO9_FUNCTION = 99` | `elevator_out - rudder_out` |

**Confirmed servo reversals (Zoh Altus VTOL):**

| Parameter | Value | Reason |
|-----------|-------|--------|
| `SERVO5_REVERSED` | 1 | Tilt servo physical orientation |
| `SERVO7_REVERSED` | 1 | Right elevon servo is factory-reversed |
| `SERVO9_REVERSED` | 1 | Right V-tail servo physical orientation |

**Tilt servo calibration (SERVO5, MicoAir H743 + Zoh Altus VTOL):**

The tilt servo uses `set_output_norm` via the Scripting2 channel, which uses `pwm_from_angle` (asymmetric TRIM-based mapping). With `SERVO5_REVERSED = 1`:

| `tilt_angle` | Servo position | PWM |
|---|---|---|
| `0.0` | Wings vertical (hover) | TRIM = **1827** |
| `+1.0` | Wings horizontal (forward) | MIN = **811** |
| `-1.0` | 15° past vertical (braking) | MAX = **2025** |

`reverse_flight_physical_angle_deg = -15.0f` in `avatarConfig`. `SERVO5_MAX = 2025` calibrated to the physical braking limit. Parameters:
```
SERVO5_MIN  = 811
SERVO5_TRIM = 1827
SERVO5_MAX  = 2025
Q_TILT_RATE_UP = <measured>   (physical slew rate of tilt mechanism in deg/s — see [AV-INVAR:tilt-servo-tracking])
```

`Q_TILT_RATE_UP` is **not a tuning knob** — it must equal the measured physical slew rate of the tilt mechanism (wings vertical to horizontal). Calibrate: command a full-range tilt and time it, then set `Q_TILT_RATE_UP = 90 / seconds`. The 90° avatar range means this value will be proportionally higher than the blimp's equivalent.

**All surface outputs use Scripting channels** (Scripting2–6). This is deliberate — ArduPlane's own mixing pipeline (`stabilize_roll`, `stabilize_pitch`, elevon mixer, vtail mixer) runs in QSTABILIZE and writes to named channels like `k_aileron` and `k_vtail_left`. Using Scripting channels fully isolates our outputs from ArduPlane's mixer. Never assign these servos to `k_aileron`, `k_elevator`, `k_rudder`, `k_vtail_left`, or `k_vtail_right`.

The aileron surfaces (Scripting3/4) carry pure differential roll — no elevator component. The V-tail surfaces (Scripting5/6) carry elevator and rudder authority. Both are computed in `AP_Motors6DOF::output_to_motors()` in `libraries/AP_Motors/AP_Motors6DOF.cpp`.

### 7.2 ArduPilot Configuration
Configure the Zoh Altus VTOL as a **QuadPlane**. This is primarily to access copter (Q) modes for testing the mixer logic. The production intent is that plane mode works at all times, but copter mode provides a controlled environment to validate motor mixing before full-plane testing.

### 7.2 Base Test Case: Copter Mode Forward Flight
1. Arm in a Q-mode (e.g., QHOVER or QSTABILIZE)
2. Apply throttle to hover near ground
3. Apply forward stick — observe wings tilt slightly forward
4. Aircraft should move forward slowly while ArduPilot maintains altitude
5. Release forward stick — wings return to vertical, aircraft decelerates

This validates the core 6DOF thrust-vector concept without relying on aerodynamics.

### 7.3 Stall Prevention Validation (Later)
1. Transition to plane mode
2. Fly at progressively lower airspeeds
3. Observe that as elevator saturates, wings tilt upward automatically
4. Confirm aircraft recovers rather than stalling

**Bench-verified (Zoh Altus VTOL, June 2026):**
- Roll authority via differential wing motor thrust ✓
- Yaw authority via dual rear motor differential + V-tail rudder ✓
- Aileron mixing (elevons) responds correctly to roll stick ✓
- V-tail mixing responds correctly to yaw stick ✓
- Tilt servo sweeps correctly from vertical (1827) to horizontal (811) ✓
- Elevator `cos_tilt` schedule verified direction correct ✓

**Remaining unknowns:**
- Plane-mode stall-prevention loop stability is theoretically sound but untested — behavior at the transition boundary is the highest-uncertainty element of the design
- ArduPlane PID gain tuning for the elevated elevator gain from `elevator_tilt_handoff_point = 0.5` (effective 2× gain in elevator-only zone)

---

## 8. Production Aircraft Design

The Zoh Altus VTOL is a test platform to validate the Avatar control architecture. The production aircraft is a purpose-built design derived from the lessons of the Zoh Altus program. This section captures the production design intent for future implementation.

### 8.1 Mission Profile

Advertising aircraft optimized for low-speed stable flight with variable payload between missions. The primary design constraint is sustained, stable low-speed flight rather than cruise efficiency or high-speed performance. Flight envelope not yet formally established.

### 8.2 Wing Geometry — Low Aspect Ratio

The production aircraft uses a **low aspect ratio wing**, explicitly rejecting high aspect ratio. Rationale:

- **Stability is electronic, not aerodynamic.** The flight controller provides stabilization at rates far exceeding any passive aerodynamic restoring force. High AR exists primarily to provide passive stability and slow landing speeds — both of which are provided by other means in this design.
- **Tip stall in turns.** High AR wings generate a large differential in lift across the span during turning flight — the outer wing moves faster, the inner wing slows toward stall. Low AR minimises this differential, allowing tighter turns at lower speeds without asymmetric tip stall.
- **Thrust vectors provide low-speed authority.** The slow landing speed benefit of high AR is redundant when the motor tilt system provides lift and control authority at zero airspeed.
- **Reverse stall risk.** On a high AR wing, aileron deflection can pop a pre-loaded wingtip out of stall, creating a violent asymmetric lift event that rolls the aircraft opposite to command — exactly the failure mode observed on the T1 Ranger before the elevon mixing was removed.

Low AR allows the aircraft to turn tighter and fly slower without stall, with the flight controller handling stability electronically.

### 8.3 Motor Placement — Forward and Below the Wings

Motors are mounted **forward of and below the wings** on a separate tilting mechanism. They are not fixed to the wing and not at the wingtips. Two considerations drove this:

**Not at wingtips (V-22 Osprey lesson):** Tilting rotors at the wingtips disturb the wing's pressure differential as the rotor wash angle changes through the transition. This creates unpredictable asymmetric lift conditions — the primary cause of the V-22 Osprey's unsafe handling qualities. An ideal aircraft maintains a consistent high pressure differential along the wing at all times, independent of what the motors are doing.

**Forward and below:** This placement keeps motor wake clear of the wing's lifting surface throughout the tilt range. The separate mounting structure means the wing's aerodynamic environment is decoupled from the motor tilt angle.

### 8.4 Independent Wing and Motor Rotation

Wings and motors rotate on **separate independent axes**. This is the central architectural difference from the T1 Ranger, where motors are fixed to the wings and rotate 1:1.

**Why not 1:1:** The wing and the motors have different optimal angles at every point in the transition. Forcing them to move together makes both suboptimal simultaneously. The wing wants to maintain its best lift-generating angle of attack relative to oncoming airflow. The motors want to vector thrust to balance lift and forward propulsion. These are different functions of airspeed.

**The mixing function:** The two axes are coupled by a mixing curve, not a fixed ratio. They converge at both endpoints — both ~90° (vertical) in hover, both ~0° (horizontal) in cruise — but follow different paths through the transition:

- **Motor angle schedule** is driven by the instantaneous thrust budget:
  ```
  motor_angle = atan2(drag, weight - aerodynamic_lift)
  ```
  As airspeed builds, aerodynamic lift increases with V² and vertical thrust requirement drops rapidly. The motor tilts toward horizontal fast. This is the same computation the TVC brain already performs via `atan2(forward_cmd, thrust_cmd)`.

- **Wing angle schedule** is driven by the wing's aerodynamic polar — the wing tracks its optimal angle of attack relative to the oncoming airflow. This is a slow, gentle function of airspeed compared to the motor schedule.

**The motor leads the wing through transition.** At any intermediate airspeed the motor is tilted further toward horizontal than the wing. They reconverge at cruise.

**Deriving the mixing curve in practice:**
1. Characterise the wing's polar (CL vs AoA), identify the optimal operating AoA
2. Compute aerodynamic lift at each airspeed: `L = ½ρV²S·CL`
3. Motor angle schedule: `atan2(drag(V), weight - L(V))`
4. Wing angle schedule: `optimal_AoA + flight_path_angle(V)`
5. Both curves plotted against airspeed yield the mixing function — two independent lookup tables, one per axis, with airspeed as the common input

### 8.5 Multi-Stage Flap System

Wing rotation is achieved through **compound flaps — a flap on a flap** — rather than a single rotating wing spar. Each stage contributes a portion of the total angle change. This distributes mechanical forces across multiple hinge points rather than concentrating them at a single axis, and keeps each stage operating within its aerodynamically valid deflection range.

**Hinge placement:** The ratio between hinge positions across stages is derived from the wing's airfoil geometry. The goal is to maintain attached flow and preserve pressure differential at every deflection stage. The exact placement is therefore airfoil-dependent and must be computed once the production airfoil is selected.

**Airfoil selection:** The airfoil is optimised for low-speed performance consistent with the advertising mission profile. The multi-stage flap geometry is then derived from that airfoil's polar rather than the other way around.

### 8.6 Variable Payload Handling

Payload varies between missions. This affects the mixing curve asymmetrically:

- **Wing angle schedule is fixed** — it is a function of airfoil geometry and aerodynamics, independent of weight.
- **Motor angle schedule is weight-dependent** — heavier payload increases vertical thrust requirement at every airspeed, shifting the motor angle curve upward (motors stay more vertical for longer before tilting forward).

The flight controller must therefore be weight-aware to execute the correct motor schedule. This can be achieved via explicit payload weight input before flight or via in-flight weight estimation from the relationship between throttle and observed climb/sink rate.

---

## 9. Design Invariants

These are non-obvious decisions that look wrong without context and are therefore the most likely to be "fixed" incorrectly during future development or flight-test iteration. Each carries a tag of the form `[AV-INVAR:<slug>]`. Search that exact string across both the codebase and this document to find every location where the invariant is enforced.

---

### [AV-INVAR:cos-tilt-i-zero]

**What:** The copter attitude rate PID I-terms (pitch and roll) are scaled toward zero as the wings approach horizontal in FBWA plane mode. At ≤45° tilt (toward vertical, hover) I runs freely. At ≥90° (horizontal, cruise) I is zeroed. Between 45° and 90° the integrator is multiplied by a linear scale factor each loop, decaying it smoothly toward zero.

**Where:** `ArduPlane/quadplane.cpp` — Avatar FBWA block (`ENABLE_TRICOPTER_VTOL_BACKEND && !tricopter_is_blimp`). `i_scale = constrain_float(1.0f - (tilt_deg - 45.0f) / 45.0f, 0.0f, 1.0f)` applied to `get_rate_pitch_pid()` and `get_rate_roll_pid()`. Convention: `tilt_deg = 0°` is wings vertical (hover), `tilt_deg = 90°` is wings horizontal (cruise).

**Why:** The mixer multiplies copter PID outputs by `cos_tilt_b` before sending them to the rear motor and wing motor differential. When `cos_tilt_b = 0` (wings horizontal), motor outputs are silently gated to zero downstream of the PID. The PID does not know this — it sees a rate error and winds its I-term trying to achieve the commanded rate. When `cos_tilt_b` becomes non-zero again (wings tilt back toward vertical), the wound-up I-term fires a sudden pulse through the motors. The `outputs.limit.pitch` anti-windup flag does not cover this case because it only fires when motor demand exceeds `[0, 1]`, not when gated to zero by `cos_tilt_b`. Allowing I to accumulate freely in hover (≤45°) provides steady-state correction for CG offset, motor imbalance, and crosswind. Decaying it proportionally through the transition prevents the windup-then-sudden-activation failure mode.

**Do not switch to unconditional I accumulation** without also adding a cos_tilt-aware anti-windup path. The `outputs.limit` flags are insufficient alone because they do not gate on `cos_tilt_b`.

---

### [AV-INVAR:surface-i-decay-tilt45]

**What:** The fixed-wing surface controllers (roll, pitch, yaw) have their I-terms decayed via `decay_I()` when `tilt_deg < 45°`.

**Where:** `ArduPlane/Attitude.cpp` — Avatar-specific block replacing the standard airspeed-threshold I-decay.

**Why:** The standard ArduPlane code decays surface I-terms when airspeed drops below `ARSPD_FBW_MIN * 0.5`. Avatar sets `ARSPD_FBW_MIN = 0` (zero-stall-speed aircraft), making that threshold permanently zero — the block never fires. The 45° tilt angle is used as a proxy: when the rotors are more than halfway toward vertical, airspeed is typically near zero and the control surfaces are aerodynamically ineffective. Allowing I-terms to accumulate when surfaces produce no force would cause a windup spike when the aircraft transitions back to forward flight. Same category of problem as `[AV-INVAR:cos-tilt-i-zero]`, different controller.

**The 45° threshold is a proxy, not a physical constant.** The real condition is "surfaces are aerodynamically ineffective." If the aircraft gains meaningful airspeed at tilt angles below 45° during flight testing, this threshold may need adjustment.

---

### [AV-INVAR:ang-vel-pitch-bypass]

**What:** In FBWA plane mode, `_ang_vel_body.y` (pitch rate target) is written directly via `rate_bf_pitch_target()` rather than going through the angle controller (`attitude_controller_run_quat()`).

**Where:** `ArduPlane/quadplane.cpp` — Avatar FBWA block. `AC_AttitudeControl/AC_AttitudeControl.h` — `rate_bf_pitch_target()` setter.

**Why:** The angle controller maintains an `_attitude_target` quaternion that slews toward the commanded angle. In a prior FBWA transition with full pitch-up stick, `_attitude_target` can be set to `nav_pitch_cd ≈ 90°`. Even after commanding 0°, `_attitude_target` slews back slowly — `_ang_vel_body.y` (the rate target fed to the rate PID) remains large and positive for many seconds, producing wrong-sign `inputs.pitch`. Writing directly to `_ang_vel_body.y` bypasses the slewing `_attitude_target` entirely, producing a clean `att_kP × (0° − actual_pitch)` signal every loop. See § 4.4.1 for full diagnosis.

---

### [AV-INVAR:ang-vel-roll-tracking]

**What:** In plane modes, `_ang_vel_body.x` (roll rate target) is written directly via `rate_bf_roll_target()`, targeting a commanded bank angle rather than always targeting 0°. In FBWA/auto that source is `nav_roll_cd`; in STABILIZE it is the pilot stick directly — see `[AV-INVAR:stabilize-roll-from-stick]`.

**Where:** `ArduPlane/quadplane.cpp` — Avatar FBWA block. `AC_AttitudeControl/AC_AttitudeControl.h` — `rate_bf_roll_target()` setter.

**Why:** Without an explicit roll rate target, `_ang_vel_body.x` is stale from the last copter mode operation. The roll rate PID then fires on a meaningless target, producing noise in `inputs.roll` which the mixer applies to the wing motor differential. By targeting the commanded bank angle, the copter roll controller and the ArduPlane roll PID (ailerons) cooperate — both command the same bank. The `cos_tilt_b` scaling in the mixer fades motor roll authority to zero at wings-horizontal, so there is no fighting in cruise regardless.

**Targeting the commanded bank angle not `0°` is load-bearing.** If changed to always target 0°, the copter roll controller will fight any bank angle commanded by ArduPlane's roll PID during intermediate tilt angles.

---

### [AV-INVAR:tilt-follows-nav-pitch]

**What:** In plane modes, `pitch_tilt_demand` is derived from `nav_pitch_cd` (normalised by `pitch_limit_max`), not from the raw pilot pitch stick.

**Where:** `ArduPlane/quadplane.cpp` — PlaneInputs injection block (`ENABLE_TRICOPTER_VTOL_BACKEND`). `plane_inputs.pitch_tilt_demand = nav_pitch_cd / (pitch_limit_max * 100)`.

**Why:** `nav_pitch_cd` captures both pilot intent (FBWA stick → pitch demand) and any autonomous system modifications (TECS stall recovery, navigation). Routing it to tilt means the wings tilt toward vertical when energy management demands more lift — the Avatar equivalent of a conventional aircraft pitching up. The elevator does NOT receive `nav_pitch_cd`; it is driven by `[AV-INVAR:elevator-follows-pitch-pid]` instead. The ArduPlane pitch PID still runs and computes `elevator_input`, but that output is ignored by the mixer.

**Do not revert to `channel_pitch->norm_input()`** — that discards TECS's autonomous pitch demand and breaks stall prevention in plane mode. Exception: STABILIZE mode, where `nav_pitch_cd` is always 0 — see `[AV-INVAR:stabilize-pitch-decoupled]`.

---

### [AV-INVAR:elevator-follows-pitch-pid]

**What:** In all plane modes (FBWA, STABILIZE, …), `elevator_out` is driven by `inputs.pitch` (the copter attitude controller PID output), not by `inputs.plane.elevator_input` (the ArduPlane pitch PID output). In STABILIZE the elevator stick mixing that would otherwise override this is also suppressed — see `[AV-INVAR:stabilize-pitch-decoupled]`.

**Where:** `ArduPlane/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp` — plane mode block. `outputs.elevator_out = inputs.pitch`.

**Why:** The elevator's job is to hold the fuselage level — the same job as the rear motor. `inputs.pitch` is generated by the copter attitude controller targeting `0° - actual_pitch` (see `[AV-INVAR:ang-vel-pitch-bypass]`). Using the same signal for both the elevator and the rear motor means both actuators cooperate on the same error signal. `inputs.plane.elevator_input` (ArduPlane pitch PID) is discarded because that PID targets `nav_pitch_cd`, which now drives tilt angle (see `[AV-INVAR:tilt-follows-nav-pitch]`) — if `elevator_input` were used, the elevator would try to pitch the nose to match the tilt demand, which is wrong.

**Gain note:** `inputs.pitch` is scaled as a motor thrust fraction (typically ±0.2 for moderate errors). This may produce smaller elevator deflections than the ArduPlane PID did. Tune with a gain multiplier if elevator authority is insufficient in flight.

---

### [AV-INVAR:stabilize-pitch-decoupled]

**What:** In STABILIZE mode, (a) `pitch_tilt_demand` is sourced from the pilot stick (`channel_pitch->norm_input_dz()`) rather than `nav_pitch_cd`, and (b) the elevator stick mixing in `stabilize_stick_mixing_direct()` is suppressed. The result is identical pitch architecture to FBWA: pilot pitch drives TVC tilt only, elevator holds level via the copter attitude PID.

**Where:** Two locations:
1. `ArduPlane/quadplane.cpp` — PlaneInputs injection block: STABILIZE branch uses `norm_input_dz()` instead of `nav_pitch_cd / pitch_limit_max`.
2. `ArduPlane/Attitude.cpp` — `ModeStabilize::stabilize_stick_mixing_direct()`: the elevator pitch mixing block is compiled out under `#if !(ENABLE_TRICOPTER_VTOL_BACKEND && ACTIVE_CONFIG == CONFIG_TYPE_AVATAR)`.

**Why:** STABILIZE always resets `nav_pitch_cd = 0` each loop (it holds current attitude and applies pilot stick directly to servo outputs via `stabilize_stick_mixing_direct()`). That means `[AV-INVAR:tilt-follows-nav-pitch]`'s `nav_pitch_cd` path always produces `pitch_tilt_demand = 0` in STABILIZE — the TVC would never move. `norm_input_dz()` carries the correct sign (positive = nose-up = more vertical tilt) and the same [-1, 1] range as `nav_pitch_cd / pitch_limit_max` at full stick in FBWA.

The elevator mixing suppression is required because `stabilize_stick_mixing_direct()` would otherwise add pilot pitch on top of the copter attitude PID elevator output — fighting the level-hold. Without suppression, STABILIZE would have partial pilot pitch authority on the elevator, which is wrong for Avatar (pilot pitch goes to TVC only).

**Do not remove the elevator mixing guard** without also providing an alternative pitch authority path — STABILIZE without direct elevator mixing relies entirely on TVC for pilot pitch input.

---

### [AV-INVAR:stabilize-tilt-rate-control]

**What:** In STABILIZE mode, `pitch_tilt_demand` is interpreted as a *rate command* rather than a position target. Neutral stick holds the current tilt angle; full stick deflection moves the servo at `Q_TILT_RATE_UP` (the physical servo speed). `Q_TILT_RATE_DN` is ignored — the pilot decides the downward rate.

**Where:** `AP_Motors6DOF_AvatarMixer.cpp` — plane mode tilt block, `tilt_rate_mode` branch. Enabled via `PlaneInputs::tilt_rate_mode = true`, set in `ArduPlane/quadplane.cpp` when `control_mode == mode_stabilize`.

**Why:** Position control (FBWA) snaps the tilt angle to a value proportional to stick position — releasing the stick always commands a fixed angle. This is wrong for a VTOL aircraft where the pilot wants to park the rotors at an arbitrary angle and hold it there. Rate control lets the pilot adjust tilt incrementally and release to freeze it. `Q_TILT_RATE_UP` is the correct rate ceiling because it is calibrated to the physical servo speed — 100% stick = maximum the servo can physically move. `Q_TILT_RATE_DN` was chosen to pace the hover→cruise airspeed transition in FBWA and has no meaning here.

**Sign convention:** positive `pitch_tilt_demand` = toward vertical = decreases `state.pilot_tilt_deg` (0° = vertical, 90° = horizontal). This matches the sign convention of `[AV-INVAR:tilt-follows-nav-pitch]`.

**`pilot_tilt_deg` sync — BOTH other branches keep it pinned to the physical tilt** (added July 2026): the copter branch and the plane *position* branch (CRUISE/AUTO/FBWA) each set `state.pilot_tilt_deg = state.current_tilt_deg` every frame. Rate mode therefore always starts from the current position on entry into STABILIZE, from any mode. Before the position-branch sync existed, CRUISE→STABILIZE slewed toward a stale `pilot_tilt_deg` (typically near-vertical from the last Q-mode session) at `Q_TILT_RATE_UP` = 225°/s — rotors slammed vertical at cruise speed. Covered by `position_mode_syncs_pilot_tilt_for_rate_mode_entry` in Group P of `tests/mixer_test`. A companion fix snapshots `_vel_hold_target` on STABILIZE entry (`_vel_damp_entry_snap_pending`, quadplane.cpp/h) so the vel-damp never acts on a stale hold target either — see `[AV-INVAR:vel-damp]`.

**Unified slew (critical):** The `tilt_rate_mode` branch computes a single combined tilt target each frame and issues ONE rate-limited slew of `state.current_tilt_deg` toward it:
- No dampening active: target = `state.pilot_tilt_deg` → classic rate-control behaviour.
- Dampening active (`[AV-INVAR:sink-damp]`, `[AV-INVAR:long-damp]`, or `[AV-INVAR:vel-damp]`): target = `new_tilt_deg` from the force-vector decomposition, which is `pilot_tilt_deg` modified by the damping demand.

**Do NOT split this into two separate rate-limited moves** (e.g., tilt-rate-control slewing toward `pilot_tilt_deg` followed by a dampening block slewing toward `new_tilt_deg`). If both use the same rate limit in opposite directions they cancel exactly every frame — the net result is that `current_tilt_deg` never moves more than one rate-step from `pilot_tilt_deg` regardless of how large the dampening demand is. This was the root cause of the vertical and longitudinal dampening appearing to have no effect in flight logs (DampThrust was nonzero, CurrTilt tracked PilotTilt). The unit tests in `GROUP K` of `tests/mixer_test/test_main.cpp` prove this invariant.

**Servo limits:** `state.current_tilt_deg` is clamped to `[reverse_flight_physical_angle_deg, forward_flight_physical_angle_deg]`. The tilt slew is bidirectional — longitudinal dampening can command a target more forward than `pilot_tilt_deg` as well as more vertical.

---

### [AV-INVAR:stabilize-roll-from-stick]

**What:** In STABILIZE mode, the copter roll PID targets `channel_roll->norm_input_dz() * roll_limit_cd` (pilot stick as a bank angle command) rather than `nav_roll_cd` (which is always 0 in STABILIZE). This gives the wing motors roll authority that tracks the pilot's stick, matching FBWA motor behaviour.

**Where:** `ArduPlane/quadplane.cpp` — Avatar FBWA block, `roll_target_rad` computation. Conditional on `control_mode == &mode_stabilize`.

**Why:** STABILIZE always resets `nav_roll_cd = 0` each loop. Without this fix, `roll_error_rad = (0 - actual_roll)` — the motors fight any bank angle rather than following the pilot. The aileron surface does receive pilot roll via `stabilize_stick_mixing_direct()`, so without this fix the surface and motors work against each other during a banked input. Using `norm_input_dz() * roll_limit_cd` maps full stick to the same maximum bank angle that FBWA would command, keeping gains consistent between modes.

**Do not use a rate command here** (unlike `[AV-INVAR:stabilize-tilt-rate-control]`). Roll is an angle-tracked axis — the copter attitude PID expects a bank angle target, not a rate. Feeding a rate would require integrating stick input externally and bypasses the PID's integral wind-up protection.

---

### [AV-INVAR:stabilize-yaw-pid]

**What:** In all nav plane modes (STABILIZE, CRUISE, AUTO, RTL, …), the pilot's rudder stick is converted to a yaw rate demand (via `get_pilot_input_yaw_rate_cds()`, which applies expo and `Q_YAW_RATE_MAX` scaling) and written to the copter attitude controller via `rate_bf_yaw_target()`. The mixer plane branch then uses `inputs.yaw` (the PID output) for motor differential and rudder surface — identical to the copter mode path. Manual-family modes (MANUAL/ACRO/TRAINING) are excluded (`use_pid_yaw = false`): they never run the rate-target block, so the PID output would be stale, and raw rudder passthrough is their correct semantic.

*Scope history:* originally STABILIZE-only; extended to all nav plane modes July 2026 so CRUISE climbs (rotors near vertical, rudder aerodynamically dead) get the same disturbance-yaw cancellation — front-wing-motor thrust imbalance yaw (log 00000072.BIN mechanism) is otherwise uncorrected outside STABILIZE. The theoretical cost — the PID damping coordinated-turn yaw rates in banked forward flight — was already present on the rudder surface in validated STABILIZE forward flight and proved benign (acts as a yaw damper); the stick-centered I-reset (`[AV-INVAR:passive-weathervane]`) keeps it P/D-only in hands-off nav turns. If CRUISE logs ever show L1 tracking degraded by skidding turns, the fix is a coordinated-turn feedforward on the yaw rate target (`g·tan(roll)/ground_speed`), not a revert.

**Where:** Two locations:
1. `ArduPlane/quadplane.cpp` — Avatar FBWA block, after `rate_bf_roll_target()`.
2. `libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp` — plane branch, `yaw_delta_b` and `rudder_out` assignment.

**Why:** The original plane branch used `rudder_input / 4500` (raw stick, open-loop). This gave noticeably weaker and inconsistent yaw authority compared to copter mode because there was no PID stabilization, no I-term heading hold when stick is centered, and no expo. Routing through `rate_bf_yaw_target()` gives STABILIZE the same `Q_A_RAT_YAW_*` PIDs as QSTABILIZE/QLOITER.

**Do not revert to `rudder_input / 4500`** in the plane branch — that discards the PID and produces open-loop yaw with no heading hold.

---

### [AV-INVAR:transition-skip]

**What:** `transition->force_transition_complete()` is called instead of `transition->update()` in FBWA plane mode for Avatar. The Blimp calls `transition->update()` and is unaffected by this invariant.

**Where:** `ArduPlane/quadplane.cpp` — Avatar FBWA block (`!g_config.tricopter_is_blimp`).

**Why:** `transition->update()` calls `hold_hover()` or `hold_stabilize()`, which call `multicopter_attitude_rate_update()`, which calls `attitude_controller_run_quat()`. This corrupts `_attitude_target`, `_pd_scale`, and `_ang_vel_body` — exactly the state that `[AV-INVAR:ang-vel-pitch-bypass]` and `[AV-INVAR:ang-vel-roll-tracking]` write directly each loop. Skipping `transition->update()` is what makes those direct writes stick.

**Why Blimp is exempt:** The Blimp's plane mode mixer uses `elevator_tilt_split` driven entirely by pilot stick input. It does not read `inputs.pitch` or `inputs.roll` from the attitude controller in plane mode, so `_ang_vel_body` corruption has no effect on Blimp mixer outputs. If the Blimp's plane mode is ever changed to consume `inputs.pitch` or `inputs.roll`, this invariant must be extended to cover it.

**If `transition->update()` is re-enabled for Avatar in plane mode**, both `[AV-INVAR:ang-vel-pitch-bypass]` and `[AV-INVAR:ang-vel-roll-tracking]` must be reconsidered. See § 4.4.1.

### [AV-INVAR:yaw-handoff-cos-tilt]

**Location:** `AP_Motors6DOF_AvatarMixer.cpp` — plane mode yaw TODO block.

**Rule:** Pilot rudder input drives rear motor differential yaw, scaled by `cos_tilt_b`. This is the same hover-to-cruise handoff used for roll differential: full motor yaw authority in hover (cos_tilt_b=1, no airspeed → rudder aerodynamically ineffective), fading to zero in cruise (cos_tilt_b=0, rudder at full aerodynamic authority).

**Why:** In a static hover the rudder surface produces no moment. In full forward flight it is inefficient and unnecessary to use rear motor differential for yaw when the rudder handles it. The cosine of the tilt angle is the correct transition function because it naturally tracks the same motor-to-surface authority handoff already used for roll.

**Status:** Fully implemented on T1 Ranger. Both rear motors present and wired. See section 2.3 for sign convention and PID starting values.

---

### [AV-INVAR:rear-pitch-priority]

**What:** The two rear motors carry the pitch/throttle common mode (`rear_demand`) and the yaw differential (`yaw_delta`) on the same two shared actuators. On saturation the common mode is prioritized: `rear_demand` is clamped to [0,1] first, then yaw receives only the symmetric headroom that remains (`yaw_room = min(rear_common, 1 - rear_common)`, applied as `rear_common ± yaw_delta`). Yaw is sacrificed before pitch.

**Where:** `AP_Motors6DOF_AvatarMixer.cpp` — both the plane STABILIZE branch (STATE B) and the copter/TVC branch (STATE C), which share the identical `rear_common ± yaw_delta` pattern. The plane branch also sets `outputs.limit.yaw` when the clamp is active. It is a no-op when unsaturated, so tuned normal flight is bit-for-bit unchanged. Covered by `[AV-INVAR:rear-pitch-priority]` tests in `tests/mixer_test` (Group N).

**Why:** The priority is the *inverse* of the wing-motor desaturation (`p_shift`, which preserves the roll differential and sacrifices common-mode throttle). For the rear pair the consequences are asymmetric: losing yaw is a recoverable heading drift, but losing pitch is an unrecoverable nose-up departure. A leftover full yaw split — front wing-motor thrust imbalance driving the yaw PID hard — railed one rear motor and starved the common mode, causing an uncommanded pitch-up to 52° in STABILIZE (log 00000072.BIN). The previous independent per-motor clamps truncate *both* pitch and yaw; this reallocation keeps pitch intact.

**This does not remove the disturbance** — it makes the failure survivable. The root cause (front wing-motor thrust imbalance inducing yaw) must still be corrected. Compounds with `[AV-INVAR:yaw-handoff-cos-tilt]`: `cos_tilt_b` already shrinks the rear common-mode headroom toward cruise before yaw is allocated.

---

### [AV-INVAR:pitch-before-throttle]

**What:** In the copter/TVC branch, pitch demand that one motor pair cannot deliver because it is railed at 1.0 is transferred to the other pair as a common-mode reduction, instead of being truncated. Front pair rails high (`throttle_thrust + pitch > 1`, nose-up demand at full throttle): the excess is subtracted from the rear pair (`rear = (throttle − pitch − front_excess) × cos_tilt`). Rear pair rails high (`(throttle − pitch) × cos_tilt > 1`, nose-down demand at full throttle): the excess is subtracted from the front base. The transfer is **lift-reducing only** — a pair railed at 0 does *not* boost the other pair.

**Where:** `AP_Motors6DOF_AvatarMixer.cpp` — copter/TVC branch (STATE C), between the `base_thrust`/`rear_thrust` computation and the roll headroom block. No-op when unsaturated, so tuned normal flight is bit-for-bit unchanged. Covered by Group O tests in `tests/mixer_test`.

**Why:** At full throttle the pitch couple (front `+pitch`, rear `−pitch × cos_tilt`) loses its increase side to the 1.0 rail — the pitch loop gain halves precisely when the disturbance is largest (e.g. a full-throttle spool transient where the rear motors build thrust faster than the fronts and pitch the nose down). The transfer restores the full tuned couple by sacrificing collective lift, which at full throttle means a slightly reduced climb — recoverable. A pitch departure is not. Same asymmetric-consequence argument as `[AV-INVAR:rear-pitch-priority]`; this extends the allocation hierarchy to pitch > roll/yaw > throttle. Precedent: stock ArduCopter's mixer prioritises roll/pitch over throttle the same way.

**Why lift-reducing only:** The symmetric case — boosting the opposite pair when one pair rails at 0 — would let a wound-up or railed pitch demand spin motors up at low throttle, i.e. near the ground during landing/flare. In the low-side case the old behaviour is kept: the demand is truncated and `limit.pitch` fires so the I-term stops winding.

**`limit.pitch` semantics changed:** It no longer fires merely because a pair railed at 1.0 — if the transfer delivered the moment through the other pair, the PID is not limited and must not be told it is. It fires only when pitch remains undelivered after the transfer: the receiving pair ran out of downward headroom (`base_thrust < 0` or `rear_thrust < 0` post-transfer).

**Interaction with the rest of the mixer:** The transfer happens *before* roll headroom (front pair) and yaw headroom (rear pair) are computed, so `[AV-INVAR:rear-pitch-priority]`'s `yaw_room` automatically respects the post-transfer rear common mode — the full hierarchy is pitch > roll/yaw > throttle with no other logic touched. The front→rear transfer is scaled by `cos_tilt`, matching how all rear pitch authority is scaled; both transfers fade out as the rear pair loses pitch relevance toward 90°.

**Bounded steal:** The transfer magnitude is bounded by `|inputs.pitch|`, which is bounded by the copter rate PID output limits — and it can only drive the receiving pair to 0, never negative. Worst case at full throttle is one pair at 1.0 and the other at 0 (maximum moment, half lift). No separate cap parameter is needed.

**Plane branch deliberately not covered:** In plane mode the front motors carry no pitch term (throttle ± roll only) — pitch is rear motor + elevator. Extending pitch-before-throttle there would mean cross-pair stealing front throttle when the rears rail, a separate design decision with TECS interactions. Scoped as future work.

---

### [AV-INVAR:tilt-servo-tracking]

**What:** In copter mode, `outputs.tilt_angle` (the servo command) is set to the TVC target immediately — the servo moves as fast as it physically can. `state.current_tilt_deg` is a separate software model of where the servo physically is, updated at a rate-limited speed each loop. All motor mixing (`cos_tilt` for roll authority, rear motor scaling) and the throttle transient scaling use `state.current_tilt_deg`, not the commanded target.

**Where:** `AP_Motors6DOF_AvatarMixer.cpp` — copter mode block, after `tvc_run_main_logic`. Identical mechanism in `AP_Motors6DOF_BlimpMixer.cpp` (`[BL-INVAR:tilt-servo-tracking]`). Rate injected from `Q_TILT_RATE_UP` via `mixer_in.tilt_rate_up_dps` in `AP_Motors6DOF.cpp`.

**Why it exists:** When the TVC commands a large tilt change, the servo takes time to physically travel. During that transient, the thrust vector is at the old angle while the motor mixing code could be computing for the new angle. The specific failure that prompted this: commanding forward thrust causes the servo to tilt toward horizontal, but while the servo is still near-vertical the motors are already producing near-full vertical thrust — more lift than intended, causing an unexpected altitude spike. The `throttle_thrust *= cos(error_deg)` term compensates: as the angular error between model and target grows, throttle is scaled down so the actual vertical component stays approximately correct. Motor mixing using `state.current_tilt_deg` similarly prevents roll authority and rear motor outputs from being computed for the wrong angle.

**`Q_TILT_RATE_UP` is a dependent variable, not a design choice.** It must be calibrated to match the actual physical slew rate of the tilt mechanism (servo speed divided by any gear ratio, expressed in degrees/second of mechanism travel). Setting it to an arbitrary value breaks the tracking:
- Too low: model lags behind the servo → mixer underestimates actual tilt → wrong motor outputs during transient
- Too high: model reaches the target before the servo does → error_deg collapses to zero → throttle compensation and motor mixing both use the target angle, as if the servo were already there — same problem as having no tracking at all

**Calibration procedure:** Command a full-range tilt and measure the time for the mechanism to complete travel. `Q_TILT_RATE_UP = mechanism_range_deg / measured_seconds`. Avatar's mechanism range is 90° (wings vertical to horizontal). The blimp's mechanism range is 180° (vertical to forward cruise). A servo that physically moves through its range in a given time will give different `Q_TILT_RATE_UP` values for each platform even if the servo itself is identical — the Avatar will have a proportionally higher value because it covers less angular distance.

**Do not use `outputs.tilt_angle` as the input to `cosf()` in copter mode.** `outputs.tilt_angle` is the target; `state.current_tilt_deg` is the physical position model. Using the target defeats the mechanism entirely.

**Contrast with plane mode tilt rate limiting** (`[AV-INVAR:plane-tilt-slew]`): that invariant rate-limits the servo command itself to give the aircraft time to build airspeed during the hover→cruise transition. This invariant does the opposite — sends the full target to the servo immediately, while protecting motor mixing for the duration of the physical travel.

**Interaction with `[AV-INVAR:mode-transition-blend]`:** during a mode-transition blend window the servo command follows the blended force vector instead of the raw TVC target, and the tracking model follows the blended command. The blend moves the command far slower than the servo's physical rate, so the model/servo error stays small and the cos(error) throttle compensation naturally stays ≈ 1 for the duration.

---

### [AV-INVAR:mode-transition-blend]

**What:** On any **in-flight** flight-mode change (Q↔Q, plane↔Q, plane↔plane — the mixer edge-detects `control_mode_id`, supplied every loop from `plane.control_mode->mode_number()`), the previous frame's commanded **trim thrust vector** `(F_horiz, F_vert)` is frozen as a snapshot, and the output trim blends from snapshot to the new mode's live command over `Q_TRANSITION_MS` (golden config: **1500 ms**; mixer default 1.5 s if unset). Both branches record their final commanded trim vector every frame (post-dampeners), so the snapshot automatically includes whatever the dampeners were contributing at the switch instant.

**Where:** `AP_Motors6DOF_AvatarMixer.cpp` — `apply_mode_transition_blend()` helper + edge-detection block at top of `mix()`; applied in the copter branch (servo command, tracking-model target, throttle) and the plane branch (throttle magnitude only — see below). Plumbing: `PlaneInputs::control_mode_id` / `transition_blend_s` set in `ArduPlane/quadplane.cpp`. Tests: Group P in `tests/mixer_test/test_main.cpp`.

**Why:** Two distinct purposes. (1) *Command-source discontinuity* — plane↔copter switches swap which architecture computes the motor commands; the copter TVC would command its (typically near-vertical) target to the servo **instantly** on entry, the abrupt motor tilt observed at STABILIZE→QSTABILIZE. (2) *Pilot grace window* — Q→Q switches reinterpret the throttle stick (direct % ↔ climb rate about mid); the blend gives the pilot ~1.5 s to re-center before the stale stick meaning takes full effect. The blend does NOT fix stick semantics — after the window the stick means what the new mode says it means; centering the throttle at the switch remains pilot procedure.

**Blend in force space, never actuator space:** the midpoint of two (tilt, throttle) pairs is not the midpoint of their net forces. Interpolate `(F_h, F_v)`, recompose via `atan2`/magnitude with the damp-block saturation rule (preserve vertical, clamp horizontal — defensive only: a convex combination of two ≤1 vectors cannot exceed 1).

**Stabilisation is never blended.** Roll/pitch/yaw PID deltas, rear-motor pitch mixing, and yaw differential are applied live around the blended trim at full authority throughout the window. Only the trim point transitions. (Copter-branch snapshot records collective only, excluding `inputs.pitch`, for the same reason.)

**Plane branch applies magnitude only:** plane-mode tilt continuity is already owned by the slew machinery (`[AV-INVAR:plane-tilt-slew]`, rate mode, and the copter-branch `pilot_tilt_deg` sync), so the snapshot direction ≈ live direction there and the vector blend reduces to a throttle handoff; writing the blended angle back would fight the slew's bookkeeping. This supersedes and replaces the old 0.5 s throttle-only `copter_to_plane_blend`.

**Anti-windup:** while the blend suppresses the live vertical demand, the mixer asserts `limit.throttle_upper/lower` so upstream closed-loop controllers (`AC_PosControl` Z) freeze their integrators instead of winding against thrust they are not getting — otherwise the wound-up I discharges as a surge when the blend expires.

**Ground safety:** mode tracking resets whenever spool ≠ `THROTTLE_UNLIMITED`; arming sequences and ground mode churn can never start a blend from a stale or zero snapshot.

**`Q_TRANSITION_MS` repurposing is safe for Avatar only** because Avatar never runs the stock transition state machine (`[AV-INVAR:transition-skip]` — `force_transition_complete()`). The blimp still calls `transition->update()`, which consumes the stock meaning — which is fine, because the blend lives in `AvatarMixer` and never executes for the blimp. Do not move the blend into shared code without resolving that parameter collision.

**Known accepted behavior:** failsafe-initiated mode changes (RC loss → QLAND/QRTL) also blend, softening the trim handoff by up to 1.5 s. Accepted deliberately: stabilisation stays live, and a smooth trim handoff arguably helps a failsafe entry.

---

### [AV-INVAR:sink-damp]

**What:** When the aircraft develops a sink rate in STABILIZE plane mode, a vertical thrust demand `damp_vert = v_z × Q_DAMP_VERT` is injected into the AvatarMixer via `PlaneInputs::damp_vert_thrust`. The mixer decomposes the current thrust vector into horizontal and vertical components, adds `damp_vert` to the vertical axis, and recomposes to derive a new tilt angle and new total throttle. This naturally tilts the rotors back toward vertical AND increases throttle in the physically correct ratio — no special-casing for tilt angle. Disabled when `tilt_deg ≥ cruise_physical_angle_deg` (pilot deliberately tilting past horizontal for descent).

**Where:** Two locations:
1. `ArduPlane/quadplane.cpp` — computes `avatar_sink_rate` from `inertial_nav.get_velocity_z_up_cms()` (gated to STABILIZE + tilt < 90°), sets `plane_inputs.damp_vert_thrust = avatar_sink_rate × damp_vert_gain`. Single parameter `Q_DAMP_VERT` (default 0.15, range 0–0.3).
2. `libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp` — plane mode block, after tilt integration, before motor output. Decomposes `(throttle × sin_tilt, throttle × cos_tilt + damp_vert)`, computes `new_tilt = atan2(horiz, vert)` and `new_throttle = sqrt(horiz² + vert²)`. Tilt-back is rate-capped to `Q_TILT_RATE_UP × dt` per loop so the servo is never commanded faster than it can physically travel.

**Why force-vector decomposition instead of separate tilt and throttle parameters:** A raw throttle boost is ineffective at near-horizontal tilt — adding throttle mostly produces forward thrust when `cos(tilt) ≈ 0`. The decomposition is correct at all tilt angles: at 80° forward, `atan2` returns a new angle much closer to vertical, which triples or quadruples the vertical component of existing thrust without consuming all available throttle headroom on forward thrust. One parameter controls intervention intensity across the full tilt range.

**Why P-only (no I, no D):** I-term would accumulate altitude debt during a descent and fight the pilot at touchdown. D-term differentiates noisy EKF velocity, producing throttle flutter.

**Why gate at `cruise_physical_angle_deg`:** When rotors are tilted past 90°, the pilot is deliberately commanding descent via tilt (see § 4.4.3). Dampening would fight that intent.

**Do not revert to separate tilt-dampening and throttle-boost parameters.** The decomposition is more correct at near-horizontal tilt angles, which is precisely where the documented crash scenarios occurred. The `fmaxf(cos_tilt, floor)` floor required by the old throttle-boost formula was a symptom of the formula being wrong in that regime.

---

### [AV-INVAR:long-damp]

**What:** When the aircraft accelerates forward in STABILIZE plane mode, a horizontal thrust correction `damp_horiz = -accel_bf_x × Q_DAMP_LONG × fade` is injected into `PlaneInputs::damp_horiz_thrust`. The force-vector decomposition in the mixer recomposes the pilot's thrust vector with this horizontal component, tilting the rotors back against the acceleration. A 2 Hz low-pass filter (`Q_DAMP_LONG_FILT`) smooths body-frame acceleration before it reaches the gain. A stick-activity fade zeroes the correction within 100 ms of pitch stick movement and restores it over 500 ms at centre — preventing the dampener from fighting deliberate pilot speed changes.

**Where:** `ArduPlane/quadplane.cpp` — computed in the `[AV-INVAR:long-damp]` block, summed into `damp_horiz_thrust` alongside `[AV-INVAR:vel-damp]`.

**Why acceleration-based is limited:** The filter introduces phase lag. At higher gains the corrective thrust arrives out of phase with the acceleration it is trying to damp, injecting energy instead of removing it and producing a self-sustaining pitch oscillation. In practice `Q_DAMP_LONG` must be kept at or below 0.05 on this airframe to stay stable. For stronger velocity hold, use `[AV-INVAR:vel-damp]` instead.

**Why P-only (no I, no D):** D of acceleration = jerk — amplifies noise catastrophically. I would wind up against sustained wind.

---

### [AV-INVAR:vel-damp]

**What:** A P controller on body-frame forward velocity error that holds the speed captured at stick release. While the pitch stick is active, `_vel_hold_target` updates continuously to track current velocity. The moment the stick returns to neutral, the snapshot freezes and the correction `-(vel_bf_x - _vel_hold_target) × Q_DAMP_VEL × fade` drives the aircraft back to exactly that speed. EKF NED velocity is rotated to body frame via the full rotation matrix (same approach as `[AV-INVAR:long-damp]`'s acceleration path). Uses the identical stick-activity fade factor as `[AV-INVAR:long-damp]` — zeroes within 100 ms of stick movement, recovers over 500 ms at centre.

**Where:** `ArduPlane/quadplane.cpp` — computed immediately after the `[AV-INVAR:long-damp]` block, summed into `damp_horiz_thrust` via `plane_inputs.damp_horiz_thrust = avatar_long_damp_thrust + avatar_vel_damp_thrust`.

**Why velocity rather than acceleration:** Velocity is the integral of acceleration — it changes slowly, has negligible phase lag relative to the oscillation frequencies of this airframe, and requires no filter. The closed-loop system is first-order: `v̇ = -K·v`, giving exponential decay to zero velocity. This is inherently stable at all gains (no phase margin issue). Contrast with `[AV-INVAR:long-damp]`, which is effectively a derivative-of-velocity feedback and requires a filter that introduces phase lag.

**Why no filter on EKF velocity:** EKF fuses GPS, accelerometers, and barometer — the velocity output is already smooth. Adding a filter would reintroduce the phase lag that causes `[AV-INVAR:long-damp]` to oscillate. Validated by inspection of `XKF1.VN` and `XKF1.VE` in flight logs.

**Why shared fade factor:** Both dampeners must yield simultaneously to pilot stick input. Using independent fades would allow one to remain active while the other zeroes, producing an asymmetric thrust demand that fights the pilot.

**Throttle activity detection:** The fade factor and VxHld slew gate respond to throttle stick movement as well as pitch stick movement. Throttle position is not a centred stick, so activity is detected by rate-of-change: if `abs(throttle_norm - last_throttle_norm) > 0.02` (~20 µs), a 200 ms latch (`_throttle_active_s`) is set. The latch bridges the gap between RC updates (~50 Hz) and the 400 Hz control loop so a single detected movement holds the active state long enough for the fade to fully suppress the correction. While either stick is active, `_vel_hold_target` slews toward current velocity so that release always snapshots a speed close to the new equilibrium.

**Why snapshot rather than zero target:** Zero target would actively decelerate the aircraft during normal forward cruise whenever the pilot releases the stick — fighting intentional flight. The snapshot captures pilot intent at the moment of release and holds it, correcting only deviations from that speed caused by wind or disturbances.

**Why P-only:** I-term would wind up against a steady headwind, producing a constant backward tilt that surprises the pilot when the wind drops. D-term would differentiate velocity = acceleration, reintroducing the phase-lag instability of `[AV-INVAR:long-damp]`.

**Saturation guard:** `_vel_hold_target` is only updated when `motors->get_throttle() < 0.95`. When motors are saturated the controller has no authority to execute the correction anyway; allowing the target to update to the current (runaway) speed would zero the error and snap the tilt forward violently the moment saturation clears. Freezing the target preserves the error so correction resumes as soon as headroom returns.

**Hold target tracking:** `_vel_hold_target = vel_bf.x` instantly whenever any stick (pitch or throttle) is active and motors are not saturated. Both pitch and throttle update the target because both can cause speed changes — if only pitch updated the target, a throttle-induced speed change would be fought by the dampener, producing incorrect trig (F_x = T × sin(θ) changes with T). With both updating the target, the error is exactly zero during all stick activity, so the dampener output is naturally zero without any explicit suppression. On stick release the target freezes and the dampener holds that speed.

**Fade factor on vel-damp output:** `avatar_vel_damp_thrust = -vel_error × damp_vel_gain × _damp_long_fade_factor`. The fade decays to 0 over 100 ms when sticks are active and recovers over 500 ms at neutral — shared with `Q_DAMP_LONG`. This requires the hold target to be frozen during stick activity (see below) so that `vel_error` remains non-zero for the fade to act on. Without the freeze, `vel_error = 0` always during stick use and the fade is irrelevant.

**Angle latch (throttle-only, instant snap):** On the first frame of throttle activity with neutral pitch, `pilot_tilt_deg` is snapped to `current_tilt_deg`. The mixer sets `tilt_target_deg = pilot_tilt_deg` when `damp_horiz = 0` (force block bypassed). Without the snap, `pilot_tilt_deg` is still 0° so `tilt_target = 0°` and the servo retracts at full physical speed the moment the dampener zeroes. With the snap, `pilot_tilt_deg = 15°` so `tilt_target = 15°` and the servo holds position. The freeze+fade then smoothly removes the residual corrective force while the servo stays put. State: `_last_throttle_active`.

**Hold target freeze + release snapshot:** During stick activity, `_vel_hold_target` is frozen (not updated). On the exact frame sticks release, `_vel_hold_target = vel_bf.x` is snapshotted so re-engagement starts from zero error. Saturation guard: snapshot is skipped if motors are saturated at release — frozen target preserves the error so correction resumes as soon as headroom returns. State: `_last_stick_active`. Previous behaviour (continuous tracking during stick activity) was correct for suppressing the dampener but prevented the fade from having a non-zero error to act on.

**Error cap ±1.5 m/s (`VEL_DAMP_ERROR_CAP_MS`):** The velocity error fed into the gain is clamped to ±1.5 m/s. Backstop against any residual large error reaching the mixer; prevents a violent multi-degree tilt snap even in edge cases not covered by the slew limiter.

**Starting value:** `Q_DAMP_VEL = 0.20` (horizontal thrust fraction per m/s of velocity error). At 1 m/s deviation from hold speed this commands 0.20 units of corrective horizontal thrust.

---

### [AV-INVAR:min-thr-tilt]

**What:** In plane modes, `plane_inputs.throttle_pct` is floored by `(Q_M_SPIN_MIN × cos(tilt_deg)) × 100`. At vertical (0°) the floor is `Q_M_SPIN_MIN` (~15%); at horizontal (90°) the floor is 0% (normal glide allowed); intermediate angles blend smoothly via cosine.

**Where:** `ArduPlane/quadplane.cpp` — plane_inputs block, immediately before the `throttle_pct` assignment. Gated by `plane.is_flying() && !g_config.tricopter_is_blimp`.

**Why:** In CRUISE/FBWB, TECS manages altitude and can command 0% throttle during a descent while rotors are vertical. With vertical rotors there is zero aerodynamic lift — motor thrust is the only thing keeping the aircraft up. ESCs take 1–2 seconds to spool back from zero, making re-throttle recovery a crash scenario. The floor prevents this while still allowing full glide in forward flight (cos(90°) = 0).

**Why not spool state gating:** `motors->get_spool_state()` is always `THROTTLE_UNLIMITED` in plane modes when armed — the motor controller is forced to that state unconditionally to accept continuous mixing commands. Spool state is useless as a gate here.

**Why `plane.is_flying()`:** Prevents the 15% floor from spinning up motors on the ground when armed. ArduPlane's probabilistic flying estimator decays back to false after touchdown, allowing motors to spin down safely.

**Do not apply this to blimps (`tricopter_is_blimp`):** A lighter-than-air vehicle has buoyancy and does not need a minimum vertical thrust floor to stay airborne.

---

### [AV-INVAR:tecs-synth-pitch]

**What:** In the no-airspeed TECS pitch-to-throttle mapping (`_update_throttle_without_airspeed`), the "measured pitch" input is the **earth-frame thrust-vector elevation**: `ahrs_pitch + (90° − current_tilt_deg)`. The body-relative tilt term is supplied by `QuadPlane::update()` each loop via `set_synthetic_pitch()`; TECS adds AHRS pitch internally. Rotors vertical + level fuselage ⇒ 90° ⇒ throttle → `THR_MAX`; rotors horizontal ⇒ 0° ⇒ `TRIM_THROTTLE`; past-horizontal descent ⇒ slightly negative ⇒ below trim. The LPF reset paths use the same substitution so mode entry starts the filter at the true current state.

**Why the sum (not tilt alone):** the tilt servo angle is fuselage-relative; if the nose is pitched up 10° with rotors at 45°, the thrust line is at 55° in the earth frame. This mirrors the TVC's pitch compensation (§ 4.2 — absolute thrust direction is what matters). It also keeps stock TECS's response to *real* nose excursions: in the stall-prevention regime (elevator saturated, nose rising) stock TECS raises throttle because it reads real pitch — tilt-alone would be blind to that. Nominally the level-hold keeps fuselage pitch ≈ 0 and the sum reduces to the tilt term; the 5 s LPF filters transient wobbles. Result is a superset of stock behaviour, not a replacement.

**Where:** Three locations: `AP_TECS.h` (setter + member, `#if ENABLE_TRICOPTER_VTOL_BACKEND`), `AP_TECS.cpp` (`_pitch_measured_for_throttle()` helper used at the `_pitch_measured_lpf` apply and both resets), `ArduPlane/quadplane.cpp` (per-loop feed in the PlaneInputs injection block).

**Why:** Stock ArduPlane infers climb effort from fuselage attitude — valid on a conventional plane where climbing *is* pitching up. Avatar's elevator + rear motor hold the fuselage level at all times, so AHRS pitch reads ~0 forever and sustained throttle pins at `TRIM_THROTTLE` (45%) regardless of tilt. Failure scenario: TECS demands climb → tilt walks toward vertical → thrust at 45% < weight → sink → more tilt demand → pitch demand rails at 90° while the aircraft mushes down, with underspeed/badDescent protection inert in this configuration. The thrust-vector angle is the aircraft's honest equivalent of "pitch": TECS's heuristic was always "throttle ∝ how upward the thrust line points"; fuselage pitch was merely how a conventional plane exposes it.

**Why the blimp is excluded** (`tricopter_is_blimp` keeps stock AHRS-pitch path): (1) different tilt geometry — the blimp's range spans 0–180° with a different cruise convention, so `90° − tilt` is wrong arithmetic for it (naively applied, emergency downward thrust would command *minimum* throttle); (2) buoyancy means the sink-on-tilt-up failure this fixes does not exist for it — same rationale as `[AV-INVAR:min-thr-tilt]`; (3) the blimp's plane mode is pilot-stick FBWA-style and has never flown TECS throttle modes. If the blimp ever flies FBWB/CRUISE/AUTO, add a blimp-specific tilt→pitch mapping using its own cruise-angle reference — do not reuse the Avatar formula.

**Do not "fix" this back to `_ahrs.get_pitch()`** because the fuselage pitch "looks more correct" — a level fuselage is the *designed* state at every tilt angle and carries zero climb-effort information on this aircraft. Do not feed the synthetic value anywhere else in TECS (energy estimates, pitch demand); it is scoped to the throttle mapping only.

**Default-safe:** `_synthetic_pitch_rad` defaults to 0 (= "rotors horizontal" = cruise throttle), which reproduces pre-fix behaviour if the setter is ever not called.

---

### [AV-INVAR:airspeed-cruise-gain]

**What:** `AIRSPEED_CRUISE` must never be set below ~1 m/s (current value: 3). It is the TECS pitch-loop gain denominator, not a speed target.

**Where:** Parameter file only; the code dependency is `AP_TECS.cpp` — `_EAS` fallback (`constrain(airspeed_cruise, min, max)` when no sensor) → `_TAS_state` → `gainInv = _TAS_state × g`, divided into the pitch demand. The backend patch that makes zero dangerous is the `min_airspeed = 0.0f` override in `_update_speed()` (tagged with this invariant), which removed stock ArduPilot's 3 m/s floor on `_TAS_state` because a zero-stall-speed vehicle must be allowed a zero airspeed *state*.

**Why:** With no airspeed sensor, TECS "measures" airspeed as `AIRSPEED_CRUISE` and converts climb demands to pitch (=tilt) angles as `γ ≈ v_z / AIRSPEED_CRUISE`. Setting it to 0 makes `gainInv = 0` → division by zero → pitch demand rails between limits (bang-bang tilt). The zero-stall intuition ("this aircraft has no minimum speed, so zero all airspeed params") is exactly the mistake this invariant guards against: `AIRSPEED_MIN = 0` is correct, `AIRSPEED_CRUISE = 0` is a crash. Tuning meaning: lower = more tilt per unit climb demand/altitude error (twitchier CRUISE), higher = gentler. See § 4.4.4.

---

### [AV-INVAR:fs-ground-disarm]

**What:** On RC link loss, disarm immediately **only when landed**, where "landed" = `!plane.is_flying()` **AND** the mixer's commanded trim thrust magnitude has been < 0.05 for > 3 s (`state.thrust_quiet_s`, accumulated every mixing frame; not-spooled-up counts as quiet). Airborne link loss falls through to the stock failsafe machinery (Q modes → QLAND, plane modes → CIRCLE → RTL). Restores the "turn the radio off to guarantee a disarm" ground workflow that the blimp's `failsafe_kill_motors` used to provide, without the blimp switch's crash-on-linkloss-in-flight behavior.

**Where:** `ArduPlane/events.cpp` — `failsafe_landed_disarm_check()`, called at the top of both `failsafe_short_on_event` and `failsafe_long_on_event` (after the blimp kill switch check); quiet clock in `AP_Motors6DOF_AvatarMixer.cpp` (`mix()`, after the mode-blend clock) + `MixerState::thrust_quiet_s` + `AP_Motors6DOF::get_thrust_quiet_s()`; enabled by `g_config.failsafe_disarm_when_landed` (Avatar true, blimp false — the blimp's `failsafe_kill_motors=true` short-circuits first anyway).

**Why two conditions:** `is_flying()` alone has a crash-grade false-negative on Avatar — in near-stationary CRUISE (deep headwind), `motors->get_throttle()` reads the pilot stick (~0 in TECS modes, `quadplane.cpp` `set_throttle_out(get_pilot_throttle())`), ground speed is below the 1.5 m/s heuristic, and the no-sensor airspeed estimate is unreliable, so `is_flying()` can decay false **at altitude**. The thrust-quiet condition is the backstop: in that regime TECS commands ≥ ~`TRIM_THROTTLE`, in a STABILIZE hover the pilot stick is high — every airborne regime commands substantial thrust, while a landed aircraft commands ~0 in every mode. The pair is satisfiable only on the ground.

**Why the trim vector (not motor outputs or pilot stick):** `last_thrust_horiz/vert` is recorded by both mixer branches every frame (shared with `[AV-INVAR:mode-transition-blend]`) — mode-agnostic, excludes stabilization deltas (a landed aircraft being nudged by wind still reads quiet), and reflects *commanded* intent rather than pilot input (so CRUISE with stick at bottom still reads loud).

**Do not** replace the pair with `!is_flying()` alone (mid-air disarm in the CRUISE gap regime) or gate on pilot stick position (CRUISE flies with the stick at zero). Tests: mixer_test Group Q.

---

### [AV-INVAR:pitch-90-identity]

**What:** `PTCH_LIM_MAX_DEG` must be exactly 90. It is not a tuning limit on this aircraft — it is the scale factor that makes "TECS pitch demand in degrees" a literal 1:1 identity with "thrust-vector elevation in degrees," and it appears in three independent code paths that are only mutually consistent at 90.

**Where:** Parameter file (`PTCH_LIM_MAX_DEG,90`); the three code dependencies are: (1) `ArduPlane/quadplane.cpp` PlaneInputs injection — `pitch_tilt_demand = nav_pitch_cd / (pitch_limit_max × 100)`, consumed by the mixer position branch (`AP_Motors6DOF_AvatarMixer.cpp`, `target_tilt_angle = cruise_norm × (1 − demand)`) where demand 1.0 = rotors fully vertical; (2) `[AV-INVAR:tecs-synth-pitch]` — the feedback path reports `90° − tilt` (thrust elevation) to TECS as measured pitch; (3) `AP_TECS.cpp` `_update_throttle_without_airspeed()` — `throttle = TRIM + (THR_MAX − TRIM) × pitch_blended / _PITCHmaxf`.

**Why 90 and only 90:** With the physical cruise angle at 90° from vertical, path (1) at `PTCH_LIM_MAX = 90` maps a demanded pitch of X° to a thrust elevation of exactly X°; path (2) then reports exactly X° back, so measured = demanded at steady state and the loop is dimensionally closed; path (3) then reaches `THR_MAX` at exactly 90° of blended pitch = exactly full tilt-up, pinning maximum thrust to precisely the regime where the aircraft hangs on its rotors. TECS itself does **no trigonometry** — its throttle law is a linear ramp that was designed as a crude "climbing costs power" heuristic for conventional planes. On Avatar the ramp doesn't need to be aerodynamically correct (the height-loop integrator trims out feed-forward error; the real force-vector trig lives in the mixer), but it must be *monotonic with correctly pinned endpoints*, and `PTCH_LIM_MAX = 90` is what pins the top endpoint to "vertical rotors = max throttle."

**Failure mode if changed:** any other value desynchronizes all three paths at once. Example at 45: TECS demanding 45° pitch would command rotors fully vertical (path 1), the feedback would report 90° against a 45° demand (path 2 identity broken, permanent apparent overshoot), and the throttle ramp would saturate at `THR_MAX` from 45° of elevation onward (path 3). The value looks like an innocent "maximum pitch" tuning knob to anyone with conventional-plane instincts — lowering it "for safety" is the anticipated mistake this invariant guards against.

**Note:** `PTCH_LIM_MIN_DEG` (= −25) carries no such identity — descent is throttle-cut-dominated, the tilt-forward-of-cruise range is deliberately small, and its value is a genuine tuning choice. See `notes/cruise_considerations.md` § 7 for the operational summary.

---

### [AV-INVAR:plane-tilt-slew]

**What:** In FBWA plane mode, `outputs.tilt_angle` (the servo command) is rate-limited before being written. The target is computed from `nav_pitch_cd` (pilot stick + TECS) as normal, but `state.current_tilt_deg` slews toward it at an asymmetric rate: fast toward vertical (Q_TILT_RATE_UP, servo physical speed) and slow toward horizontal (Q_TILT_RATE_DN, an independent design choice). `outputs.tilt_angle` is then derived from the slewed `state.current_tilt_deg`, so all downstream calculations (`tilt_deg_b`, `cos_tilt_b`, roll differential, rear motor) use the commanded position.

**Where:** `AP_Motors6DOF_AvatarMixer.cpp` — plane mode block, replacing the previous single-line `constrain_float`. `Q_TILT_RATE_DN` injected alongside `Q_TILT_RATE_UP` in `AP_Motors6DOF.cpp` inside `#if ENABLE_TRICOPTER_VTOL_BACKEND`. When `Q_TILT_RATE_DN = 0`, falls back to `Q_TILT_RATE_UP`.

**Why asymmetric:** The two directions have opposite urgency. Tilting toward vertical is stall recovery — it must happen as fast as the servo physically can (Q_TILT_RATE_UP = servo speed). Tilting toward horizontal is the hover→cruise transition — if it happens at servo speed (~0.75s), the aircraft loses all vertical motor thrust before aerodynamic lift has time to develop and falls. Slowing this to ~3 seconds (Q_TILT_RATE_DN = 30 °/s at 90° range) gives the motors time to accelerate the aircraft while they still have a vertical thrust component.

**Why at the servo command, not at `nav_pitch_cd`:** Rate-limiting `nav_pitch_cd` in quadplane.cpp would require Avatar-specific logic in the ArduPlane attitude controller path and would fight TECS's stall-recovery pitch demands. Rate-limiting the servo command in the mixer is downstream of all guidance and affects both pilot and TECS input uniformly. It is also the natural place — the mixer owns all actuator commands.

**`Q_TILT_RATE_DN` is an independent design choice**, not a hardware calibration. It should be set to produce the transition time that allows airspeed to build: `Q_TILT_RATE_DN = 90 / desired_transition_seconds`. At 30 °/s, full transition takes 3 seconds. Current value in param file: **30 °/s**.

**`state.current_tilt_deg` continuity:** Both copter mode (`[AV-INVAR:tilt-servo-tracking]`) and plane mode write `state.current_tilt_deg`. At a copter→FBWA mode switch, the slew starts from wherever copter mode left the tilt angle — no discontinuity.

**Contrast with `[AV-INVAR:tilt-servo-tracking]`:** That invariant sends the full target to the servo immediately and uses `state.current_tilt_deg` only for motor mixing bookkeeping. This invariant does the opposite — `state.current_tilt_deg` is the authoritative servo command, and the servo only moves as fast as the slew allows.

---

### [AV-INVAR:passive-weathervane]

**What:** In all nav plane modes (STABILIZE, CRUISE, AUTO, …) and QSTABILIZE, when the pilot has no rudder input (`get_pilot_input_yaw_rate_cds() == 0`), the yaw rate PID I-term is reset to zero each control loop before the rate controller runs. P and D continue to operate, providing yaw damping. When the pilot applies rudder input, the reset does not fire and the I-term accumulates normally, giving full PID authority for commanded yaw. (Scope extended alongside `[AV-INVAR:stabilize-yaw-pid]` July 2026; in hands-off banked nav turns the reset is what keeps the yaw PID from winding up against the coordinated-turn yaw rate.)

**Where:** Two locations, both gated by `g_config.custom_weathervane`:
1. `ArduPlane/quadplane.cpp` — Avatar FBWA block, STABILIZE branch: `attitude_control->get_rate_yaw_pid().reset_I()` before `rate_bf_yaw_target(pilot_yaw_cds)`.
2. `ArduPlane/mode_qstabilize.cpp` — `ModeQStabilize::run()`: same reset before `hold_stabilize()`.

**Why:** The yaw rate PID I-term accumulates to resist any sustained yaw motion, including rotation driven by the airframe's natural aerodynamic weathercock stability. Avatar's fixed-wing fuselage has a meaningful weathervaning moment — the vertical tail and fuselage shape create a restoring force that rotates the nose into the wind. Without this change, the I-term builds up to oppose this rotation indefinitely, and the aircraft points wherever it was placed rather than aligning with the wind. Resetting I each cycle while keeping P and D means: (a) brief yaw disturbances are damped by P, and (b) the sustained aerodynamic weathervaning moment, which is larger than what P alone can resist, can slowly rotate the nose into wind.

**Why not QLOITER:** QLOITER has active weathervaning via `AC_WeatherVane` (see `[AV-INVAR:stabilize-yaw-pid]` and § 5.2). The I-term in QLOITER supports the active yaw rate commands from `AC_WeatherVane` and should not be zeroed.

**CRUISE note:** the I-reset now fires in CRUISE too (July 2026 scope extension). In forward flight it is a no-op for weathervaning (a steadily flying aircraft develops no sideslip for the fin to react to — weathervaning only exists when ground velocity is constrained), but it serves a second purpose there: keeping the yaw PID P/D-only during hands-off banked turns so it cannot wind up against the coordinated-turn yaw rate.

**Do not apply to modes with active position or heading hold** — resetting I there would degrade tracking performance.
