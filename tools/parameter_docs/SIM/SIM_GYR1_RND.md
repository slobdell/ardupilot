---
layout: parameter
name: SIM_GYR1_RND
display_name: Simulated Gyroscope 1 Noise
description: The amount of noise (in degrees/second) added to the first simulated gyroscope.
default_value: 0
range: 0 10.0
units: deg/s
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1127
---

# Simulated Gyroscope 1 Noise (SIM_GYR1_RND)

## Description
`SIM_GYR1_RND` injects artificial noise into the simulated primary gyroscope.

This is used to test how "twitchy" or unstable the drone's attitude control becomes when the gyro data is imperfect. High noise levels can cause the drone to oscillate or lose orientation entirely.

## The Engineer's View
Adds Gaussian noise (σ) to the body-frame rotational rate:
$$ \omega_{read} = \omega_{true} + \mathcal{N}(0, \text{SIM\_GYR1\_RND}) $$

## Tuning & Behavior
*   **Default Value:** 0
*   **Effect of Increasing:** The drone's attitude (roll/pitch/yaw) will appear to vibrate or "jitter" in the GCS HUD, and the EKF may trigger "high gyro noise" warnings.