---
layout: parameter
title: RPM_MSG_RATE
name: RPM sensor message rate
group: RPM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L712
---

# RPM_MSG_RATE: RPM sensor message rate

## Description
This is the rate RPM sensor data is sent in Hz. Zero means no send. Each sensor with a set ID is sent in turn.

## Values
- **Range:** 0 to 200
- **Units:** Hz
- **Default:** 0

## Description
This parameter controls the frequency of RPM telemetry messages sent by the AP_Periph device (e.g., a CAN-based RPM sensor or ESC).

- **Usage:** Set this to a non-zero value (e.g., **10Hz or 20Hz**) to see motor or rotor RPM on your GCS or OSD.
- **Function:** The peripheral will sample the RPM and broadcast it on the CAN bus at this interval. 
- **0 (Default):** Disables RPM telemetry from this device.

