---
layout: parameter
name: RNGFND_FILT
display_name: Rangefinder Low-Pass Filter
description: Cut-off frequency for smoothing the rangefinder distance data.
default_value: 0.5
range: 0 5
units: Hz
group: RNGFND
visual_asset_id: rngfnd_range_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L1018
---

# Rangefinder Low-Pass Filter (RNGFND_FILT)

## Description
`RNGFND_FILT` smooths the "Jitter" from your distance sensor. 

Many rangefinders (especially ultrasonic or low-cost Lidars) produce noisy data that can bounce around by several centimeters even when the drone is stationary. This filter removes that high-frequency noise to provide a stable altitude for the flight controller.

*   **Higher Frequency:** More responsive to rapid terrain changes, but more "jittery" altitude hold.
*   **Lower Frequency:** Very smooth altitude, but the drone might react slowly to a sudden obstacle or drop in terrain.

## Tuning & Behavior
*   **Default:** 0.5 Hz.
*   **Recommendation:** Leave at **0.5 Hz** for most sensors. If your drone is "bobbing" up and down rapidly while using the rangefinder, try lowering this to **0.25 Hz**.
*   **Disabled:** Setting this to **0** disables the filter (raw data is used directly).