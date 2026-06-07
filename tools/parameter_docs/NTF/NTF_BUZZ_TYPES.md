---
layout: parameter
name: NTF_BUZZ_TYPES
display_name: Buzzer Driver Types
description: A bitmask that selects which types of buzzers are active.
default_value: 1
range: 0 7
units: 
group: NTF
visual_asset_id: buzzer_types_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Notify/AP_Notify.cpp#L175
---

# Buzzer Driver Types (NTF_BUZZ_TYPES)

## Description
`NTF_BUZZ_TYPES` controls where the "Beeps" come from.

*   **Bit 0 (1): Built-in buzzer.** The standard piezoelectric buzzer connected to the flight controller.
*   **Bit 1 (2): DShot.** Uses the motors themselves to beep! The ESC vibrates the motor windings to create sound.
*   **Bit 2 (4): DroneCAN.** Uses a buzzer on a CAN-bus peripheral (like a GPS puck).

## The Engineer's View
Enabling **DShot (Bit 1)** is extremely useful for finding a lost drone in tall grass ("Lost Model Alarm"). Since the motors are much louder than the small piezo buzzer, this can be a lifesaver.

## Tuning & Behavior
*   **Default Value:** 1 (Built-in)
*   **Recommendation:** Set to **3** (Built-in + DShot) to enable motor beeping.