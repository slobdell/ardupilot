---
layout: parameter
name: PUP_PITCH_START
display_name: Pullup target pitch
description: Target pitch for initial pullup.
default_value: -60
range: -80 0
units: deg
group: PUP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/pullup.cpp#L62
---

# PUP_PITCH_START: Pullup target pitch

## Description
Target pitch for initial pullup.

## Values
- **Range:** -80 to 0
- **Units:** deg
- **Default:** -60

## Description
This parameter defines the **Pitch Angle Trigger** for the pull-up maneuver.

- **Function:** After the altitude wait finishes (e.g., balloon burst), the autopilot assumes the vehicle is tumbling or diving vertically. It waits for the nose to stabilize at this pitch angle (e.g., -60 degrees, nose down) before initiating the high-G pull-up.
- **Purpose:** Ensures the aircraft has gained sufficient airspeed and aerodynamic authority before attempting to pull out of the dive.

