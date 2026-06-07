---
layout: parameter
name: OSD_P_INCR
display_name: OSD Parameter Slot Increment
description: The amount the parameter value changes with each stick movement.
default_value: 0.001
range: 0 100
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L92
---

# OSD Parameter Slot Increment (OSD_P_INCR)

## Description
`OSD_P_INCR` defines the "Sensitivity" of the in-flight tuning. 

When you push the transmitter stick to change a parameter, this is the amount added to or subtracted from the current value. 

*   **Small Value (e.g. 0.001):** Precision tuning for delicate PIDs.
*   **Large Value (e.g. 1.0):** Quick adjustments for broad settings like MAVLink stream rates.

## Tuning & Behavior
*   **Recommendation:** Match the increment to the scale of the parameter. For a P-gain that is usually around 0.1, an increment of 0.005 is appropriate. For an altitude limit of 100m, an increment of 5.0 is better.