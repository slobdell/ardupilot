---
layout: parameter
title: ROLL_MAX
name: Mount Roll angle maximum
group: ROLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Mount/AP_Mount_Params.cpp#L50
---

# ROLL_MAX: Mount Roll angle maximum

## Description
Mount Roll angle maximum.

## Values
- **Range:** -180 to 180
- **Units:** deg
- **Default:** 30

## Description
This parameter defines the physical "Right Tilt" limit for your camera gimbal's roll axis.

- **Usage:** Set this to the maximum angle your gimbal can tilt to the right before hitting its mechanical stops or twisting the cables too far.
- **Function:** The autopilot will prevent any automatic or manual command from exceeding this angle.

