---
layout: parameter
name: RELAY1_INVERTED
display_name: Relay Inversion (Instance 1)
description: Flips the electrical logic of the relay output (Active-High vs Active-Low).
default_value: 0
range: 0 1
units: 
group: RELAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Relay/AP_Relay_Params.cpp#L75
---

# Relay Inversion (RELAY1_INVERTED)

## Description
`RELAY1_INVERTED` calibrates the autopilot for your specific relay hardware.

Different relay modules have different "Trigger" requirements. Some turn ON when given a 3.3V signal (Active-High), while others turn ON when the signal is pulled to Ground (Active-Low). 

*   **0: Normal.** Active-High (Standard).
*   **1: Inverted.** Active-Low.

## Tuning & Behavior
*   **Calibration:** If your relay stays ON when you command it OFF (and vice versa), toggle this parameter.