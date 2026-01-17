# Blimp Project TODO - January 16, 2026

## Immediate Verification
- [x] **Verify Throttle Boost Fix:** Pitch the gondola manually and confirm the lift motors no longer surge (Angle Boost disabled).

## Hardware & ESC Debugging
- [ ] **Lift Motor Sync:** Investigate why Motors 1 and 2 spin at different speeds. Check ESC calibration and throttle mapping.
- [ ] **Tail Motor Fix:** Diagnose why Motor 3 (Yaw) is not spinning. Check ESC 3D/Bidirectional configuration and wiring.
- [ ] **Range Finder:** Verify the hardware connection for the range finder and ensure distance data is being read correctly in the GCS.

## Software Refactoring
- [ ] **Output Function Mapping:** Rename/Refactor motor outputs to use standard Servo Functions (e.g., `k_scripting1`, `k_yaw`) where appropriate. This is necessary to prepare for sharing actuators with the QuadPlane/Plane code without function conflicts.

## Safety & Control Logic
- [ ] **Transient Thrust Limiting (Emergency Descent):**
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