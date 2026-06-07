---
layout: parameter
name: OSD_P_MIN
display_name: OSD Parameter Slot Minimum
description: The minimum value allowed for the parameter when adjusted via the OSD.
default_value: 0
range: -1000000 1000000
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L80
---

# OSD Parameter Slot Minimum (OSD_P_MIN)

## Description
`OSD_P_MIN` defines the lower safety limit for in-flight tuning. 

When you use your sticks to decrease a parameter value on the OSD, the autopilot will stop at this value. This is critical for safety to ensure you don't accidentally set a PID to zero or a negative value that could crash the vehicle.

## Tuning & Behavior
*   **Recommendation:** Set this to the lowest "Safe" value for the parameter you are tuning. For PIDs, this is usually a small positive number.