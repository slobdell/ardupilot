---
layout: parameter
name: SERVO_BLH_TRATE
display_name: BLHeli Telemetry Rate
description: The rate (in Hz) at which the ESC sends telemetry data back to the autopilot.
default_value: 10
range: 0 100
units: Hz
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Telemetry Rate (SERVO_BLH_TRATE)

## Description
`SERVO_BLH_TRATE` controls how often the ESC reports Voltage, Current, RPM, and Temperature.

## Tuning & Behavior
*   **Default Value:** 10 Hz.
*   **Recommendation:** Set to **10 Hz** for general monitoring. Higher rates are not needed unless you are doing detailed analysis, and they can clog the serial port.