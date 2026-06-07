---
layout: parameter
name: SERVO_32_ENABLE
display_name: Enable 32 Servo Channels
description: Enables support for up to 32 servo output channels (if supported by hardware).
default_value: 0
range: 0 1
units: 
group: SERVO
visual_asset_id: servo_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SRV_Channel/SRV_Channels.cpp#L100
---

# Enable 32 Servo Channels (SERVO_32_ENABLE)

## Description
`SERVO_32_ENABLE` unlocks the full potential of high-end flight controllers (like the Cube Orange or Durandal) that can support more than the standard 16 outputs.

*   **0:** 16 Channels (Standard).
*   **1:** 32 Channels.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Leave at **0** unless you have a massive rover or plane with more than 16 physical servos.
*   **Reboot Required:** Yes.