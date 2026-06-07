---
layout: parameter
name: RNGFND_SQ_MIN
display_name: Rangefinder Minimum Signal Quality
description: The minimum signal quality (0-100%) required to trust the distance data.
default_value: 0
range: 0 100
units: %
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Rangefinder Minimum Signal Quality (RNGFND_SQ_MIN)

## Description
`RNGFND_SQ_MIN` defines the "Certainty Threshold" for your distance measurements. 

Many sensors (especially acoustics/sonars used in **ArduSub**) report a confidence level or signal quality. If the return signal is weak (due to bubbles, silt, or extreme angles), the sensor may report a "Confidence" percentage. This parameter tells the autopilot to reject any measurement if the sensor's own confidence is below this value.

*   **0:** Trust all data (Default).
*   **50:** Reject data if the sensor is less than 50% certain.

## Tuning & Behavior
*   **Recommendation:** Set to **50%** if you find your depth or altitude readings "glitching" in difficult environments.
*   **Context:** This is functionally similar to [RNGFND1_SNR_MIN](RNGFND1_SNR_MIN.html) but uses a normalized percentage (0-100) instead of a raw SNR value.