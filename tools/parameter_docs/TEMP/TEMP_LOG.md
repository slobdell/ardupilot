---
layout: parameter
name: TEMP_LOG
display_name: Temperature Sensor Logging
description: Controls the logging of temperature sensor data to the DataFlash logs.
default_value: 0
range: 0 2
units: 
group: TEMP
visual_asset_id: temperature_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TemperatureSensor/AP_TemperatureSensor.cpp#L48
---

# Temperature Sensor Logging (TEMP_LOG)

## Description
`TEMP_LOG` enables or disables the recording of temperature sensor data to the drone's internal dataflash log (`.BIN` files).

*   **0: Disabled.** No temperature data is logged.
*   **1: Log All.** Data from every enabled temperature sensor is recorded.
*   **2: Log Only Source None.** Only logs sensors that are NOT assigned to a specific component (like an ESC or Battery). This avoids duplicating data already being recorded in other messages.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Use Case:** Enable this if you have added a dedicated sensor for monitoring ambient air temperature or a custom payload.
