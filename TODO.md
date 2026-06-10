# Blimp / Avatar Project TODO - January 16, 2026

## Hardware & Sensors
- [ ] **Range Finder:** Verify TF02-Pro integration via Serial.

## QuadPlane Integration (Next Steps)
- [ ] **Takeoff Logic:** Allow `TKOFF_ROTATE_SPD = 0` (Lift-off without runway run).
- [ ] **Transition Blending:** Implement smooth 0.0 -> 1.0 blending for tilt servos.

## Stability & Flight Testing
- [ ] **Multi-copter Stability:** Finalize QSTABILIZE tuning.
- [ ] **Altitude Hold:** Verify Rangefinder feedback in QHOVER.
- [ ] **Position Hold:** Verify Optical Flow / GPS feedback in QLOITER.
- [ ] **Weathervane Baseline:** Before enabling weathervaning, fly a stable Loiter session to confirm yaw hold is solid with `custom_weathervane = false` (current default). This establishes a baseline with no unknown variables.
- [ ] **Weathervane Enable:** After baseline is confirmed, set `custom_weathervane = true` in `libraries/AP_CustomConfig/AP_CustomConfig.cpp` for the relevant config and set `WVANE_DIRECTION = 1` (nose into wind), `WVANE_GAIN = 1.0`, `WVANE_ANG_MIN = 1.0`. Verify the aircraft yaws to face into wind during Loiter without hunting.

## Avatar Flight Log Checks
- [x] **TVC forward scaling (Issue 5):** The 2× scaling at `libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp` was written to normalize manual mode (acro/sport) inputs which are capped at ±0.5 (`ArduCopter/mode_acro.cpp:73`, `mode_sport.cpp:136`). We never fly those modes. In stabilized/althold/loiter, `set_forward` is called from `libraries/AC_AttitudeControl/AC_AttitudeControl_Multi_6DoF.cpp:75` via `-sinf(pitch_angle)` which has a full ±1 range (`AP_Motors_Class.h:147`). After the 2× multiply, the TVC saturates at `inputs.forward = ±0.5`, halving forward tilt authority. **To confirm**: set `#define AVATAR_DEBUG_LOG 1` at the top of `AP_Motors6DOF_AvatarMixer.cpp`, fly a forward translation maneuver in AltHold/Loiter, and read the `AV fwd=` value in Mission Planner messages. If it regularly exceeds ±0.5, remove the 2× factor from the `f2pwm(inputs.forward * 2.0f, ...)` call.

## Avatar FBWA Transition

- [ ] **Bumpless transfer on copter→FBWA mode switch:** When transitioning from a copter mode (e.g. QStabilize) to FBWA from a hover, TECS initializes with zero integrators. The P-term responds immediately to the large kinetic energy deficit (zero airspeed vs. target), but the integrators need time to wind up, creating an instability window. Solution: at the moment of transition, pre-load TECS state variables from the copter controller's current output:
  - Copter hover throttle output → `_integTHR_dem`
  - `_integSEB_dem` (specific energy balance integrator, drives pitch demand) → pre-load to max, since at zero airspeed the energy balance demand is maximal
  - The mapping is approximate (copter operates in attitude space, TECS in energy space), but the goal is just that TECS's first output is already saturated toward what's needed rather than winding up from zero.
  - This is the classical **bumpless transfer** technique for controller handoffs.

## Avatar ArduPlane Integration