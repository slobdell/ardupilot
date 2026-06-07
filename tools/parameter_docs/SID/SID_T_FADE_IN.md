---
layout: parameter
name: SID_T_FADE_IN
display_name: System identification Fade in time
description: Time to reach maximum amplitude of sweep.
default_value: 15
range: 0 20
units: s
group: SID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_systemid.cpp#L40
---

# SID_T_FADE_IN: System identification Fade in time

## Description
Time to reach maximum amplitude of sweep.

## Values
- **Range:** 0 to 20
- **Units:** s
- **Default:** 15

## Description
This parameter defines the "Ramp-Up" duration at the beginning of the System ID test.

- **Function:** Instead of instantly jumping to full magnitude, the autopilot slowly increases the magnitude of the chirp signal over this time period.
- **Safety:** This gives the pilot time to assess whether the drone is handling the excitation correctly and to abort if the oscillations become too violent.
- **Data Quality:** A longer fade-in ensures that any "startup transients" in the physics don't corrupt the analysis of the steady-state frequency response.

