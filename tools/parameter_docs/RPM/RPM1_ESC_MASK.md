---
layout: parameter
name: RPM1_ESC_MASK
display_name: RPM ESC Telemetry Mask
description: A bitmask that determines which ESC instances this RPM sensor should provide data for.
default_value: 0
range: 0 4294967295
units: 
group: RPM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_Params.cpp#L70
---

# RPM ESC Telemetry Mask (RPM1_ESC_MASK)

## Description
`RPM1_ESC_MASK` allows a single RPM sensor to represent multiple motors.

This is useful for vehicles where multiple motors are physically linked to a single shaft (e.g. a geared twin-motor setup) or for helicopters where one RPM sensor on the main gear represents the speed for the entire power system.

*   **Bit 0 (1):** Motor 1
*   **Bit 1 (2):** Motor 2
*   **Example:** Set to **3** (1+2) if this sensor's data applies to both Motors 1 and 2.