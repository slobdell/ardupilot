---
layout: parameter
name: RELAY1_FUNCTION
display_name: Relay Function (Instance 1)
description: Assigns a specific control purpose (e.g., Camera, Ignition, Parachute) to Relay 1.
default_value: 0
range: 0 100
units: 
group: RELAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Relay/AP_Relay_Params.cpp#L36
---

# Relay Function (RELAY1_FUNCTION)

## Description
`RELAY1_FUNCTION` defines the "Job" of the first relay output.

Unlike physical PWM outputs which are usually used for motors and servos, Relays are simple digital ON/OFF switches. This parameter tells the autopilot what internal logic should control this switch.

## Common Values
*   **0: None.** Relay is disabled.
*   **1: Relay.** Manual control via MAVLink or auxiliary switch.
*   **2: Ignition.** Controlled by the Internal Combustion Engine (ICE) library.
*   **3: Parachute.** Triggered when a crash is detected.
*   **4: Camera.** Triggered by the camera shutter logic.

## Tuning & Behavior
*   **Default:** 0.
*   **Note:** If you want to use the relay for a custom purpose (like turning on LED lights via a transmitter switch), set this to **1 (Relay)** and assign an RC channel to that relay instance.