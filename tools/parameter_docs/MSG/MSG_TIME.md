---
layout: parameter
title: MSG_TIME
name: Message display duration in seconds
group: MSG
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L148
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.h#L588
---

# MSG_TIME: Message display duration in seconds

## Description
Sets the duration (in seconds) that temporary status messages and warnings remain visible on the OSD.

## Values
- **Range:** 1 to 20
- **Units:** s
- **Default:** 10
- **Increment:** 1

## Description
This parameter controls the persistence of "pop-up" messages on the On-Screen Display.

- **Examples:** Flight mode changes ("STABILIZE"), Arm/Disarm notifications, Battery warnings ("LOW BATT"), and GCS text messages.
- **Tuning:**
    - **Too Short:** You might miss important warnings while flying.
    - **Too Long:** The message might obscure other critical flight data (like the horizon or battery voltage) for an annoying amount of time.

## Source Code
[ardupilot/libraries/AP_OSD/AP_OSD.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L148)

