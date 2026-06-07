---
layout: parameter
name: SCR_ENABLE
display_name: Scripting Enable
description: Enables the Lua scripting engine for custom autopilot behaviors.
default_value: 0
range: 0 1
units: 
group: SCR
visual_asset_id: scripting_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L40
---

# Scripting Enable (SCR_ENABLE)

## Description
`SCR_ENABLE` activates the internal Lua interpreter.

Lua scripting allows you to add custom features to ArduPilot without needing to recompile the C++ source code. You can write simple scripts to control LEDs, automate complex flight patterns, or interface with unique hardware.

*   **0: Disabled.**
*   **1: Enabled.**

## Tuning & Behavior
*   **Default Value:** 0.
*   **Reboot Required:** Yes.
*   **Requirement:** Scripts must be placed in the `/scripts` folder on the SD card.