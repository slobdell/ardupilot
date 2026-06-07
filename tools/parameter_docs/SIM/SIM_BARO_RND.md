---
layout: parameter
name: SIM_BARO_RND
display_name: Simulated Barometer Noise
description: The amount of noise (in Pascals) added to the simulated primary barometer.
default_value: 0.2
range: 0 10.0
units: Pa
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L190
---

# Simulated Barometer Noise (SIM_BARO_RND)

## Description
`SIM_BARO_RND` simulates atmospheric pressure noise. Since ArduPilot uses the barometer for altitude, this noise directly affects how "bouncy" the altitude hold is in flight.

## The Engineer's View
Adds Gaussian noise to the simulated pressure reading. Because 1 Pascal is roughly 8cm of altitude at sea level, a noise value of 0.2 represents about 1.6cm of altitude jitter.

## Tuning & Behavior
*   **Default Value:** 0.2 Pa
*   **Effect of Increasing:** The drone will struggle to maintain a precise altitude, and the climb rate estimate will become noisier.