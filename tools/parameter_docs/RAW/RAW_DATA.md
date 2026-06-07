---
layout: parameter
name: RAW_DATA
display_name: Raw data logging
description: Handles logging raw data; on uBlox chips that support raw data this will log RXM messages into logger; on Septentrio this will log on the equipment's SD card and when set to 2, the autopilot will try to stop logging after disarming and restart after arming.
default_value: 0
range: 0 5
units: 
group: RAW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/AP_GPS.cpp#L190
---

# RAW_DATA: Raw data logging

## Description
This parameter enables the logging of raw GNSS satellite observations from the GPS module to the autopilot's DataFlash logs.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Ignore (Disabled) |
| 1 | Always log |
| 2 | Stop logging when disarmed (SBF/Septentrio only) |
| 5 | Only log every five samples (u-blox only) |

- **Default:** 0

## Description
This parameter is essential for **PPK (Post-Processing Kinematics)**. 

- **How it works:** Instead of just logging the calculated position, it logs the raw "carrier phase" and "pseudorange" data from the satellites. 
- **Usage:** After a flight, you can use software like RTKLIB or Emlid Studio to process this raw log against a base station log to achieve centimeter-level accuracy for photo geotagging or survey paths.
- **Warning:** Enabling this generates much larger log files and increases CPU load. Use a high-speed SD card.

## Source Code
[ardupilot/libraries/AP_GPS/AP_GPS.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/AP_GPS.cpp#L190)

