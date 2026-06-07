---
layout: parameter
name: SIM_SERVO_DELAY
display_name: Simulated Servo Delay
description: The additional signal delay (in seconds) added to all simulated servo commands.
default_value: 0
range: 0 0.1
units: s
group: SIM
visual_asset_id: sim_lag_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/ServoModel.cpp#L25
---

# Simulated Servo Delay (SIM_SERVO_DELAY)

## Description
`SIM_SERVO_DELAY` simulates the processing lag of digital servos or PWM signal propagation.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **0.05** (50ms). You will likely see the drone start to wobble as the control loop becomes unstable due to the lag.