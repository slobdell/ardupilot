# Precision Landing Configuration (PLND)

## Overview
The **PLND** parameter group configures the **Precision Landing** system. This library uses visual sensors (IR Beacons, AprilTags, or companion computer vision) to land the vehicle on a specific target with centimeter-level accuracy, regardless of GPS drift.

## Key Concepts

### 1. Landing Target Sensors (`PLND_TYPE`)
Defines the hardware used to see the target.
*   **1 (IR Lock):** Uses a specialized IR camera (IRLock) to track a pulsed infrared beacon.
*   **2 (Companion):** Receives target position updates from a companion computer (e.g., Raspberry Pi running OpenMV or AprilTag detection).
*   **3 (SITL):** Simulated landing target.

### 2. Estimator and Filter (`PLND_EST_TYPE`)
Determines how the target's relative position is fused.
*   **0 (Raw):** Direct sensor-to-motor correction (only recommended for simple IR lock).
*   **1 (Kalman Filter):** Fuses vehicle velocity and sensor data to predict target position even if the target is briefly obscured.

### 3. Safety Thresholds
*   **`PLND_XY_DIST_MAX`**: If the target is further away than this, the drone will ignore it and land normally (prevents chasing a false positive).
*   **`PLND_ALT_MAX`**: Maximum altitude to start looking for the target.

## Parameter Breakdown

*   **`PLND_ENABLED`**: Master switch.
*   **`PLND_YAW_ALIGN`**: Rotates the vehicle to match the orientation of the target (if using oriented tags).

## Integration Guide
1.  **Hardware:** Mount the sensor (e.g., IRLock) facing straight down.
2.  **Enable:** Set `PLND_ENABLED = 1` and `PLND_TYPE`.
3.  **Mode:** Set `LAND_TYPE = 1` (Precision) if you want it to trigger every time you switch to Land mode.

## Developer Notes
*   **Library:** `libraries/AC_PrecLand`.
*   **Accuracy:** Typically achieves < 10cm accuracy. Essential for automated charging pads or shipboard landings.