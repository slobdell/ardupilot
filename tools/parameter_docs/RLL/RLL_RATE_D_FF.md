---
layout: parameter
name: RLL_RATE_D_FF
display_name: Roll Derivative Feed-Forward
description: A feed-forward gain based on the rate of change of the target rate. Improves response to aggressive stick movements.
default_value: 0
range: 0 0.03
units: 
group: RLL
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Derivative Feed-Forward (RLL_RATE_D_FF)

## Description
`RLL_RATE_D_FF` acts like an "Inertia Override."

When you flick the stick quickly, the autopilot sees a rapid change in your command. This parameter injects extra power immediately to overcome the drone's inertia and start the roll faster than a standard PID loop could.