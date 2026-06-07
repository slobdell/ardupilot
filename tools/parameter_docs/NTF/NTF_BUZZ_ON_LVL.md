---
layout: parameter
title: NTF_BUZZ_ON_LVL
name: Buzzer-on pin logic level
group: NTF
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Notify/AP_Notify.cpp#L215
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Notify/AP_Notify.h#L220
---

# NTF_BUZZ_ON_LVL: Buzzer-on pin logic level

## Description
Specifies pin level that indicates buzzer should play.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | LowIsOn (Active Low) |
| 1 | HighIsOn (Active High) |

- **Default:** 1 (HighIsOn)

## Description
This parameter defines the electrical polarity of the buzzer control signal.

- **Active High (1):** The autopilot outputs 3.3V (Logic High) to turn the buzzer ON. This is standard for most simple piezo buzzers driven by a transistor.
- **Active Low (0):** The autopilot outputs 0V (Logic Low) to turn the buzzer ON. This is common for some integrated buzzer modules or specific board designs.

## Source Code
[ardupilot/libraries/AP_Notify/AP_Notify.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Notify/AP_Notify.cpp#L215)

