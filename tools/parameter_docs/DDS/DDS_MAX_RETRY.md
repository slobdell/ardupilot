---
layout: parameter
name: DDS_MAX_RETRY
display_name: "DDS ping max attempts"
description: "Max retries for DDS/ROS2 connection"
default_value: 10
range: 0 100
units: ""
group: DDS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DDS/AP_DDS_Client.cpp#L153
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DDS/AP_DDS_Client.h#L309
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# DDS ping max attempts (DDS_MAX_RETRY)

## Description
This parameter controls the connection robustness between ArduPilot and the ROS 2 (Robot Operating System) DDS Agent. It limits how many times the client will try to establish a session before giving up.

## The Mathematics
Counter logic.

## The Engineer's View
Defined in `libraries/AP_DDS/AP_DDS_Client.cpp`.
*   **0:** Unlimited retries (Best for persistent autonomy).
*   **>0:** Give up after N attempts.

## Tuning & Behavior
*   **Default Value:** 10
*   **Recommendation:** Set to 0 for production robots where the companion computer might boot slower than the autopilot.