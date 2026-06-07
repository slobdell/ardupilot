---
layout: parameter
name: SCR_HEAP_SIZE
display_name: Scripting Heap Size
description: The amount of RAM (in bytes) dedicated to the Lua scripting engine.
default_value: 40960
range: 10240 1000000
units: bytes
group: SCR
visual_asset_id: scripting_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L42
---

# Scripting Heap Size (SCR_HEAP_SIZE)

## Description
`SCR_HEAP_SIZE` defines the memory limit for your Lua scripts.

If your scripts are large or use many complex variables, they may run out of memory. This parameter allows you to allocate more of the flight controller's RAM to the scripting engine.

## Tuning & Behavior
*   **Default Value:** Usually 40,960 bytes (40 KB).
*   **Constraint:** On memory-constrained boards (like those with only 1MB flash), you may not be able to increase this significantly. High-end boards (Cube Orange) can support much larger values.
