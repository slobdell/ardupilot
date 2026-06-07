---
layout: parameter
name: OSD_P_EN
display_name: OSD Parameter Slot Enable
description: Enables or disables a specific parameter slot on the in-flight OSD tuning screen.
default_value: 0
range: 0 1
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L39
---

# OSD Parameter Slot Enable (OSD_P_EN)

## Description
`OSD_P_EN` (usually appearing in groups like `OSD5_PARAM1_EN`) enables a specific slot in the in-flight tuning menu. 

ArduPilot allows you to configure special OSD screens where you can adjust PIDs, rates, or other parameters while flying using your transmitter sticks. Each screen has multiple slots (typically 9). This parameter controls if a particular slot is active and visible.

*   **0: Disabled.** The slot is empty.
*   **1: Enabled.** The slot displays the configured parameter for adjustment.

## Tuning & Behavior
*   **Setup:** Once enabled, you must also set the parameter group (`OSD_P_GRP`) and index (`OSD_P_IDX`) to tell the autopilot which parameter you want to tune in this slot.
*   **Safety:** Only enable the parameters you actually intend to tune during the flight to avoid accidental changes to critical settings.