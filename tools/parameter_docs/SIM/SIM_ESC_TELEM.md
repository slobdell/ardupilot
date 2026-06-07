---
layout: parameter
name: SIM_ESC_TELEM
display_name: Simulated ESC Telemetry Type
description: Selects the type of ESC telemetry data to emulate (RPM, Voltage, Temperature).
default_value: 0
range: 0 2
units: 
group: SIM
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated ESC Telemetry Type (SIM_ESC_TELEM)

## Description
`SIM_ESC_TELEM` enables the virtual return path for motor data.

If you are testing **DShot ESC Telemetry** or **RPM filtering**, you need this enabled so the autopilot "sees" the RPM and voltage data coming back from the virtual ESCs.

*   **0:** Disabled.
*   **1:** Enabled (Standard RPM + Voltage).
*   **2:** Bidirectional DShot (RPM only, but high-speed).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **1** to verify your OSD battery display and motor fail detection.