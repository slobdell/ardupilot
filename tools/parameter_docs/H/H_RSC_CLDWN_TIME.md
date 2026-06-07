---
layout: parameter
name: H_RSC_CLDWN_TIME
display_name: Cooldown Time
description: Duration in seconds to run the engine at a fast idle for cooldown after landing.
default_value: 0
range: 0 120
units: s
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# Cooldown Time (H_RSC_CLDWN_TIME)

## Description
Automates the engine cooldown procedure for combustion or turbine engines. After landing and disarming, the engine will run at an elevated idle for this many seconds before shutting down.
*   **0 disables the cooldown feature.**
