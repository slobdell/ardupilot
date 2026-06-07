# Sensor Orientation Configuration (ORIENT)

## Overview
The **ORIENT** parameter group (specifically `ORIENT_YAW` or `FLOW_ORIENT_YAW`) defines the mechanical rotation of auxiliary sensors relative to the flight controller.

## Key Concepts

### 1. Yaw Alignment
When mounting a sensor like an **Optical Flow** camera or a **Lidar**, the chip's internal X/Y axes must be aligned with the vehicle's Forward/Right axes.
*   **`ORIENT_YAW`**: The rotation (in degrees) of the sensor around its vertical axis.
    *   **0:** Sensor "Forward" points with the vehicle "Forward."
    *   **90:** Sensor is rotated 90 degrees to the right.

## Developer Notes
*   **Library:** `libraries/AP_OpticalFlow`, `libraries/AP_RangeFinder`.
*   **Criticality:** If this is wrong, the vehicle will attempt to correct horizontal drift in the wrong direction, leading to a "fly-away" or crash in Loiter modes.