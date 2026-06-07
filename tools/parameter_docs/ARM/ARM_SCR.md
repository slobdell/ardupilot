---
layout: parameter
name: ARM_SCR
display_name: "Arm Screen"
description: "Selects which OSD screen to automatically display when the vehicle arms."
default_value: 0
range: 0 4
units: "Index"
group: ARM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L155
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Arm Screen (ARM_SCR)

## Description
This parameter automates the On-Screen Display (OSD) management by automatically switching to a specific layout when the vehicle arms. 

Pilots often prefer a "Pre-flight" OSD screen (showing GPS health and battery cell voltages) while on the ground, but want a "Flight" OSD screen (showing artificial horizon, altitude, and current draw) as soon as they are ready to fly. Setting `ARM_SCR` eliminates the need to manually toggle screens using a transmitter switch.

## The Mathematics
The parameter uses a 1-based index for user convenience, which the internal code converts to a 0-indexed array element:

$$ \text{InternalScreenID} = ARM\_SCR - 1 $$

If $ARM\_SCR = 0$, the feature is disabled and no automatic switching occurs.

## The Engineer's View
In `AP_OSD::update()` (`libraries/AP_OSD/AP_OSD.cpp`), the OSD system monitors the armed state of the vehicle. 
1.  It checks for a "Rising Edge" transition where `was_armed` is false but the current state is armed.
2.  It verifies that `arm_scr` is within the valid range (typically 1 to 4).
3.  It checks if the target screen layout is actually enabled in the parameters.
4.  If all checks pass, it updates the `current_screen` variable, forcing the display to refresh with the new layout.

## Tuning & Behavior
*   **0:** Disabled (No automatic switching).
*   **1 - 4:** Switches to the corresponding OSD screen number on arming.
*   **Recommendation:** Set OSD Screen 1 as your "Summary/Pre-flight" screen and OSD Screen 2 as your "Combat/Flight" screen. Then set `ARM_SCR` to **2**.
*   **Related:** Use `OSD_DSARM_SCR` to automatically switch back to a summary screen upon landing and disarming.

