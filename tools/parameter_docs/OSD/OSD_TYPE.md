---
layout: parameter
name: OSD_TYPE
display_name: OSD Type
description: Selects the hardware protocol and chip type for the On-Screen Display (OSD).
default_value: 0
range: 0 5
units: 
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L40
---

# OSD Type (OSD_TYPE)

## Description
`OSD_TYPE` tells the flight controller what kind of "Video Overlay" chip is being used.

The OSD chip is what draws the text (Altitude, Speed, Battery) over your camera's video feed.

*   **0: None.** OSD is disabled.
*   **1: MAX7456.** The standard analog OSD chip used on most flight controllers (e.g., Matek, Holybro).
*   **3: MSP.** For digital video systems like DJI, FatShark Avatar, or HDZero.
*   **5: Screen.** Integrated graphics for specialized boards.

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Note:** If using a digital system (DJI/Avatar), you must also set a Serial port to `SERIALx_PROTOCOL = 33` (MSP).
