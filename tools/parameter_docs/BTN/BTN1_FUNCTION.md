---
layout: parameter
name: BTN1_FUNCTION
display_name: Joystick Button Function (Instance 1)
description: Assigns a specialized function (e.g., Mode Switch, Arm/Disarm, Lights) to physical button 1.
default_value: 0
range: 0 111
units: 
group: BTN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_JSButton/AP_JSButton.cpp#L10
---

# Joystick Button Function (BTN1_FUNCTION)

## Description
`BTN1_FUNCTION` defines the "Primary Action" for the first button on your USB joystick or game controller.

This is extremely common in **ArduSub** and **ArduBlimp** applications. By assigning functions to specific buttons, you can fly the vehicle entirely from a joystick without needing a traditional RC transmitter.

## Common Values
*   **0: None.** 
*   **1: shift.** (Enables the [BTN1_SFUNCTION](BTN1_SFUNCTION.html) for all other buttons).
*   **2: arm_toggle.** 
*   **3: arm.**
*   **4: disarm.**
*   **5-13: mode_X.** (Sets a specific flight mode).
*   **21-27: mount/camera.**
*   **31-36: lights.**
*   **42-43: gain_inc/dec.**

## Tuning & Behavior
*   **Default:** 0.
*   **Multiple Buttons:** This parameter is replicated for every button on your controller (BTN2, BTN3, etc.).
