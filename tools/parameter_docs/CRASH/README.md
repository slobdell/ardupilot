# Crash Detection (CRASH)

## Overview
The **CRASH** parameter group configures the automatic **Crash Detection** logic. This safety feature is designed to rapidly identify when the vehicle has impacted the ground or an obstacle and is no longer under control.

Upon detection, the system immediately **Disarms the Motors** to:
1.  Prevent fire (stalled motors overheat ESCs).
2.  Prevent injury to bystanders.
3.  Minimize damage to the airframe and props.

## Key Concepts

### 1. Detection Logic
Different vehicles use different logic:
*   **Plane:** Looks for sudden X-axis deceleration (impact) while flying (`CRASH_ACC_THRESH`).
*   **Copter:** Looks for a sustained error between Target Angle and Actual Angle (loss of control) combined with low throttle usage.

### 2. Check Logic (`CRASH_DETECT`)
(Note: Often `CRASH_ACC_THRESH` or `FS_CRASH_CHECK`).
*   If enabled, the code runs in the fast loop to monitor IMU spikes.

## Parameter Breakdown

*   **`CRASH_ACC_THRESH`**: (Plane) Impact force threshold (m/s/s). 0 to disable.
*   **`CRASH_DETECT`**: (Some firmwares) Bitmask options.

## Integration Guide
*   **False Positives:** If you hand-launch or use a bungee, ensure `CRASH_ACC_THRESH` is high enough not to trigger on release.
*   **Rough Landings:** If the plane disarms the moment it touches down (but bounces), you might need to relax the threshold or improve the landing flare logic.

## Developer Notes
*   **Library:** Vehicle specific (`ArduPlane/crash_check.cpp`).
*   **Safety:** This is a critical safety feature for large/heavy drones.