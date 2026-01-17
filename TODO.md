# Blimp Project TODO - January 16, 2026

## Immediate Verification
- [x] **Verify Throttle Boost Fix:** Pitch the gondola manually and confirm the lift motors no longer surge (Angle Boost disabled).

## Hardware & ESC Debugging
- [ ] **Lift Motor Sync:** Investigate why Motors 1 and 2 spin at different speeds. Check ESC calibration and throttle mapping.
- [ ] **Tail Motor Fix:** Diagnose why Motor 3 (Yaw) is not spinning. Check ESC 3D/Bidirectional configuration and wiring.
- [ ] **Range Finder:** Verify the hardware connection for the range finder and ensure distance data is being read correctly in the GCS.

## Software Refactoring
- [x] **Output Function Mapping:** Servos refactored to `k_scripting2/3`. Motor count reduced to 3.

## Safety & Control Logic
- [x] **Transient Thrust Limiting:** Implemented via "Virtual Servo" slew estimation and cosine-based throttle scaling. Includes disarmed state reset for safe arming.

## Hardware & ESC Debugging
- [x] **Tail Motor Consistency:** 3D DShot working with `SERVO_BLH_3DMASK`.
- [ ] **Lift Motor Sync:** Investigate uneven speeds on Motors 1 and 2.
- [ ] **Range Finder:** Wire and verify Benewake TF02-Pro.

## QuadPlane Integration
- [ ] **Core Adaptation:** TECS floor removal, 0 airspeed takeoff, airspeed min = 0.
    *   *Problem:* Commanding full down (-1.0) causes motors to spin to 100% immediately while servos are still rotating from Up/Forward to Down (180°). This results in a transient burst of wrong-way thrust.
    *   *Goal:* Clip/Limit throttle output based on the servo's *actual* (or estimated) position relative to the target vector. Only allow full power once the vector is aligned.
    *   *Solution (Verified):* Implement a "Virtual Servo" model in `AP_Motors6DOF` similar to `Tiltrotor::slew`.
        *   Define a Slew Rate parameter (deg/s) matching the physical servo speed.
        *   Update a `_current_tilt` state variable every loop based on `dt * rate`.
        *   Compare `_current_tilt` (estimated position) vs `_target_tilt` (command).
        *   Clip or scale `throttle_thrust` if the angular error is large (e.g. > 20°), ensuring motors wait for the vector to align.

## QuadPlane Integration
- [ ] **Plane Code Fixes:** Begin implementing the necessary adaptations in the ArduPlane core logic (TECS floor, Airspeed Min, etc.) as outlined in the design documents.
- [ ] **Multi-copter Stability:** Ensure the airframe is 100% stable and predictable in `QSTABILIZE` before attempting transitions.