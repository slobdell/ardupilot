---
layout: parameter
name: FS_TEMP_ENABLE
display_name: Internal Temperature Failsafe Enable
description: Selects the action taken if internal enclosure temperature exceeds the limit.
default_value: 0
range: 0 3
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L108
---

# Internal Temperature Failsafe Enable (FS_TEMP_ENABLE)

## Description
`FS_TEMP_ENABLE` defines the emergency response if the internal electronics enclosure gets too hot.

*   **0: Disabled.**
*   **1: Warn Only.**
*   **2: Surface.**

## Tuning & Behavior
*   **Default:** 0.
*   **Requirement:** Requires a configured [FS_TEMP_MAX](FS_TEMP_MAX.html) threshold.