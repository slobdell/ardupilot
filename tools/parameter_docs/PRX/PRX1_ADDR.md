---
layout: parameter
name: PRX1_ADDR
display_name: Proximity Sensor Bus Address (Sensor 1)
description: The specific I2C or DroneCAN bus address for the proximity sensor.
default_value: 0
range: 0 127
units: 
group: PRX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L118
---

# Proximity Sensor Bus Address (PRX1_ADDR)

## Description
`PRX1_ADDR` identifies the unique "Hardware Address" of your proximity sensor on the shared I2C or DroneCAN bus.

This allows you to connect multiple sensors of the same type to the same bus without conflict.

*   **0:** Auto-detection.
*   **1-127:** Specific hardware address.