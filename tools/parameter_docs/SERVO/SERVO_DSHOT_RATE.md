---
layout: parameter
name: SERVO_DSHOT_RATE
display_name: DShot Update Rate
description: The update rate (in kHz) for the DShot ESC protocol.
default_value: 0
range: 0 4
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SRV_Channel/SRV_Channel.cpp#L100
---

# DShot Update Rate (SERVO_DSHOT_RATE)

## Description
`SERVO_DSHOT_RATE` selects the speed of the digital motor protocol.

*   **0:** Disabled (Use PWM/OneShot).
*   **1:** DShot150 (150kHz). Slowest, most robust against noise.
*   **2:** DShot300 (300kHz). Standard.
*   **3:** DShot600 (600kHz). High performance.
*   **4:** DShot1200 (1200kHz). Experimental, requires very short signal wires.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **DShot600** (Value 3) for most modern quads.