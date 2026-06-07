---
layout: parameter
name: OSD_CHAN
display_name: OSD Screen Switch Channel
description: Selects the RC channel used to toggle between different OSD screens in flight.
default_value: 0
range: 0 16
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L101
---

# OSD Screen Switch Channel (OSD_CHAN)

## Description
`OSD_CHAN` allows you to change what information you see on your goggles using a switch on your transmitter.

ArduPilot supports up to 4 different "Screens" (e.g., Screen 1 for takeoff, Screen 2 for cruising, Screen 3 for racing). By assigning a switch to this channel, you can cycle through them while flying.

*   **0:** Disabled. Only Screen 1 is shown.
*   **1-16:** RC Channel number.