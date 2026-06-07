---
layout: parameter
name: FS_THR_ENABLE
display_name: Throttle Failsafe Enable
description: Enables the "Radio Loss" failsafe based on the throttle channel value or RC link loss.
default_value: 0
range: 0 5
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L101
---

# Throttle Failsafe Enable (FS_THR_ENABLE)

## Description
`FS_THR_ENABLE` is the primary failsafe for your radio control link.

If you fly out of range or your transmitter battery dies, your drone needs to know how to react.

*   **0: Disabled.** No action. (Dangerous!).
*   **1: Enabled (RTL).** The drone will automatically return home and land.
*   **3: Enabled (Smart-RTL or RTL).** The drone will try to retrace its steps home.
*   **5: Enabled (Land).** The drone will land exactly where it is.

## Tuning & Behavior
*   **Recommendation:** Always set this to **1 (RTL)** for any outdoor mission.
*   **Trigger:** This failsafe is triggered if the throttle channel drops below `FS_THR_VALUE` or if the receiver stops sending data (Radio Loss).