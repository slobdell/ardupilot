---
layout: parameter
name: FS_EKF_ACTION
display_name: EKF Failsafe Action
description: Selects the action taken when the EKF variance threshold is exceeded.
default_value: 1
range: 1 3
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# EKF Failsafe Action (FS_EKF_ACTION)

## Description
`FS_EKF_ACTION` determines how the drone reacts if its "Internal Map" becomes unreliable (see [FS_EKF_THRESH](FS_EKF_THRESH.html)).

*   **1: Land (Default).** The drone will immediately perform a controlled descent and land. This is the safest option if the GPS or Compass data is bad.
*   **2: AltHold.** The drone will switch to Altitude Hold mode. This stops it from following a bad GPS position but allows the pilot to take manual control and fly by sight.
*   **3: Land (Strict).** Forces a landing even if the drone is currently in a manual mode like Stabilize.