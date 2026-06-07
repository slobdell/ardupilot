---
layout: parameter
name: SIM_BZ_ENABLE
display_name: Simulation Buzzer Enable
description: Enables the simulated buzzer (beeper) in the SITL environment.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L155
---

# Simulation Buzzer Enable (SIM_BZ_ENABLE)

## Description
`SIM_BZ_ENABLE` activates a virtual beeper.

When enabled, SITL will log and potentially play sound for arming beeps, failsafe warnings, and other audio cues produced by the autopilot. Useful for debugging new melody patterns or verifying failsafe alerts.
