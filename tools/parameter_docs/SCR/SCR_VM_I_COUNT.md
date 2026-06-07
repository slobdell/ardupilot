---
layout: parameter
name: SCR_VM_I_COUNT
display_name: Scripting Instruction Count
description: The maximum number of Lua instructions allowed to execute in a single time slice.
default_value: 10000
range: 1000 100000
units: 
group: SCR
visual_asset_id: scripting_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L41
---

# Scripting Instruction Count (SCR_VM_I_COUNT)

## Description
`SCR_VM_I_COUNT` acts as a "Speed Governor" for scripts to ensure they don't slow down the flight control loops.

If a script enters an infinite loop or tries to do too much math at once, the autopilot will pause the script after it reaches this many instructions, allowing the main flight stabilization code to run.

*   **Default:** 10,000 instructions.
*   **Recommendation:** Leave at default unless you have a very complex script that is triggering "Scripting: slow" warnings.