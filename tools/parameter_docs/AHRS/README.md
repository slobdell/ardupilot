# Attitude Heading Reference System (AHRS)

## Overview
The **AHRS** (Attitude Heading Reference System) parameters control the fundamental orientation logic of the autopilot. This library is responsible for determining "Which way is Up" and "Which way is North."

While the modern **Extended Kalman Filter (EKF)** does the heavy lifting for state estimation, the AHRS library manages:
1.  **Board Orientation:** Telling the software how the flight controller is mounted relative to the vehicle frame.
2.  **Estimator Selection:** Choosing between EKF2, EKF3, or the legacy DCM (Direction Cosine Matrix) filter.
3.  **Fallback Logic:** Providing a backup attitude solution if the EKF fails or diverges.

## Key Concepts

### 1. Board Orientation (`AHRS_ORIENTATION`)
**This is the most critical parameter in setup.** If this is wrong, the vehicle will flip over instantly on takeoff.
*   It defines the rotation of the flight controller board relative to the vehicle's forward direction.
*   **Example:** If the USB port points to the right wing, you likely need `YAW_90`.

### 2. Estimator Type (`AHRS_EKF_TYPE`)
ArduPilot supports multiple estimator backends.
*   **0:** Disabled (DCM only). Not recommended for modern GPS flight.
*   **2:** EKF2 (Legacy, 22-state). Stable, widely used in older versions.
*   **3:** EKF3 (Modern, 24-state). Supports newer features like Moving Baseline Yaw, Optical Flow, and Visual Odometry. **Default for 4.1+.**

### 3. Custom Rotations
If standard 90-degree increments are insufficient (e.g., mounting on a 45-degree arm), the `AHRS_CUSTOM_ROLL`, `PITCH`, and `YAW` parameters (or `CUSTOM_ORIENTATION` group) allow for precise alignment.

## Parameter Breakdown

*   **`AHRS_ORIENTATION`**: Board rotation enum (0=None, 2=Yaw90, 8=Roll180, etc.).
*   **`AHRS_EKF_TYPE`**: Active state estimator selector.
*   **`AHRS_GPS_USE`**: Determines if the legacy DCM filter is allowed to use GPS for correction.
*   **`AHRS_TRIM_X` / `Y`**: (Radians) Internal trim states for level horizon. Usually set via "Calibrate Level".

## Integration Guide

### Setting Orientation
1.  **Check Arrow:** Look for the arrow on your flight controller case.
2.  **Mount:** Secure the board.
3.  **Configure:** If the arrow points Forward, `AHRS_ORIENTATION = 0`. If Right, `AHRS_ORIENTATION = 2` (Yaw 90).
4.  **Verify:** Open the HUD in your GCS. Tilt the vehicle nose DOWN. The HUD horizon should move UP. Tilt Right, HUD moves Left. **If it moves incorrectly, your orientation is wrong.**

## Developer Notes
*   **Library:** `libraries/AP_AHRS`
*   **Classes:** `AP_AHRS_DCM`, `AP_AHRS_NavEKF`.
*   **Redundancy:** The AHRS library often runs the DCM filter in the background as a "sanity check" for the EKF. If the EKF "blows up" (diverges), the system may failover to the DCM (Msg: "EKF Fail, switching to DCM").