---
layout: parameter
name: BATT_OPTIONS
display_name: Battery monitor options
description: Bitmask of options to change the behaviour of the battery monitor.
default_value: 0
range: 
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Battery monitor options (BATT_OPTIONS)

## Description
Configuration bitmask for advanced battery features like MPPT reporting or special DroneCAN behaviors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 6: Send resistance compensated voltage to GCS
    *   Bit 8: Battery is for internal autopilot use only
    *   Bit 9: Sum monitor measures minimum voltage instead of average