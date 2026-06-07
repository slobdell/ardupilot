---
layout: parameter
name: CAN_D1_UC_NTF_RT
display_name: DroneCAN Notify Transmit Rate
description: Maximum transmit rate (in Hz) for Notify State messages over DroneCAN.
default_value: 20
range: 1 200
units: Hz
group: CAN
visual_asset_id: dronecan_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L133
---

# DroneCAN Notify Transmit Rate (CAN_D1_UC_NTF_RT)

## Description
`CAN_D1_UC_NTF_RT` controls how often the flight controller updates CAN-based status lights (LEDs) and buzzers.

If you are using a CAN LED (like the NeoPixel modules on some GPS units), this setting determines the smoothness of color transitions and how quickly the lights react to mode changes or arming events.

## Tuning & Behavior
*   **Default Value:** 20 Hz.
*   **Recommendation:** Leave at **20 Hz**. This is fast enough for smooth visual feedback without wasting bus bandwidth.