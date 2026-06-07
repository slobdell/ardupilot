---
layout: parameter
name: SIM_FTOWESC_ENA
display_name: Simulation FETtec OneWire ESC Enable
description: Enables the simulation of FETtec OneWire protocol ESCs.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L128
---

# Simulation FETtec OneWire ESC Enable (SIM_FTOWESC_ENA)

## Description
`SIM_FTOWESC_ENA` activates the virtual FETtec OneWire interface.

This allows you to test the [SERVO_FTW_MASK](../SERVO/SERVO_FTW_MASK.html) configuration and RPM telemetry feedback without having a physical FETtec ESC board connected.
