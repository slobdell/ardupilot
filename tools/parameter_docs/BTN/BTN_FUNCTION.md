---
layout: parameter
name: BTN_FUNCTION
display_name: "Function for button"
description: "Primary function for joystick button"
default_value: 0
range: 0 100
units: ""
group: BTN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_JSButton/AP_JSButton.cpp#L10
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_JSButton/AP_JSButton.h#L136
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Function for button (BTN_FUNCTION)

## Description
This parameter assigns a **Primary Function** to a specific button on a connected USB Joystick or Gamepad (communicating via MAVLink). This allows for direct control of vehicle modes, camera triggers, relays, and servos from the controller.

## The Mathematics
Enum Map.

## The Engineer's View
Defined in `libraries/AP_JSButton/AP_JSButton.cpp`.
*   **0:** Disabled.
*   **1:** Mode Change (Manual/Stabilize).
*   **...** (See Wiki for full list).

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Setup:** Identify the button ID from your GCS/Driver, then set the corresponding `BTN_FUNCTION` parameter.