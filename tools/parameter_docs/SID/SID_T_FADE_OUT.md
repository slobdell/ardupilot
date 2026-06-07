---
layout: parameter
name: SID_T_FADE_OUT
display_name: System identification Fade out time
description: Time to reach zero amplitude at the end of the sweep.
default_value: 2
range: 0 5
units: s
group: SID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_systemid.cpp#L48
---

# SID_T_FADE_OUT: System identification Fade out time

## Description
Time to reach zero amplitude at the end of the sweep.

## Values
- **Range:** 0 to 5
- **Units:** s
- **Default:** 2

## Description
This parameter defines the "Cool-Down" duration at the end of the System ID test.

- **Function:** After the chirp finishes its frequency sweep, the autopilot slowly reduces the magnitude to zero over this time period.
- **Purpose:** Prevents a sudden, jerky stop of the aircraft's motion, which could destabilize it or cause stress on the frame. It ensures a smooth transition back to the pilot's manual control or the original flight mode's behavior.

