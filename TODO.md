# Blimp Project TODO - January 16, 2026

## Hardware & Sensors
- [ ] **Range Finder:** Verify TF02-Pro integration via Serial.
- [x] **Tail Motor Sync:** Reversible DShot confirmed working.
- [x] **Servo Range:** Confirmed 270 deg authority.

## Software Architecture (Unified Mixing)
- [x] **Data Injection:** Injected from QuadPlane to Motor Backend.
- [x] **Dual-Mode Switching:** Binary switch between Copter (TVC) and Plane logic based on mode.
- [x] **Asymmetric Mapping:** Center 0.5 (Forward 90), Min -1.0 (Back -90), Max 1.0 (Down 180).
- [x] **Split Pitch Control:** Tail Elevator handover logic implemented (Split = 0.0).
- [x] **Manual Mode Fix:** Motors/Servos active in MANUAL mode via Spool State override.
- [x] **Technical Cleanup:** Removed dead code, logs, and technical debt.

## QuadPlane Integration (Next Steps)
- [ ] **TECS Adaptation:** Allow `AIRSPEED_MIN = 0` (Bypass 3.0m/s stall floor).
- [ ] **Takeoff Logic:** Allow `TKOFF_ROTATE_SPD = 0` (Lift-off without runway run).
- [ ] **Transition Blending:** Implement smooth 0.0 -> 1.0 blending for tilt servos.

## Stability & Flight Testing
- [ ] **Multi-copter Stability:** Finalize QSTABILIZE tuning.
- [ ] **Altitude Hold:** Verify Rangefinder feedback in QHOVER.
- [ ] **Position Hold:** Verify Optical Flow / GPS feedback in QLOITER.