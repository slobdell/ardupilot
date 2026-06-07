---
layout: parameter
name: RNGFND1_WSP_AVG
display_name: Wasp-LRF Multi-Pulse Average
description: The number of individual pulses to average for each reported distance measurement.
default_value: 2
range: 0 255
units: 
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Wasp.cpp#L52
---

# Wasp-LRF Multi-Pulse Average (RNGFND1_WSP_AVG)

## Description
`RNGFND1_WSP_AVG` improves the accuracy of the **Wasp-LRF** laser rangefinder.

In this mode, the sensor fires a quick sequence of laser pulses and averages the results before sending a single distance value to the autopilot. This helps filter out "Outliers" or noise caused by dust, rain, or difficult surfaces.

*   **Higher Value:** More accurate, but reduces the effective update frequency.
*   **Lower Value:** Faster updates, but more sensitive to noise.

## Tuning & Behavior
*   **Default:** 2.
*   **Recommendation:** Leave at **2** for general flight. Increase to **5** or **10** if you are performing slow-speed precision tasks (like automatic docking) where accuracy is more important than speed.
*   **Dependency:** Only active if [RNGFND1_TYPE](RNGFND1_TYPE.html) is set to 18 (WASP-LRF).