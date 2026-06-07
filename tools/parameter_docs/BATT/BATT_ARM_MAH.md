---
layout: parameter
name: BATT_ARM_MAH
display_name: Required arming remaining capacity
description: Battery capacity remaining which is required to arm the aircraft. Set to 0 to allow arming at any capacity.
default_value: 0
range: 
units: mAh
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Required arming remaining capacity (BATT_ARM_MAH)

## Description
A pre-arm safety check. The vehicle will refuse to arm if the calculated remaining capacity is below this value.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Note: Rebooting usually resets this estimate for non-smart batteries.**
