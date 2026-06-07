---
layout: parameter
name: VTX_POWER
display_name: Video Transmitter Power Level
description: Sets the output power (in mW) for the video transmitter.
default_value: 0
range: 0 1000
units: mW
group: VTX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VideoTX/AP_VideoTX.cpp#L41
---

# Video Transmitter Power Level (VTX_POWER)

## Description
`VTX_POWER` controls the strength of your video signal.

*   **Standard Values:** 25, 100, 200, 400, 600, 800 (mW).
*   **0:** Lowest available power (Pit mode).

## Tuning & Behavior
*   **Recommendation:** Use the lowest power necessary for your flight. High power settings (800mW+) generate significant heat and can damage the VTX if there is no airflow (e.g., sitting on the bench).
*   **Protocol:** Requires a VTX that supports **SmartAudio** or **Tramp** protocol connected to a serial port.