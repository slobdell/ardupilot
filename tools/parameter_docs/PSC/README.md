# Position Controller Configuration (PSC)

## Overview
The **PSC** parameter group contains the **PID Tuning** parameters for the **Position Controller**. This library is the "brains" of the navigation system for multicopters and blimps.

While the `ATC` group handles how the drone rotates (Attitude), the `PSC` group handles how it moves through 3D space (Position and Velocity). It translates a waypoint target into the specific tilt angles and throttle levels needed to get there.

## Key Concepts: The Cascaded Loop

Like attitude control, position control uses a cascaded structure:

### 1. Position Loop (Outer)
*   **Input:** Target Position (Lat/Lon/Alt) vs. Actual Position.
*   **Output:** Target Velocity (m/s).
*   **Parameters:** `PSC_POSXY_P`, `PSC_POSZ_P`.

### 2. Velocity Loop (Middle)
*   **Input:** Target Velocity vs. Actual Velocity (from EKF).
*   **Output:** Target Acceleration (m/s²).
*   **Parameters:** `PSC_VELXY_P/I/D`, `PSC_VELZ_P/I/D`.

### 3. Acceleration Loop (Inner)
*   **Input:** Target Acceleration vs. Actual Acceleration (from IMU).
*   **Output:** Desired Lean Angle (to `ATC`) and Throttle level.
*   **Parameters:** `PSC_ACCZ_P/I/D` (specifically for vertical control).

## Key Parameters

*   **`PSC_POSXY_P`**: How aggressively the drone tries to close a horizontal position gap.
*   **`PSC_VELXY_P`**: Horizontal velocity responsiveness.
*   **`PSC_ACCZ_P/I/D`**: Vertical acceleration tuning. Critical for stable hover and smooth altitude changes.
*   **`PSC_JERK_XY`**: Smoothness of horizontal transitions (m/s/s/s).

## Integration Guide

### Tuning Altitude Hold
1.  If the drone "bounces" or "hunts" vertically while trying to hold altitude, your `PSC_ACCZ_` gains are likely too high.
2.  If it feels "sloppy" and drops significantly when moving forward, increase `PSC_ACCZ_I` and `PSC_POSZ_P`.

### Tuning Loiter
1.  If the drone overshoots its target and circles back (toilet-bowling), first check the compass. If compass is perfect, then reduce `PSC_POSXY_P`.

## Developer Notes
*   **Library:** `libraries/AC_PosControl`.
*   **Coordinates:** Uses the NED (North-East-Down) frame for all internal calculations.