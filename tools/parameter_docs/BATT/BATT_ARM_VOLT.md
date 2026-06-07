---
layout: parameter
name: BATT_ARM_VOLT
display_name: Required arming voltage
description: Battery voltage level which is required to arm the aircraft. Set to 0 to allow arming at any voltage.
default_value: 0
range: 
units: V
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Required arming voltage (BATT_ARM_VOLT)

## Description
A pre-arm safety check. The vehicle will refuse to arm if the battery voltage is below this value.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Prevents starting a flight with a partially discharged battery.**
