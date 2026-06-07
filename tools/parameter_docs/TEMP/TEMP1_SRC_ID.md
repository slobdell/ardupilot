---
layout: parameter
name: TEMP1_SRC_ID
display_name: Sensor Source Instance ID
description: The instance number (e.g. ESC 1, Battery 2) that this temperature sensor's data should be mapped to.
default_value: 0
range: 0 255
units: 
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Params.cpp#L68
---

# Sensor Source Instance ID (TEMP1_SRC_ID)

## Description
`TEMP1_SRC_ID` tells the autopilot which specific system component this temperature sensor is "Replacement" data for.

For example, if you have a standalone temperature probe mounted to your motor, and you want that probe's data to show up as "ESC 1 Temperature" in your logs and GCS, you would use this parameter.

*   **Mapping:** This works with [TEMP1_SRC](TEMP1_SRC.html).
    *   If `TEMP1_SRC` = 1 (ESC), and `TEMP1_SRC_ID` = 1, this sensor's data replaces the temperature report for **ESC 1**.
    *   If `TEMP1_SRC` = 3 (Battery), and `TEMP1_SRC_ID` = 2, it replaces **Battery 2**.

## Tuning & Behavior
*   **Default:** 0.
*   **Significance:** This is a powerful integration tool for customizing your vehicle's telemetry dashboard without needing custom firmware.