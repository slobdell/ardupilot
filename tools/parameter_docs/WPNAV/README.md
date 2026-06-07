# Waypoint Navigation Configuration (WPNAV)

## Overview
The **WPNAV** parameter group provides the low-level **Path Planning** and **Speed** settings for **ArduCopter** autonomous flight (Auto, Guided, RTL).

While the `PSC` group handles PID control, the `WPNAV` group defines the "Target Velocity" and "Acceleration" profiles that the drone follows between points.

## Key Concepts

### 1. Speed Control (`WPNAV_SPEED` / `DN` / `UP`)
*   **`WPNAV_SPEED`**: Maximum horizontal cruising speed (cm/s).
*   **`WPNAV_SPEED_UP`**: Maximum climb rate (cm/s).
*   **`WPNAV_SPEED_DN`**: Maximum descent rate (cm/s).

### 2. Cornering (`WPNAV_RADIUS`)
Similar to `WP_RADIUS`, this defines the acceptance circle for waypoints.
*   **Spline Turns:** In newer versions, the drone uses "Spline" paths to fly through waypoints smoothly without stopping.

### 3. Acceleration (`WPNAV_ACCEL` / `Z`)
Defines how fast the drone can speed up or slow down.
*   **Smoothness:** Lower values make for a more graceful, cinematic flight.

## Integration Guide
*   **Efficiency:** For long-range mapping, increase `WPNAV_SPEED` to the airframe's most efficient cruise speed.
*   **Safety:** Ensure `WPNAV_SPEED_DN` is not set higher than the drone's stable descent capability (to prevent "Wobble of Death").

## Developer Notes
*   **Library:** `libraries/AC_WPNav`.