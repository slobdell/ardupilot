---
layout: parameter
title: ROLL_MIN
name: Mount Roll angle minimum
group: ROLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Mount/AP_Mount_Params.cpp#L41
---

# ROLL_MIN: Mount Roll angle minimum

## Description
Mount Roll angle minimum.

## Values
- **Range:** -180 to 180
- **Units:** deg
- **Default:** -30

## Description
This parameter defines the physical "Left Tilt" limit for your camera gimbal's roll axis.

- **Usage:** Set this to the maximum angle your gimbal can tilt to the left before hitting its mechanical stops or twisting the cables too far.
- **Function:** The autopilot will prevent any automatic or manual command from exceeding this angle.

