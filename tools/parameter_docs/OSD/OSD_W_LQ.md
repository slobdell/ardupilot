---
layout: parameter
name: OSD_W_LQ
display_name: OSD Link Quality Warning
description: The link quality percentage at which the OSD will start flashing a warning.
default_value: 50
range: 0 100
units: %
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD.cpp#L223
---

# OSD Link Quality Warning (OSD_W_LQ)

## Description
`OSD_W_LQ` sets the "Alarm Trigger" for your radio signal quality. 

When your link quality (LQ) percentage drops below this value, the LQ readout on your goggles/screen will begin to flash. This gives you a clear visual warning that you are nearing the edge of your radio range or that you are experiencing high interference.

## Tuning & Behavior
*   **Default:** 50%.
*   **Recommendation:** Set to **70** if you want an early warning. Set to **30** if you are comfortable flying on the edge of the link capability.
*   **Note:** This is based on the **Link Quality** (percentage of successful packets), which is generally a more reliable indicator of link health than simple RSSI (signal strength).