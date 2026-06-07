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

## Avatar ArduPlane Integration
- [ ] **Fixed-wing PID integrator decay during motor-up phase:** The block at `ArduPlane/Attitude.cpp:27-40` decays ArduPlane's roll/pitch/yaw PID integrators (`rollController.decay_I()`, `pitchController.decay_I()`, `yawController.decay_I()`) when in VTOL mode at low airspeed. This prevents windup from accumulating while aerodynamic surfaces are ineffective. The decay is gated on `threshold = airspeed_min * 0.5` which equals 0 since we set `ARSPD_FBW_MIN = 0`, so the block never fires. Need an alternative trigger that doesn't rely on the airspeed threshold — good candidates: wing tilt angle from `_mixer_state.current_tilt_deg` (available in `libraries/AP_Motors/AP_Motors6DOF.h`), or a hardcoded low-airspeed floor inside `#if ENABLE_TRICOPTER_VTOL_BACKEND` (defined in `libraries/AP_CustomConfig/AP_CustomConfig.h:51`).