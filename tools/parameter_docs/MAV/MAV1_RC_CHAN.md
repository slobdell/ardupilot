---
layout: parameter
name: MAV1_RC_CHAN
display_name: MAVLink RC Channel Stream Rate
description: The frequency (in Hz) for streaming stick inputs (RC_CHANNELS) and motor outputs (SERVO_OUTPUT_RAW).
default_value: 0
range: 0 50
units: Hz
group: MAV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/GCS_Mavlink.cpp
---

# MAVLink RC Channel Stream Rate (MAV1_RC_CHAN)

## Description
`MAV1_RC_CHAN` controls how often the autopilot reports your stick positions and motor outputs to the Ground Control Station.

This is essential for viewing the "Radio Calibration" bars or "Servo Output" diagnostics in your GCS while the drone is powered on. It also affects the refresh rate of any RC-based widgets or graphs on your dashboard.

## Tuning & Behavior
*   **Default:** 0 Hz (Only sends when requested or at a very low base rate).
*   **Recommendation:** Set to **2 or 5 Hz** if you want to see smooth movements on the GCS radio bars.
*   **Context:** Covers `SERVO_OUTPUT_RAW` and `RC_CHANNELS` messages.