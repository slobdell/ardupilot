---
layout: parameter
name: SIM_RFL_OPTS
display_name: Simulation RealFlight Options
description: Bitmask for various options when using the RealFlight simulator link.
default_value: 1
range: 0 7
units: 
group: SIM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_FlightAxis.cpp#L48
---

# Simulation RealFlight Options (SIM_RFL_OPTS)

## Description
`SIM_RFL_OPTS` provides advanced control over the communication between ArduPilot SITL and the **RealFlight** simulator (FlightAxis).

*   **Bit 0 (1): Reset Position.** If enabled, ArduPilot will command RealFlight to reset the aircraft position to the runway whenever the SITL instance is rebooted or reset.
*   **Bit 1 (2): Use MAVLink State.**

## Tuning & Behavior
*   **Default:** 1 (Reset Position enabled).
*   **Note:** This is only relevant if you are using ArduPilot SITL in "RealFlight mode" (e.g. running `sim_vehicle.py -v ArduPlane -f realflight`).