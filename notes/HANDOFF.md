# Avatar Flight Handoff — PID Tuning (Roll & Yaw) + Next Task: Thrust Linearization

**Date:** June 2026  
**Airframe:** Hee-wing T1 Ranger  
**FC:** MicoAir H743 (`AHRS_ORIENTATION=6`)  
**Branch:** `slobdell_base`  
**Test mode:** QSTABILIZE (copter mode, wings vertical)

**Last flight:** QSTABILIZE stable and flying well. QLOITER not working — see Known Issues.

---

## What's Working

- Hover in QSTABILIZE: stable and flight-tested
- Roll: differential wing motor thrust, tuned and flight-tested
- Yaw: dual rear motor differential via spring-lever mechanism, flight-tested
- Pilot stick inputs (roll, yaw, pitch, throttle): all correct directions
- Disturbance correction (roll, yaw): confirmed resists rather than amplifies
- Motor arming: fixed — mixer now returns DShot 0 during GROUND_IDLE (preventing PID state from leaking into arming window) and applies spin_min floor during SPOOLING_UP/THROTTLE_UNLIMITED (preventing rear motor stall protection from triggering mid-flight)

---

## Motor Layout

| Index | Define | Physical | SERVO | SERVO_FUNCTION |
|-------|--------|----------|-------|----------------|
| 0 | `AVATAR_MOT_WING_LEFT` | Left wing motor | SERVO1 | 33 |
| 1 | `AVATAR_MOT_WING_RIGHT` | Right wing motor | SERVO4 | 34 |
| 2 | `AVATAR_MOT_YAW_RIGHT` | Right rear yaw motor | SERVO3 | 35 |
| 3 | `AVATAR_MOT_YAW_LEFT` | Left rear yaw motor | SERVO2 | 36 |

---

## Yaw Mechanism

Spring-lever: differential thrust between the two rear motors causes the higher-thrust side to swing outward, delivering lateral side force for yaw.

**Sign convention in mixer (`AP_Motors6DOF_AvatarMixer.cpp`):**
```
yaw_delta = inputs.yaw * cos_tilt
YAW_LEFT  = rear_thrust + yaw_delta   // positive inputs.yaw → increases
YAW_RIGHT = rear_thrust - yaw_delta   // positive inputs.yaw → decreases
```
Positive `inputs.yaw` = right yaw (standard ArduPilot convention).

**Important:** This is differential *thrust*, not differential *torque*. The gains have more physical authority per unit than a standard torque-based copter. Approach gains from below and tune up slowly.

**Known behavior:** In a neutral hover with no yaw input, rear_thrust is small (wing motors carry most of the load), so one rear motor may be near-zero at idle. This is expected — the differential activates meaningfully when yaw is commanded.

---

## Current PID Values (golden param file)

### Roll
```
Q_A_ANG_RLL_P  = 4.5
Q_A_RAT_RLL_P  = 0.25
Q_A_RAT_RLL_I  = 0.25
Q_A_RAT_RLL_D  = 0.003
Q_A_RAT_RLL_FF = 0
```
Flight-tested baseline. Reverted after first flight — increase 50% if roll feels sluggish.

### Yaw
```
Q_A_ANG_YAW_P  = 2.0
Q_A_RAT_YAW_P  = 0.03
Q_A_RAT_YAW_I  = 0.01
Q_A_RAT_YAW_D  = 0
Q_A_RAT_YAW_FF = 0.5
```
Flight-tuned with criss-cross thrust geometry. ANG_YAW_P reduced to 2.0 (from 4.5) and RAT_YAW_P to 0.03 to eliminate oscillation. If oscillating, reduce ANG_YAW_P first, then RAT_YAW_P.

---

## Tuning Workflow

Set params live over MAVLink (board must be connected via USB):
```bash
python3 tools/mavlink/param_set.py Q_A_RAT_YAW_P 0.1 Q_A_RAT_YAW_I 0.01
```

Read current board params:
```bash
python3 tools/mavlink/param_dump.py
```

After tuning, update the golden file so values survive a full restore:
```
params/avatar_t1ranger_micoair.param
```
Apply golden file: `python3 tools/mavlink/param_apply.py params/avatar_t1ranger_micoair.param`

Flash new firmware: `./micoair_flash.sh --flash`

---

## Tuning Approach

### Yaw (start here — less tested)

1. Hold aircraft in hand, hover in QSTABILIZE
2. Release yaw stick — aircraft should resist external yaw disturbances
3. If oscillating at rest: reduce `Q_A_RAT_YAW_P`
4. If sluggish / disturbances barely resisted: increase `Q_A_RAT_YAW_P`
5. Once P feels right, add I slowly to eliminate steady-state yaw drift
6. `Q_A_RAT_YAW_FF = 1.0` is the current value (doubled from 0.5) — reduce if pilot yaw feels too aggressive
7. Target: snappy resistance to disturbance, smooth pilot response, no oscillation

Suggested P range to explore: **0.05 → 0.2**. Back off 30% from the onset of oscillation.

### Roll (re-validate with new rear motors)

Current values (P=I=0.25, D=0.003) were tuned before the dual rear yaw motors were added. The added rear motor mass changes the roll inertia slightly. If roll feels different:

1. In QSTABILIZE, command sharp roll inputs and observe response
2. If oscillating: reduce P then D
3. If sluggish: increase P
4. I should roughly track P (I ≈ P is a reasonable starting ratio for this airframe)

---

## Tilt Servo Range

| PWM | Position |
|-----|----------|
| 811 | Wings horizontal (cruise) |
| 1827 | Wings vertical (hover) |
| 2025 | 15° past vertical (braking) |

SERVO5_MAX = 2025 opens the braking range. The mixer must clamp to 1827 for normal flight and only allow beyond 1827 when braking is commanded.

---

---

## Next Task: Thrust Linearization

### The Problem

The motor mixing pipeline currently outputs thrust fractions (0.0–1.0) that are converted to PWM **linearly** in `AP_Motors6DOF::calc_thrust_to_pwm()` (`libraries/AP_Motors/AP_Motors6DOF.cpp`, line 245):

```cpp
return (thrust_in * (get_pwm_output_max() - minPwm)) + minPwm;
```

This is wrong. Motor thrust is proportional to RPM², and RPM is roughly proportional to PWM for a linear ESC (DShot). Therefore:

```
thrust ∝ PWM²
```

A command of 50% throttle sends 50% PWM but produces only ~25% of maximum thrust. This means:
- The mixer's roll differential, rear motor mixing, and TVC throttle scaling all assume linear thrust but receive quadratic output
- Gain-scheduled control is inconsistent across the throttle range
- Hover throttle is higher than it should be, and low-throttle authority is worse than intended

### What Already Exists (Not Yet Applied)

`Q_M_THST_EXPO = 0.65` is in the golden param file (`params/avatar_t1ranger_micoair.param`). This is ArduPilot's standard thrust expo parameter. Standard `AP_MotorsMulticopter` applies it via `thrust_to_actuator()`:

```cpp
// Standard ArduPilot formula (AP_MotorsMulticopter.cpp):
float actuator = expo * (thrust * thrust - thrust) + thrust;
// At expo=0: actuator = thrust (linear, current broken state)
// At expo=1: actuator = thrust² (full quadratic correction)
// At expo=0.65: partial correction matched to typical motor curves
```

Our custom `calc_thrust_to_pwm()` ignores this entirely — `Q_M_THST_EXPO` has no effect on our motors.

### Where to Make the Fix

The fix belongs in `AP_Motors6DOF::calc_thrust_to_pwm()` (`libraries/AP_Motors/AP_Motors6DOF.cpp`, line 245). Apply the expo curve to `thrust_in` before the linear PWM scaling:

```cpp
// Read expo from the standard ArduPilot parameter (already exists on the object)
float expo = constrain_float(_thrust_curve_expo, 0.0f, 1.0f);
float linearized = expo * (thrust_in * thrust_in - thrust_in) + thrust_in;
return (linearized * (get_pwm_output_max() - minPwm)) + minPwm;
```

`_thrust_curve_expo` is the member variable backing `Q_M_THST_EXPO` — it is already declared in `AP_MotorsMulticopter` which `AP_Motors6DOF` inherits from. Confirm the member name by checking `AP_Motors/AP_MotorsMulticopter.h`.

Note: this only applies to the non-reversible path. The reversible path (blimp tail motor) uses a different formula and should be evaluated separately.

### Context on the Mixer Architecture

The mixer (`libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp`) outputs `motor_thrust[i]` values in the range [0, 1] representing **thrust fractions**, not PWM fractions. The design intent is that 0.5 means 50% of maximum thrust. The `calc_thrust_to_pwm` function is the sole conversion point between that intent and actual PWM — fixing it there corrects the entire pipeline without touching mixer logic.

The TVC brain (`tvc_run_main_logic` in `libraries/AP_Motors/TVC_Core.cpp`) also works in thrust-fraction space and its `total_throttle` output is passed directly to `motor_thrust`. So linearization at `calc_thrust_to_pwm` is the right and complete fix.

---

## Things to Watch

- **AVATAR_DEBUG_LOG=1:** The firmware logs to GCS every 1–3 seconds (`AV ...` messages). Useful for observing `yaw=`, `gz=`, and motor values mid-flight. Disable before production (`#define AVATAR_DEBUG_LOG 0` in `AP_Motors6DOF_AvatarMixer.cpp`).
- **ARMING_CHECK=50:** Pre-flight arming checks are reduced. Do not fly without verifying motor directions manually first.
- **Q_A_RAT_YAW_FF = 1.0 is above the documented max of 0.5.** ArduPilot does not hard-clamp it but GCS tools will flag it. Reduce if pilot yaw feels too aggressive.
- **SERVO_DSHOT_RATE = 1** (changed from 4 to reduce update frequency and improve DShot reliability on rear motors).

## Known Issues

### QLOITER — lurches forward immediately on engagement
QLOITER was attempted in flight and immediately lurched forward. Root cause: likely compass/heading error. QLOITER's position controller translates world-frame position errors into attitude commands using EKF heading. If heading is wrong, corrections go in the wrong direction. Suspected culprits:
- IST8310 compass on MicoAir being affected by EMI from rear motors spooling up
- `EK3_SRC1_YAW = 1` (compass only) — no GPS yaw fallback

**Do not use QLOITER until compass interference is investigated.** Check EKF heading in logs at the exact moment of QLOITER engagement. Consider `EK3_SRC1_YAW = 2` (GPS) if hardware supports it.

---

## Context on Yaw History (why the sign convention matters)

The yaw motor differential has been swapped twice. The current assignment (`YAW_LEFT = rear + yaw_delta`, `YAW_RIGHT = rear - yaw_delta`) is a **temporary workaround** driven by a hardware constraint:

**Why the swap exists:** To gain more angular headroom on the spring-lever mechanism, the motors were physically re-routed so their thrust vectors now **criss-cross** (each motor's thrust passes through or across the centerline) rather than pushing outward from the centerline as originally designed. This inverts the relationship between differential thrust and yaw direction, requiring the `+`/`-` swap in the mixer to restore correct yaw sense.

**This will need to be reversed** when the mechanism is rebuilt with the intended outward-thrust geometry. At that point, restore:
```
YAW_LEFT  = rear_thrust - yaw_delta
YAW_RIGHT = rear_thrust + yaw_delta
```
and re-verify both pilot yaw direction and disturbance resistance before flight.

The attitude controller's yaw rate PID (P and I) uses standard positive gains with the current motor assignment. No special sign handling is needed.
