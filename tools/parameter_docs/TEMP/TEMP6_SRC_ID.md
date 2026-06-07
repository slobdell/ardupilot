---
alias_target: TEMP1_SRC_ID
default_value: AP_TEMPERATURE_SENSOR_SOURCE_ID_DEFAULT
description: 'Sensor Source Identification is used to replace a specific instance
  of a system component''s temperature report with the temp sensor''s. Examples: TEMP_SRC
  = 1 (ESC), TEMP_SRC_ID = 1 will set the temp of ESC1. TEMP_SRC = 3 (BatteryIndex),TEMP_SRC_ID
  = 2 will set the temp of BATT2. TEMP_SRC = 4 (BatteryId/SerialNum),TEMP_SRC_ID=42
  will set the temp of all batteries that have param BATTn_SERIAL = 42.'
display_name: Sensor Source Identification
group: TEMP
investigation_status: alias
layout: parameter
name: TEMP6_SRC_ID
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Params.cpp#L68
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TemperatureSensor/AP_TemperatureSensor_Params.h#L56
units: ''
visual_asset_id: null
---

# Sensor Source Identification

**Note:** This parameter functions identically to [TEMP1_SRC_ID](../TEMP/TEMP1_SRC_ID.html).
