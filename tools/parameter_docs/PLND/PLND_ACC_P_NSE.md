---
layout: parameter
name: PLND_ACC_P_NSE
display_name: Kalman Filter Accelerometer Noise
description: The expected noise level for the accelerometers within the precision landing estimator. Higher values trust the landing sensor more than the drone's own inertia.
default_value: 2.5
range: 0.5 5.0
units: 
group: PLND
visual_asset_id: precland_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L78
---

# Kalman Filter Accelerometer Noise (PLND_ACC_P_NSE)

## Description
`PLND_ACC_P_NSE` defines the "Trust Balance" for the precision landing system. 

When the drone is landing on a target, it uses two pieces of information:
1.  **The Sensor:** Where the camera/IR sensor sees the target right now.
2.  **The IMU:** Where the drone thinks it has moved based on its internal accelerometers.

*   **Higher Value:** The drone assumes the IMU is noisy. It will react faster to new data from the landing sensor. Good for high-vibration drones.
*   **Lower Value:** The drone trusts its IMU more. It will ignore small jitters in the landing sensor and move more smoothly.

## The Engineer's View
This parameter sets the process noise covariance ($Q$) for the internal precision landing Kalman filter. It specifically weights the accelerometer inputs against the measurement updates from the vision system.

## Tuning & Behavior
*   **Default Value:** 2.5.
*   **Oscillations:** If the drone "Twitches" or over-corrects as it approaches the landing pad, decrease this value to **1.5**.
*   **Lag:** If the drone is slow to react to target movements, increase to **3.5**.