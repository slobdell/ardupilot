---
layout: parameter
name: SIM_PIN_MASK
display_name: Simulated GPIO Pin Mask
description: A bitmask of GPIO pins to emulate in SITL.
default_value: 0
range: 0 65535
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated GPIO Pin Mask (SIM_PIN_MASK)

## Description
`SIM_PIN_MASK` tells the simulator which "Digital Pins" it should pretend exist.

This allows you to test things like Relay control, Camera triggering, or specialized hardware switches without physical wires. 

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Match the pins you have configured in your `RELAY_PIN` or `CAM_FEEDBACK_PIN` parameters.