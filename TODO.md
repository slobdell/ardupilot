# Blimp Project TODO - January 16, 2026

## Debugging
- [ ] **Plane Input Loss:** Investigate why `k_rudder` and `k_throttle` are 0 in STABILIZE mode. (Debug logs added).
- [ ] **Lift Motor Sync:** Resolved.
- [ ] **Range Finder:** Verify R50-C via MAVLink (Type 10) or Custom Driver (Type 44).

## Software Architecture
- [x] **Baseline Mixing:** 3 Motors + 2 Scripting Servos.
- [x] **Data Injection:** `set_plane_inputs` implemented.
- [x] **Safety:** Slew limiting & Disarmed centering implemented.
- [x] **Mixer Bypass:** Removed (Using cooperative function mapping).

## QuadPlane Integration (Next Steps)
- [ ] **Core Adaptation:**
    *   Allow `AIRSPEED_MIN = 0` (Bypass `AP_TECS` floor).
    *   Update Takeoff logic to allow `TKOFF_ROTATE_SPD = 0`.
- [ ] **Multi-copter Stability:** Ensure the airframe is 100% stable in `QSTABILIZE`.
