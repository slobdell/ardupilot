---
layout: parameter
name: FLTMODE_CH
display_name: Flight mode channel
description: RC Channel to use for flight mode selection.
default_value: 8
range: 1 16
units: 
group: FLTMODE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Flight mode channel (FLTMODE_CH)

## Description
Specifies which RC channel on your transmitter is used to switch between the 6 primary flight modes.
*   **Default Value:** 8 (Plane), 5 (Copter)