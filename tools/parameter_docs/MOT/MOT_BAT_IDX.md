---
layout: parameter
name: MOT_BAT_IDX
display_name: Battery Compensation Index
description: Selects which battery monitor instance to use for thrust scaling.
default_value: 0
range: 0 9
units: 
group: MOT
visual_asset_id: mot_bat_volt_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_Motors_Thrust_Linearization.cpp#L66
---

# Battery Compensation Index (MOT_BAT_IDX)

## Description
`MOT_BAT_IDX` tells the autopilot which battery it should look at to decide how much to scale the motor power (compensation). 

If you have multiple batteries with separate monitors (e.g., BATT1 for motors, BATT2 for electronics), you must set this to the index of the battery that is actually powering the ESCs/Motors.

*   **0: Battery 1.** (Standard).
*   **1: Battery 2.**
*   **etc.**

## Tuning & Behavior
*   **Default:** 0.
*   **Important:** If you set this to an index that is not enabled (e.g., set to 1 but only BATT1 is configured), the autopilot will not be able to perform voltage compensation, and your throttle feel may vary during the flight.