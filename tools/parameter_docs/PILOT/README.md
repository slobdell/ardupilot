# Pilot Input Configuration (PILOT)

## Overview
The **PILOT** parameter group defines how the pilot's stick inputs are interpreted in assisted and autonomous flight modes.

These parameters do not affect Manual/Stabilize modes. Instead, they control the "feel" of modes like AltHold, Loiter, and Auto when the pilot uses the sticks to override or guide the autopilot.

## Key Concepts

### 1. Vertical Speed (`PILOT_SPEED_UP` / `DN`)
In modes with automated altitude control (AltHold, Loiter), the throttle stick no longer controls raw motor power. Instead, it commands a **Climb** or **Descent** rate.
*   **`PILOT_SPEED_UP`**: Maximum climb rate at full throttle (cm/s).
*   **`PILOT_SPEED_DN`**: Maximum descent rate at zero throttle (cm/s).

### 2. Vertical Smoothness (`PILOT_ACCEL_Z`)
Limits the vertical acceleration. A lower value makes the drone feel more "floaty" and smooth when starting or stopping a climb.

### 3. Takeoff Behavior (`PILOT_TKOFF_ALT`)
Defines the altitude (centimeters) the vehicle will automatically climb to when an automated takeoff is triggered via the pilot's stick.

## Parameter Breakdown

*   **`PILOT_SPEED_UP`**: Climb rate (e.g., 250 = 2.5 m/s).
*   **`PILOT_ACCEL_Z`**: Vertical acceleration limit (cm/s/s).
*   **`PILOT_THR_BHV`**: Bitmask for throttle behaviors (e.g., feedback or spring-centered).

## Integration Guide
*   **Heavy Payloads:** If your drone struggles to stop a descent, you may need to reduce `PILOT_SPEED_DN` or increase `PILOT_ACCEL_Z`.
*   **Precision:** If you find it hard to hover at a precise altitude, increase `PILOT_THR_FILT` to smooth out noisy RC sticks.

## Developer Notes
*   **Library:** `libraries/AC_AttitudeControl` and vehicle main loops.