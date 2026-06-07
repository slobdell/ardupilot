# Visual Odometry Configuration (VISO)

## Overview
The **VISO** parameter group configures the **Visual Odometry** (External Navigation) subsystem. This allows ArduPilot to use position and velocity data from an external camera-based system (like Intel RealSense or an OptiTrack mo-cap system) for navigation.

Visual Odometry is the primary method for high-performance non-GPS autonomous flight.

## Key Concepts

### 1. Vision Types (`VISO_TYPE`)
*   **1 (MAVLink):** Receives `VISION_POSITION_ESTIMATE` or `ODOMETRY` MAVLink messages from a companion computer.
*   **2 (Intel RealSense):** Specialized driver for RealSense devices.

### 2. Offsets and Orientation
*   **`VISO_POS_X/Y/Z`**: The physical distance from the camera lens to the vehicle's center of gravity.
*   **`VISO_ORIENT`**: The rotation of the camera relative to the flight controller.

## Parameter Breakdown

*   **`VISO_ENABLE`**: Master switch.
*   **`VISO_DELAY_MS`**: Time lag of the vision system (crucial for EKF synchronization).
*   **`VISO_QUAL_MIN`**: Minimum confidence threshold for the vision solution.

## Integration Guide
1.  **Preparation:** Requires an H7 processor and a high-speed telemetry link (921k baud).
2.  **Config:** Set `VISO_TYPE = 1`.
3.  **EKF Source:** Set `EK3_SRC1_POSXY = 6` (External Nav).
4.  **Verify:** Check the GCS map. The drone's position should move accurately as you walk it around a room.

## Developer Notes
*   **Library:** `libraries/AP_VisualOdom`.
*   **Messages:** Primarily consumes the `MAVLINK_MSG_ID_ODOMETRY` message.