---
layout: parameter
name: ICE_ENABLE
display_name: ICEngine Enable
description: Enables the internal combustion engine (ICE) control state machine.
default_value: 0
range: 0 1
units: 
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L40
---

# ICEngine Enable (ICE_ENABLE)

## Description
`ICE_ENABLE` activates the dedicated control logic for gas and nitro engines.

When enabled, ArduPilot moves beyond simple throttle control and activates a formal state machine to manage the **Ignition** and **Starter** sequences. It allows the autopilot to autonomously start the engine for a mission, maintain a steady idle on the ground, and monitor for "uncommanded stops" (flame-outs) using an RPM sensor.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Reboot Required:** Yes.
*   **Integration:** Once enabled, you must assign servo functions to your ignition (`k_ignition`) and starter (`k_starter`) channels.