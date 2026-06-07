---
layout: parameter
name: PTCH2SRV_RLL
display_name: Roll Compensation
description: Gain added to pitch to keep the aircraft from descending or ascending in turns.
default_value: 1.0
range: 0.7 1.5
units: 
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L55
---

# Roll Compensation (PTCH2SRV_RLL)

## Description
`PTCH2SRV_RLL` is the "Turn Coordination" elevator boost.

When a plane banks, it loses vertical lift component. To stay level, you must pull back on the stick. This parameter does that automatically.

*   **1.0 (Default):** Calculated compensation based on physics.
*   **> 1.0:** Pulls harder in turns (gains altitude).
*   **< 1.0:** Pulls less (loses altitude).

## Tuning & Behavior
*   **Default Value:** 1.0.
*   **Recommendation:** Tune this by flying continuous circles in FBWA mode. If the nose drops, increase this value. If the nose rises, decrease it.
