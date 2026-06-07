---
layout: parameter
name: OSD_W_NSAT
display_name: OSD Satellites Warning
description: The minimum number of satellites at which the OSD will start flashing a warning.
default_value: 9
range: 0 30
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L108
---

# OSD Satellites Warning (OSD_W_NSAT)

## Description
`OSD_W_NSAT` warns you if your GPS signal is getting weak.

If the number of satellites drops below this value, the satellite icon on your OSD will flash. This is a sign that you might be flying near tall buildings or trees that are blocking the sky.
