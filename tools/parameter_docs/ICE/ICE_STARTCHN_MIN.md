---
layout: parameter
name: ICE_STARTCHN_MIN
display_name: Input channel for engine start minimum PWM
description: This is a minimum PWM value for engine start channel for an engine stop to be commanded.
default_value: 0
range: 0 1300
units: PWM
group: ICE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L166
---

# ICE_STARTCHN_MIN: Input channel for engine start minimum PWM

## Description
This is a minimum PWM value for engine start channel for an engine stop to be commanded.

## Values
- **Range:** 0 to 1300
- **Units:** PWM (Microseconds)
- **Default:** 0

## Description
This parameter sets a noise floor for the Engine Start switch.

- **Function:** If you have assigned an RC Channel to `ICE_START_CHAN`, the autopilot monitors it.
- **Logic:** To command an engine stop (Kill), the PWM value must be **Low** (below 1300) but **High enough** to be valid (above `ICE_STARTCHN_MIN`).
- **Use Case:** Prevents a failsafe event or a glitch (where PWM might drop momentarily to 0 or 800) from accidentally killing the engine in flight.

