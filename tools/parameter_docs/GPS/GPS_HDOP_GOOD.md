---
layout: parameter
name: GPS_HDOP_GOOD
display_name: GPS HDOP Threshold (Good Fix)
description: The maximum allowed HDOP for the GPS position to be considered "Good" during pre-arm checks.
default_value: 140
range: 100 900
units: 
group: GPS
visual_asset_id: gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# GPS HDOP Threshold (GPS_HDOP_GOOD)

## Description
`GPS_HDOP_GOOD` sets the "Trust Limit" for your GPS during pre-arm safety checks. 

HDOP (Horizontal Dilution of Precision) is a measure of GPS geometric accuracy. A lower number is better. If your GPS reports an HDOP higher than this value, the autopilot will prevent you from arming in autonomous modes (like Loiter, PosHold, or Auto) because the position data is too imprecise.

*   **100:** Extremely strict (Excellent signal required).
*   **140 (Default):** Standard for most users.
*   **200+:** Relaxed (Allows arming with poorer signals, risky).

## Tuning & Behavior
*   **Default:** 140 (reported as 1.4 in some GCS).
*   **Safety:** Do not increase this value unless you have a very specific reason to fly in an area with poor sky visibility (e.g. narrow canyons). High HDOP can lead to "GPS Glitches" where the drone suddenly jumps several meters.