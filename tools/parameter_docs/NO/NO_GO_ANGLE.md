---
layout: parameter
title: NO_GO_ANGLE
name: Sailing no go zone angle
group: NO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.cpp#L76
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.h#L106
---

# NO_GO_ANGLE: Sailing no go zone angle

## Description
The typical closest angle to the wind the vehicle will sail at. The vehicle will sail at this angle when going upwind.

## Values
- **Range:** 0 to 90
- **Units:** deg
- **Increment:** 1
- **Default:** 45

## Description
This parameter defines the "dead zone" into the wind where a sailboat cannot generate forward thrust.

- **Function:** When the autopilot needs to go to a waypoint that lies within this angle of the wind, it will tack (zig-zag) back and forth at this angle instead of trying to sail straight into the wind.
- **Tuning:**
    - **Performance Boats:** Can often sail closer to the wind (e.g., 35-40 degrees).
    - **Cruisers/Inefficient Rigs:** May need a wider angle (e.g., 50-60 degrees) to maintain speed.

## Source Code
[ardupilot/Rover/sailboat.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/sailboat.cpp#L76)
