---
layout: parameter
name: PRX_FILT
display_name: Proximity Data Low-Pass Filter
description: Cutoff frequency for the filter that smooths obstacle detection data.
default_value: 0.25
range: 0 20
units: Hz
group: PRX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity.cpp#L69
---

# Proximity Data Low-Pass Filter (PRX_FILT)

## Description
`PRX_FILT` smooths out the "noisy" data from proximity sensors (like Lidars). 

Lidars often report small, random fluctuations in distance. Without filtering, these fluctuations can cause the drone to twitch or make small steering corrections even when stationary. This filter removes that high-frequency noise, providing a stable "Boundary" for the obstacle avoidance algorithm to work with.

*   **Higher Frequency:** Faster reaction to obstacles, but more twitchy.
*   **Lower Frequency (Default):** Very smooth movement, but may react slightly slower to a fast-moving object.

## Tuning & Behavior
*   **Default:** 0.25 Hz.
*   **Recommendation:** Leave at **0.25 Hz** for most setups. If you find your drone is too slow to stop for obstacles, try increasing to **1.0 Hz**.