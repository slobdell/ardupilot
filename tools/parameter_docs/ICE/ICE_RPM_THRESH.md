---
layout: parameter
name: ICE_RPM_THRESH
display_name: RPM threshold
description: The rotational speed (RPM) above which the engine is considered to be successfully running.
default_value: 100
range: 100 100000
units: RPM
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L70
---

# RPM threshold (ICE_RPM_THRESH)

## Description
`ICE_RPM_THRESH` is the "Run Signal" for the autopilot.

When the RPM sensor reports a speed higher than this value, ArduPilot transitions from the `STARTING` state to the `RUNNING` state and immediately turns off the starter motor. If the RPM falls below this value while the engine is supposed to be running, a "Uncommanded Stop" error is triggered, and the autopilot may attempt an in-flight restart.

## Tuning & Behavior
*   **Default Value:** 100 RPM.
*   **Recommendation:** Set to a value roughly **50% of your idle RPM**. If your engine idles at 1200 RPM, set this to **600**. This ensures the starter stays engaged until the engine has truly fired and stabilized.