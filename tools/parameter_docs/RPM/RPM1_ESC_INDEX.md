---
layout: parameter
name: RPM1_ESC_INDEX
display_name: RPM ESC Telemetry Index
description: Selects the ESC instance index that this RPM sensor data will be written to in the telemetry logs.
default_value: 0
range: 0 32
units: 
group: RPM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_Params.cpp#L78
---

# RPM ESC Telemetry Index (RPM1_ESC_INDEX)

## Description
`RPM1_ESC_INDEX` allows you to "Inject" external RPM data into the ESC telemetry system.

If you have a motor that doesn't provide internal RPM telemetry (like a gas engine or an older ESC), but you have an external RPM sensor (optical or hall effect), you can use this parameter to tell the autopilot: "Take the RPM from this sensor and record it as if it were coming from ESC X."

## Tuning & Behavior
*   **Default:** 0 (Disabled).
*   **Usage:** Set to the motor number (e.g. 1) to have this sensor's data appear in the `ESC[0]` telemetry logs and GCS fields.