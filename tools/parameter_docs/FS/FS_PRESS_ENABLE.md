---
layout: parameter
name: FS_PRESS_ENABLE
display_name: Internal Pressure Failsafe Enable
description: Selects the action taken if internal enclosure pressure exceeds the limit.
default_value: 0
range: 0 3
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L101
---

# Internal Pressure Failsafe Enable (FS_PRESS_ENABLE)

## Description
`FS_PRESS_ENABLE` is a hardware protection feature for **ArduSub** ROVs.

If an ROV has an internal pressure sensor, an increase in pressure can indicate a structural failure or a fast-expanding gas (e.g., from a failing battery). This parameter defines the emergency response.

*   **0: Disabled.**
*   **1: Warn Only.**
*   **2: Surface.**

## Tuning & Behavior
*   **Default:** 0.
*   **Requirement:** Requires a valid internal pressure sensor and a configured [FS_PRESS_MAX](FS_PRESS_MAX.html) threshold.