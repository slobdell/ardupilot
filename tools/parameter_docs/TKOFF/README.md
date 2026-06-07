# Takeoff Configuration (TKOFF)

## Overview
The **TKOFF** parameter group configures the **Autonomous Takeoff** sequence for ArduPlane and QuadPlane.

Automating the takeoff ensures a consistent climb-out and prevents pilot errors during the most vulnerable stage of flight.

## Key Concepts

### 1. Launch Acceleration (`TKOFF_THR_MINACC`)
(Plane) For hand-launched or bungee-launched planes, the motor shouldn't start until the plane is physically thrown.
*   **Threshold:** The motor starts only after the IMU detects an acceleration spike (m/s²) exceeding this value.

### 2. Takeoff Pitch (`TKOFF_LVL_PITCH`)
The target pitch angle during the initial climb-out.
*   **Recommendation:** Usually 10-15 degrees for most airframes.

### 3. Transition Altitude (`TKOFF_ALT`)
The height at which the takeoff sequence is considered "Complete," and the autopilot switches to the first mission waypoint or its standard navigation logic.

## Parameter Breakdown

*   **`TKOFF_THR_MAX`**: Maximum throttle allowed during takeoff.
*   **`TKOFF_DIST`**: (Rover/Plane) Distance from home to consider the takeoff complete.
*   **`TKOFF_FLAP_PCNT`**: Percentage of flaps to deploy during takeoff.

## Integration Guide
*   **Hand Launch:** Set `TKOFF_THR_MINACC = 15` and `TKOFF_THR_DELAY = 2` (0.2s) to ensure the motor doesn't bite your hand as you throw.

## Developer Notes
*   **Library:** `ArduPlane/mode_takeoff.cpp`.