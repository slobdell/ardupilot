---
layout: parameter
name: AFS_RC_MAN_ONLY
display_name: Enable RC Termination only in manual control modes
description: If this parameter is set to 1, then an RC loss will only cause the plane to terminate in manual control modes. If it is 0, then the plane will terminate in any flight mode.
default_value: 1
range: 
units: 
group: AFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AdvancedFailsafe/AP_AdvancedFailsafe.cpp
---

# Enable RC Termination only in manual control modes (AFS_RC_MAN_ONLY)

## Description
Restricts RC-loss termination to manual flight modes only.

## Tuning & Behavior
*   **Default Value:** 1 (Manual Only)
*   **Values:** 0:All Modes, 1:Manual Modes Only
