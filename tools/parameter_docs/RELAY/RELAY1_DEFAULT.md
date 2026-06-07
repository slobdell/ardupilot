---
layout: parameter
name: RELAY1_DEFAULT
display_name: Relay Default State (Instance 1)
description: Sets whether the relay is ON or OFF when the flight controller first powers up.
default_value: 0
range: 0 1
units: 
group: RELAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Relay/AP_Relay_Params.cpp#L66
---

# Relay Default State (RELAY1_DEFAULT)

## Description
`RELAY1_DEFAULT` defines the "Power-On" state of the first relay output.

This is important for safety and automation. For example, if Relay 1 is connected to a camera power supply, you might want it to default to **ON (1)** so the camera starts recording immediately upon power-up. If it is connected to a loud siren or a high-voltage igniter, you would set it to **OFF (0)** to prevent accidental activation.

*   **0: OFF.** The relay starts in the deactivated state.
*   **1: ON.** The relay starts in the activated state.

## Tuning & Behavior
*   **Default:** 0.
*   **Logic Link:** This value is applied immediately when the autopilot initializes.
*   **Note:** If [RELAY1_INVERTED](RELAY1_INVERTED.html) is enabled, the physical output state will be flipped relative to this setting.