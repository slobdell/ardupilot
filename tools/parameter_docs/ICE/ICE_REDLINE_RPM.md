---
layout: parameter
name: ICE_REDLINE_RPM
display_name: RPM Redline Limit
description: The maximum safe rotational speed (RPM) for the engine.
default_value: 0
range: 0 2000000
units: RPM
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L137
---

# RPM Redline Limit (ICE_REDLINE_RPM)

## Description
`ICE_REDLINE_RPM` is a safety governor that prevents engine destruction.

If the engine RPM exceeds this limit (e.g., during a steep dive or if the propeller detaches), ArduPilot will override the mission throttle and force it lower to bring the RPM back into a safe range.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to the manufacturer's recommended maximum continuous RPM.
*   **Action:** When active, the autopilot reduces the effective throttle output until the RPM falls below the limit.