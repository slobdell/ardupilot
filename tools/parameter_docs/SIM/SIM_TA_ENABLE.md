---
layout: parameter
name: SIM_TA_ENABLE
display_name: Simulated ToneAlarm Enable
description: Enables or disables the simulated ToneAlarm (Buzzer) device.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_buzzer_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_ToneAlarm.cpp#L25
---

# Simulated ToneAlarm Enable (SIM_TA_ENABLE)

## Description
`SIM_TA_ENABLE` activates the simulated hardware buzzer. 

In a real flight controller, the ToneAlarm is the speaker that plays the "Happy" arming tune, "Sad" battery low tones, and error chirps. Enabling this in SITL allows developers to hear these tones while testing in the simulator.

## The Engineer's View
Defined in `SIM_ToneAlarm.cpp`.
When enabled, the SITL backend pipes the audio frequency commands to the host computer's audio system (or logs them for verification). It mimics the behavior of the `AP_Notify` ToneAlarm backend.

## Tuning & Behavior
*   **Default Value:** 0 (Silent).
*   **1:** Tones are enabled.