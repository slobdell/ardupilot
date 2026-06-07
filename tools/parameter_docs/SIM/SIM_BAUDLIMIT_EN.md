---
layout: parameter
name: SIM_BAUDLIMIT_EN
display_name: Simulated Baud Rate Limiting Enable
description: Enables strict bandwidth limiting on simulated serial ports to match their baud rate settings.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: serial_protocol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Baud Rate Limiting Enable (SIM_BAUDLIMIT_EN)

## Description
`SIM_BAUDLIMIT_EN` forces the simulator to respect the physics of serial data transfer speeds.

By default, SITL sends data as fast as the CPU allows. If you enable this, a simulated 57600 baud link will actually choke if you try to send too much data, causing packet loss and latency.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited speed).
*   **Recommendation:** Enable this when testing telemetry radios or low-bandwidth links to verify your stream rates (`SRx_params`) are configured correctly.