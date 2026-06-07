---
layout: parameter
name: TEMP1_SRC
display_name: Temperature Sensor Source
description: Selects which system component this temperature sensor is measuring.
default_value: 0
range: 0 6
units: 
group: TEMP
visual_asset_id: temp_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Params.cpp#L63
---

# Temperature Sensor Source (TEMP1_SRC)

## Description
`TEMP1_SRC` tells the autopilot what the temperature sensor is actually touching. 

By default, temperature data is just recorded in the logs. However, if you set a source here, the autopilot will "link" this sensor to a specific component. For example, if you set this to **1 (ESC)**, the temperature reported for ESC 1 will come from this physical sensor instead of the ESC's built-in (often inaccurate) telemetry.

*   **0: None.** Data is logged but not displayed as a component temperature.
*   **1: ESC.**
*   **2: Motor.**
*   **3: Battery.** (Uses [TEMP1_SRC_ID](TEMP1_SRC_ID.html) to select which battery).
*   **5: Pitot Tube.**

## Tuning & Behavior
*   **Default:** 0.
*   **Integration:** Use this to enable thermal protection for motors or to monitor battery health more closely.