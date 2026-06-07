---
layout: parameter
name: YAW_CORR
display_name: Yaw Correction Gain
description: The gain used to correct heading errors between the IMU and the compass/GPS.
default_value: 0.1
range: 0 1.0
units: 
group: YAW
visual_asset_id: yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_AHRS/AP_AHRS.cpp#L100
---

# Yaw Correction Gain (YAW_CORR)

## Description
`YAW_CORR` defines how much the autopilot trusts the compass or GPS heading compared to its internal motion sensors (IMU).

Over time, the IMU "Drifts" and loses track of true North. The autopilot uses the compass (or GPS ground track) to "Pull" the IMU back into alignment.

*   **Higher Value:** Faster alignment to the compass, but more susceptible to compass glitches (e.g. flying near large metal structures).
*   **Lower Value:** Smoother heading, but more prone to long-term drift.