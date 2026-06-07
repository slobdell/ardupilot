# Rangefinder Configuration (RNGFND)

## Overview
The **RNGFND** parameter group configures the **Rangefinder** (Lidar, Ultrasonic, or Radar) subsystem. Rangefinders provide precise altitude data (distance to ground) or obstacle distance.

ArduPilot supports up to 10 simultaneous rangefinder instances, which can be oriented in any direction (Down, Forward, Up, etc.).

## Key Concepts

### 1. Distance Sensing Types (`RNGFNDn_TYPE`)
Defines the hardware protocol.
*   **1 (Analog):** Old ultrasonic sensors.
*   **2 (MaxbotixI2C):** I2C Ultrasonic.
*   **4 (LightWareI2C):** High-end Lidar.
*   **15 (MAVLink):** Distance data from a companion computer or separate MAVLink device.
*   **24 (DroneCAN):** CAN-based sensors (e.g., HereFlow, Benewake CAN).

### 2. Orientation (`RNGFNDn_ORIENT`)
Determines which direction the sensor is pointing.
*   **25 (Down):** Used for precision landing, terrain following, and automated takeoff/landing.
*   **0 (Forward):** Used for simple obstacle avoidance.
*   **6 (Up):** Used for ceiling avoidance or indoor altitude hold.

### 3. Scaling and Offsets
*   **`RNGFNDn_SCALING`**: Multiplier for analog sensors.
*   **`RNGFNDn_OFFSET`**: Physical distance (meters) between the sensor and the zero-point of the vehicle.
*   **`RNGFND_GNDCLEAR`**: (Down only) The distance from the sensor to the ground when the vehicle is physically resting on its landing gear. **Critical for proper landing detection.**

## Parameter Breakdown

*   **`RNGFNDn_MIN / MAX`**: The valid operating range of the sensor (centimeters). Values outside this range are ignored by the EKF.
*   **`RNGFND_FILT`**: Cutoff frequency for the rangefinder data filter (Hz).

## Integration Guide

### Setting up a Downward Lidar
1.  **Mount:** Face the sensor straight down with a clear view of the ground.
2.  **Enable:** Set `RNGFND1_TYPE` to your sensor model.
3.  **Orient:** Set `RNGFND1_ORIENT = 25`.
4.  **Measure:** Measure the distance to the ground while landed and set `RNGFND_GNDCLEAR`.
5.  **Verify:** Check the `sonar_range` or `rngfnd1` value in the GCS. It should read correctly as you lift the drone.

## Developer Notes
*   **Library:** `libraries/AP_RangeFinder`.
*   **Usage:** Fused by `AP_NavEKF3` to improve vertical position accuracy and for "Terrain Following" mission logic.