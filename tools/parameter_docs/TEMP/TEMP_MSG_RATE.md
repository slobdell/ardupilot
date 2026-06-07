---
layout: parameter
title: TEMP_MSG_RATE
name: Temperature sensor message rate
group: TEMP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L694
---

# TEMP_MSG_RATE: Temperature sensor message rate

## Description
This is the rate Temperature sensor data is sent in Hz. Zero means no send.

## Values
- **Range:** 0 to 200
- **Units:** Hz
- **Default:** 0

## Description
This parameter controls how frequently the AP_Periph device broadcasts temperature data over the DroneCAN bus.

- **0 (Default):** Disabled. No temperature messages are sent.
- **1-200:** The frequency in Hertz.
- **Usage:** Set this to a positive value (e.g., 10) if you have connected an external temperature sensor to your CAN peripheral and want the flight controller to receive the data.

