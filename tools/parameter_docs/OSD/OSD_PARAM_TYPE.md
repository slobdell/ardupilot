---
layout: parameter
name: OSD_PARAM_TYPE
display_name: OSD Parameter Type
description: Selects the logical type of the parameter for specialized display formatting (e.g., Serial Protocol names instead of numbers).
default_value: 0
range: 0 7
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L100
---

# OSD Parameter Type (OSD_PARAM_TYPE)

## Description
`OSD_PARAM_TYPE` tells the OSD how to format the value of a tuned parameter.

Normally, parameters are just numbers. However, some parameters (like `SERIAL_PROTOCOL`) are easier to understand if shown as text (e.g., "MAV" instead of "1").

*   **0: None.** Show the raw numerical value.
*   **1: Serial Protocol.** Show names of serial protocols.
*   **2: Servo Function.** Show servo function names.
*   **4: Flight Mode.** Show flight mode names.
