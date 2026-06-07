---
layout: parameter
name: PTCH2SRV_RMAX_DN
display_name: Pitch Down Max Rate
description: The maximum pitch-down rate (in degrees per second) that the angle controller is allowed to demand.
default_value: 0
range: 0 100
units: deg/s
group: PTCH
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_PitchController.cpp#L48
---

# Pitch Down Max Rate (PTCH2SRV_RMAX_DN)

## Description
`PTCH2SRV_RMAX_DN` limits how fast the nose can push down.

This is critical for preventing negative-G structural failures or engine starvation (if your fuel tank pickup doesn't like negative Gs).
