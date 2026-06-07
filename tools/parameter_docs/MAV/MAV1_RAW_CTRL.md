---
layout: parameter
name: MAV1_RAW_CTRL
display_name: MAVLink Raw Control Stream Rate
description: The frequency (in Hz) for streaming raw control output messages (e.g., for HIL or specific telemetry analysis).
default_value: 0
range: 0 50
units: Hz
group: MAV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/GCS_Mavlink.cpp
---

# MAVLink Raw Control Stream Rate (MAV1_RAW_CTRL)

## Description
`MAV1_RAW_CTRL` defines the frequency for specialized raw control data messages. 

In most modern ArduPilot versions, this stream is **Unused** or reserved for Hardware-In-The-Loop (HIL) simulations and developer-level diagnostic analysis. 

## Tuning & Behavior
*   **Default:** 0 Hz.
*   **Recommendation:** Leave at **0** unless specifically instructed by a developer or when setting up a custom simulation environment that requires high-rate raw actuator data.