---
layout: parameter
name: BTN_OPTIONS1
display_name: Button Pin 1 Options
description: Options for Pin 1. PWM input detects PWM above or below 1800/1200us instead of logic level. Invert changes HIGH state to be logic low voltage on pin.
default_value: 0
range: 
units: 
group: BTN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Button/AP_Button.cpp
---

# Button Pin 1 Options (BTN_OPTIONS1)

## Description
Advanced configuration for the first button, allowing for inverted logic or PWM signal detection instead of simple high/low voltage.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: PWM Input
    *   Bit 1: InvertInput
