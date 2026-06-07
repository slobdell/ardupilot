---
layout: parameter
name: TEMP1_TYPE
display_name: Temperature Sensor Type (Sensor 1)
description: Enables and selects the type for the first temperature sensor.
default_value: 0
range: 0 7
units: 
group: TEMP
visual_asset_id: temp_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Params.cpp#L40
---

# Temperature Sensor Type (TEMP1_TYPE)

## Description
`TEMP1_TYPE` enables the primary external temperature sensor. 

This is often used to monitor the heat of critical components like motors, ESCs, or batteries that do not have built-in telemetry. 

*   **0: Disabled.**
*   **1: TSYS01.** (I2C).
*   **2: MCP9600.** (I2C Thermocouple).
*   **5: Analog.** (Voltage-divider based thermistor).
*   **6: DroneCAN.**

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Integration:** Once enabled, use [TEMP1_SRC](TEMP1_SRC.html) to tell ArduPilot which system component this sensor is measuring.