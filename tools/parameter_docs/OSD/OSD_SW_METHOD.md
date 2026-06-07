---
layout: parameter
name: OSD_SW_METHOD
display_name: OSD Switch Method
description: Determines how the OSD switches between different screens.
default_value: 0
range: 0 2
units: 
group: OSD
visual_asset_id: osd_switch_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.h#L730
---

# OSD Switch Method (OSD_SW_METHOD)

## Description
`OSD_SW_METHOD` controls how you cycle through the 4 available OSD screens using your RC transmitter.

You can set up different layouts (e.g., one for flight, one for landing, one blank) and switch between them in flight.

*   **0: Toggle (Default).** Assign a switch to `RCx_OPTION = 224` (OSD Toggle). Each toggle moves to the next screen (1 -> 2 -> 3 -> 4 -> 1).
*   **1: PWM Range.** Assign an RC channel to `OSD_CHAN`. The position of the switch/knob determines the screen (Low=1, Mid-Low=2, Mid-High=3, High=4).
*   **2: Auto Switch.** The OSD automatically switches screens based on flight mode or events (requires Lua scripting or specific backend support).

## Tuning & Behavior
*   **Default Value:** 0 (Toggle).
*   **Recommendation:** Use **0** if you have a momentary switch. Use **1** if you have a multi-position switch or a knob.