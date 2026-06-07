# Extended Kalman Filter 3 (EK3)

## Overview
The **EK3** parameter group configures the **Modern EKF3** state estimator. This is the default and recommended navigation filter for all modern ArduPilot vehicles.

EKF3 differs from EKF2 by offering **Source Switching** ("Lane Switching"). It can seamlessly transition between different navigation sources in flight (e.g., GPS outdoors -> Optical Flow indoors -> Beacon) based on pilot switches or signal health.

## Key Concepts

### 1. Source Switching (`EK3_SRCn_...`)
You can define up to 3 sets of sensor configurations ("Sources").
*   **`EK3_SRC1_POSXY`**: Horizontal Position Source (GPS, Flow, Beacon, None).
*   **`EK3_SRC1_VELXY`**: Horizontal Velocity Source.
*   **`EK3_SRC1_POSZ`**: Vertical Position Source (Baro, Rangefinder, GPS).
*   **`EK3_SRC1_YAW`**: Heading Source (Compass, GPS Moving Baseline, External).

The pilot can switch between SRC1, SRC2, and SRC3 using an RC channel (`RCx_OPTION = 90`).

### 2. Multi-Core Affinity (`EK3_AFFINITY`)
On H7 processors, EKF3 can run multiple "Lanes" (Instances) on different IMUs simultaneously. `EK3_AFFINITY` controls which IMU is assigned to which EKF lane to maximize redundancy.

### 3. Visual Odometry / GPS Denied
EKF3 is the engine that makes non-GPS flight possible.
*   **Optical Flow:** `EK3_SRCx_POSXY = 0`, `VELXY = 5` (Optical Flow).
*   **Visual Odometry:** `EK3_SRCx_POSXY = 6` (External Nav).

## Parameter Breakdown

*   **`EK3_ENABLE`**: Master switch.
*   **`EK3_PRIMARY`**: Which lane is currently driving the vehicle (Read-only status mostly).
*   **`EK3_MAG_CAL`**: In-flight mag calibration options.
*   **`EK3_FLOW_DELAY`**: Time lag for optical flow sensor.

## Integration Guide

### Setting up GPS + Optical Flow Backup
1.  **Source 1 (GPS):** `EK3_SRC1_POSXY = 3` (GPS), `VELXY = 3` (GPS), `POSZ = 1` (Baro).
2.  **Source 2 (Flow):** `EK3_SRC2_POSXY = 0` (None), `VELXY = 5` (OptFlow), `POSZ = 2` (Rangefinder).
3.  **Switching:** Assign RC6 to `EKF Pos Source`.
    *   Low PWM = Source 1 (GPS).
    *   Mid PWM = Source 2 (Flow).

## Developer Notes
*   **Library:** `libraries/AP_NavEKF3`
*   **States:** 24-state filter.
*   **Complexity:** EKF3 is significantly more complex to tune than EKF2 but offers far greater capability.