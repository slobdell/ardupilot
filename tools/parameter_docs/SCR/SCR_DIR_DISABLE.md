---
layout: parameter
name: SCR_DIR_DISABLE
display_name: Scripting Directory Disable
description: Disables the script directory scan on specific directories.
default_value: 0
range: 0 1
units: 
group: SCR
visual_asset_id: scripting_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L135
---

# Scripting Directory Disable (SCR_DIR_DISABLE)

## Description
`SCR_DIR_DISABLE` is a security and performance setting for the Lua engine.

It prevents the flight controller from searching certain directories on the SD card for scripts.

*   **0:** Scan all standard locations.
*   **1:** Disable advanced directory scanning.

## Tuning & Behavior
*   **Recommendation:** Leave at **0** for standard users.