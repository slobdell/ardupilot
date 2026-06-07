---
layout: parameter
name: OSD_W_RSSI
display_name: OSD RSSI Warning
description: The signal strength (RSSI) percentage at which the OSD will start flashing a warning.
default_value: 30
range: 0 100
units: %
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L107
---

# OSD RSSI Warning (OSD_W_RSSI)

## Description
`OSD_W_RSSI` is a "Low Signal" alert.

When your radio connection drops below this percentage, the signal bar on your screen will start flashing to warn you that you are nearing the limit of your control range.
