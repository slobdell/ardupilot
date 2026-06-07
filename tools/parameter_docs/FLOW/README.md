# Optical Flow Configuration (FLOW)

## Overview
The **FLOW** parameter group configures the **Optical Flow Sensor**. This sensor uses a tiny high-speed camera and an image processor to track the movement of "features" (textures) on the ground. By measuring this "visual flow," the autopilot can estimate the vehicle's horizontal velocity.

Optical flow is the primary method for position hold in GPS-denied environments (Indoors, under tree canopies).

## Key Concepts

### 1. Scaling (`FLOW_FXSCALER` / `FLOW_FYSCALER`)
The raw output of the flow sensor must be scaled based on the lens focal length and mounting height to convert "pixels per second" into "meters per second."

### 2. Height Requirement
Optical flow requires an accurate measurement of height above ground to calculate velocity correctly.
*   **Rangefinder:** A Lidar or Ultrasonic sensor is almost always required alongside an Optical Flow sensor.

### 3. Orientation (`FLOW_ORIENT_YAW`)
The autopilot needs to know which way the flow camera is rotated relative to the flight controller to ensure the "Flow X" aligns with "Vehicle X."

## Parameter Breakdown

*   **`FLOW_TYPE`**: Driver selection (0=Disabled, 1=PX4Flow, 2=DroneCAN, 5=CX-OF, etc.).
*   **`FLOW_ADDR`**: I2C address of the sensor.
*   **`FLOW_POS_X/Y/Z`**: Offset of the sensor relative to the vehicle's center of gravity (for lever-arm compensation).

## Integration Guide
1.  **Hardware:** Mount the sensor facing straight down. Ensure good lighting.
2.  **Enable:** Set `FLOW_TYPE` and `EK3_SRC1_VELXY = 5` (Optical Flow).
3.  **Calibrate:** Perform a "Handheld Calibration" (see Wiki) to ensure the flow and gyro data are perfectly synced.
4.  **Test:** Hover in Loiter mode. The vehicle should stay stationary without GPS.

## Developer Notes
*   **Library:** `libraries/AP_OpticalFlow`.
*   **Accuracy:** Accuracy degrades with height. Most sensors are effective up to 10-20 meters AGL.
*   **Surface Texture:** Flow will fail over perfectly uniform surfaces like smooth water or solid-color tiles.