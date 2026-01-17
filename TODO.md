# Blimp Project TODO - January 16, 2026

## Hardware & ESC Debugging
- [x] **Tail Motor Consistency:** 3D DShot working with `SERVO_BLH_3DMASK` (or PWM workaround).
- [x] **Lift Motor Sync:** Resolved uneven speeds.
- [ ] **Range Finder:** Verify R50-C via MAVLink (Type 10) or Custom Driver (Type 44).

## Software Refactoring & Safety
- [x] **Output Function Mapping:** Servos refactored to `k_scripting2/3`. Motor count reduced to 3.
- [x] **Transient Thrust Limiting:** Implemented via "Virtual Servo" slew estimation and cosine-based throttle scaling.
- [x] **Disarmed Safety:** Servos center and motors stop when disarmed. Slew estimator resets.

## QuadPlane Integration (Next Steps)
- [ ] **Core Adaptation:**
    *   Allow `AIRSPEED_MIN = 0` (Bypass `AP_TECS` floor).
    *   Update Takeoff logic to allow `TKOFF_ROTATE_SPD = 0` (Lift-off without forward run).
- [ ] **Multi-copter Stability:** Ensure the airframe is 100% stable and predictable in `QSTABILIZE` before attempting transitions.