---
layout: parameter
name: WNDSPD_MIN
display_name: Sailboat minimum wind speed to sail in
description: Sailboat minimum wind speed to continue sail in, at lower wind speeds the sailboat will motor if one is fitted.
default_value: 0
range: 0 5
units: m/s
group: WNDSPD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.cpp#L85
---

# WNDSPD_MIN: Sailboat minimum wind speed to sail in

## Description
Sailboat minimum wind speed to continue sail in, at lower wind speeds the sailboat will motor if one is fitted.

## Values
- **Range:** 0 to 5
- **Units:** m/s
- **Default:** 0

## Description
This parameter sets the threshold for **Hybrid Sailing**.

- **Function:** If the wind drops below this speed, the autopilot assumes sailing is ineffective and will start the motor (if equipped) to maintain progress towards the waypoint.
- **Use Case:** Cruising or long-endurance missions where you want to sail as much as possible but need to ensure you don't get becalmed.
