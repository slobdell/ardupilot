---
layout: parameter
name: SCR_USER_FLOAT
display_name: Scripting User Parameter (Float)
description: A general-purpose floating point parameter for use by Lua scripts.
default_value: 0
range: 
units: 
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/UserParameters.cpp#L12
---

# Scripting User Parameter (SCR_USER_FLOAT)

## Description
`SCR_USER_FLOAT` (and its INT8/INT16 cousins) provides a way for **Lua Scripts** to have their own configurable settings in the standard parameter list.

Since ArduPilot supports custom user-written scripts, those scripts often need variables that the user can change (like a timer duration or a sensitivity factor). These "User Parameters" are placeholders that the scripts can read and write.

## Tuning & Behavior
*   **Usage:** Only relevant if you have a Lua script installed on your drone that is designed to use these parameters. Consult the documentation for your specific script to see what value to enter here.