---
layout: parameter
name: AFS_RC_FAIL_TIME
display_name: RC failure time
description: This is the time in seconds in manual mode that failsafe termination will activate if RC input is lost. For the OBC rules this should be (1.5). Use 0 to disable.
default_value: 0
range: 
units: s
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# RC failure time (AFS_RC_FAIL_TIME)

## Description
Duration of RC link loss in manual mode before forced termination.

## Tuning & Behavior
*   **Default Value:** 0 s (Disabled)
*   **Recommended for OBC rules: 1.5 seconds.**