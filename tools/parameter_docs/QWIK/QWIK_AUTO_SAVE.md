---
layout: parameter
name: QWIK_AUTO_SAVE
display_name: Quicktune Auto Save Time
description: The number of seconds to wait after completing the tune before automatically saving the new gains to memory.
default_value: 0
range: 0 60
units: s
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L92
---

# Quicktune Auto Save Time (QWIK_AUTO_SAVE)

## Description
`QWIK_AUTO_SAVE` allows the autopilot to permanently store the new PID gains without requiring a separate "Save" command from the pilot.

Normally, you have to toggle a switch on your remote to save the tune. If you set this parameter to **10**, the drone will wait for 10 seconds after it finishes tuning all axes and then automatically save the values to memory.

*   **0 (Default):** Auto-save disabled. You must save manually using an RC switch or the Ground Station.