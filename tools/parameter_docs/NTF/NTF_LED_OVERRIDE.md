---
layout: parameter
name: NTF_LED_OVERRIDE
display_name: "Specifies colour source for the RGBLed"
description: "Override standard LED color scheme"
default_value: 0
range: 0 2
units: ""
group: NTF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Notify/AP_Notify.cpp#L176
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Notify/AP_Notify.h#L241
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Specifies colour source for the RGBLed (NTF_LED_OVERRIDE)

## Description
This parameter changes the color logic of the main Status LED. The standard ArduPilot blink codes are very detailed but complex. This option allows selecting simplified schemes used for specific competitions or safety standards.

## The Mathematics
Enum mapping.

## The Engineer's View
Defined in `libraries/AP_Notify/AP_Notify.cpp`.
*   **0 (Standard):** Full ArduPilot blink codes (Yellow=Failsafe, Blue=GPS, Green=Armed/GPS, etc.).
*   **1 (Traffic Light):** Red=Armed, Yellow=Disarmed (Unsafe/No GPS), Green=Disarmed (Safe).
*   **2 (Medical Express):** Specific to the UAV Challenge rules.

## Tuning & Behavior
*   **Default Value:** 0
*   **Usage:** Use "Traffic Light" (1) for simpler visual confirmation of safety state for ground personnel.