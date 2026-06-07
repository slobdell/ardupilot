---
layout: parameter
name: PTCH2SRV_RLL
display_name: Pitch Compensation in Roll
description: Adds upward pitch to compensate for loss of lift during banked turns.
default_value: 1.0
range: 0 2.0
units: 
group: PTCH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_PitchController.cpp#L60
---

# Pitch Compensation in Roll (PTCH2SRV_RLL)

## Description
`PTCH2SRV_RLL` is an "Elevator-to-Aileron" mix.

When a fixed-wing plane banks (rolls) into a turn, it loses vertical lift. To maintain its altitude while turning, it must pull slightly back on the elevator. This parameter automates that process.

*   **1.0 (Default):** Standard compensation.
*   **Higher Value:** Adds more back-elevator during turns (useful for "draggy" or low-lift planes).
*   **0:** No compensation (the plane will lose altitude in every turn unless the pilot manually pulls back).