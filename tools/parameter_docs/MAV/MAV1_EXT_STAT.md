---
layout: parameter
name: MAV1_EXT_STAT
display_name: MAVLink Extended Status Stream Rate
description: The frequency (in Hz) for streaming system health, power, and GPS status messages.
default_value: 1
range: 0 50
units: Hz
group: MAV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/GCS_Mavlink.cpp
---

# MAVLink Extended Status Stream Rate (MAV1_EXT_STAT)

## Description
`MAV1_EXT_STAT` determines how often the drone reports its "Vital Signs" to the Ground Control Station.

This parameter covers a large group of essential status messages, including:
*   **SYS_STATUS:** Battery voltage, current, and sensor health.
*   **GPS_RAW_INT:** Number of satellites, HDOP, and fix type.
*   **MEMINFO:** CPU load and free memory.
*   **NAV_CONTROLLER_OUTPUT:** Target vs. actual headings and altitude.

## Tuning & Behavior
*   **Default:** 1 Hz.
*   **Recommendation:** Set to **2 or 5 Hz** for a more responsive GCS dashboard. 
*   **Note:** This is one of the most important stream rates for pilot situational awareness. If it is too low, your battery and GPS readings will look "stuck" or update very infrequently.