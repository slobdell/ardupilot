---
layout: parameter
name: H_DUAL_MODE
display_name: Dual Heli Rotor Mode
description: Selects the rotor configuration for dual-rotor helicopters (Tandem, Coaxial, Intermeshing).
default_value: 0
range: 0 2
units: 
group: H
visual_asset_id: heli_dual_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Dual.cpp#L25
---

# Dual Heli Rotor Mode (H_DUAL_MODE)

## Description
`H_DUAL_MODE` tells ArduPilot what kind of multi-rotor helicopter you are flying.

Standard helicopters have one main rotor and one tail rotor. "Dual" helicopters use two large rotors to generate lift.

*   **0: Tandem.** Rotors are arranged front-to-back (like a Chinook CH-47).
*   **1: Coaxial.** Two rotors stacked on top of each other on a single shaft.
*   **2: Intermeshing.** Rotors are side-by-side and tilt slightly towards each other (like a K-MAX).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Reboot Required:** Yes.