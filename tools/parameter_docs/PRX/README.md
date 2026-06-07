# Proximity Sensor Configuration (PRX)

## Overview
The **PRX** parameter group configures the **Proximity Sensors** used for obstacle detection and avoidance. This library supports 360-degree scanners (Lidar), simple rangefinders used as proximity sensors, and virtual proximity data from companion computers.

The data from these sensors is fed into the **AVOID** and **OA** (Object Avoidance) libraries to prevent collisions.

## Key Concepts

### 1. Sensor Types (`PRXn_TYPE`)
ArduPilot supports up to 5 proximity sensor instances.
*   **1 (LightWareSF40):** 360-degree scanning Lidar.
*   **2 (RPLidarA2/A3):** Popular scanning Lidars.
*   **4 (DroneCAN):** CAN-based proximity sensors.
*   **15 (RangeFinder):** Converts a standard downward or forward-facing Lidar (`RNGFND_`) into a proximity source.

### 2. Ignore Zones (`PRXn_IGN_...`)
Often, the drone's own frame, landing gear, or antennas might block the sensor's field of view, causing false obstacle detections.
*   **`PRXn_IGN_ANG`**: The center angle of the zone to ignore.
*   **`PRXn_IGN_WID`**: The width (degrees) of the zone to ignore.

### 3. Vertical Limits (`PRX_ALT_MIN`)
Defines the minimum altitude required for the sensors to be active, preventing the ground from being seen as an obstacle during takeoff.

## Parameter Breakdown

*   **`PRX1_TYPE`**: Driver selection for first sensor.
*   **`PRX1_MAX`**: Maximum effective range (meters).
*   **`PRX_FILT`**: Low-pass filter for proximity data (Hz).

## Integration Guide
1.  **Hardware:** Mount the Lidar on top or bottom with a clear 360-degree view.
2.  **Enable:** Set `PRX1_TYPE`.
3.  **Clean View:** Look at the "Proximity" window in Mission Planner. If you see "phantom" obstacles that move with the drone, use `IGN_ANG` to mask out the propeller arms or frame.

## Developer Notes
*   **Library:** `libraries/AP_Proximity`.
*   **Output:** Generates the "Proximity" MAVLink message and logs to the `PRX` dataflash message.