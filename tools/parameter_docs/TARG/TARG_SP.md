---
layout: parameter
name: TARG_SP
display_name: "Target Glide Ground Speed"
description: "Target ground speed during autorotation glide"
default_value: 1500
range: 800 2000
units: "cm/s"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Autorotation/AC_Autorotation.cpp#L53
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Autorotation/AC_Autorotation.h#L35
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Target Glide Ground Speed (TARG_SP)

## Description
This parameter sets the target ground speed for the autonomous autorotation controller during the glide phase. Maintaining the correct forward speed is critical for keeping the rotor RPM in the green arc and reaching the designated landing spot during an engine failure scenario.

## The Mathematics
PID Setpoint.

## The Engineer's View
Defined in `libraries/AC_Autorotation/AC_Autorotation.cpp`.

## Tuning & Behavior
*   **Default Value:** 1500 cm/s (15 m/s)
*   **Tuning:** Adjust based on the specific best-glide speed of your helicopter.