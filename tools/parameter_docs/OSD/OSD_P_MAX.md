---
layout: parameter
name: OSD_P_MAX
display_name: OSD Parameter Slot Maximum
description: The maximum value allowed for the parameter when adjusted via the OSD.
default_value: 0
range: -1000000 1000000
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_ParamSetting.cpp#L86
---

# OSD Parameter Slot Maximum (OSD_P_MAX)

## Description
`OSD_P_MAX` defines the upper safety limit for in-flight tuning. 

This prevents you from increasing a parameter (like a P-gain) to a point where the drone becomes unstable or the servos oscillate to the point of failure. 

## Tuning & Behavior
*   **Recommendation:** Set this to a value that is slightly above your target but still within the known safe operating limits for your specific vehicle.
*   **Safety:** Always test your tuning limits in an open area with plenty of altitude.