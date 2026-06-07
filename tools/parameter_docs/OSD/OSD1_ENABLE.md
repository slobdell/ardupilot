---
layout: parameter
name: OSD1_ENABLE
display_name: OSD Screen Enable (Instance 1)
description: Enables the first OSD screen.
default_value: 1
range: 0 1
units: 
group: OSD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD_Screen.cpp#L69
---

# OSD Screen Enable (OSD1_ENABLE)

## Description
`OSD1_ENABLE` (and its siblings OSD2..OSD6) determines if a specific "Screen Layout" is active.

ArduPilot supports up to 6 different OSD screens. You can switch between them using an RC channel ([OSD_CHAN](OSD_CHAN.html)). This allows you to have one screen for takeoff (with flight timers and battery), another for long-range cruising (with GPS and efficiency stats), and a third "Minimalist" screen for unobstructed cinematic flight.

*   **1: Enabled.** The screen is available and can be displayed.
*   **0: Disabled.** The screen is ignored.

## Tuning & Behavior
*   **Default:** 1 for Screen 1, 0 for others.
*   **Switching:** If you enable multiple screens, you must configure [OSD_CHAN](OSD_CHAN.html) to toggle between them.