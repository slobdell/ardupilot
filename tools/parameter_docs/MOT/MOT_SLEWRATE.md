---
layout: parameter
name: MOT_SLEWRATE
display_name: Throttle Slew Rate
description: Limits the rate of change of the throttle output to prevent mechanical strain or electrical brownouts.
default_value: 100
range: 0 1000
units: %/s
group: MOT
visual_asset_id: mot_slewrate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_Motors/AP_MotorsUGV.cpp#L80
---

# Throttle Slew Rate (MOT_SLEWRATE)

## Description
`MOT_SLEWRATE` acts as a "Smoothing" filter for your throttle. 

It defines how fast the motor power can increase or decrease. A value of 100% means the motor can go from zero to full power in exactly 1 second. This is critical for heavy Rovers or vehicles with high-torque motors where a sudden "punch" of throttle could snap a drive belt, strip a gear, or cause a sudden voltage drop (brownout) that reboots the flight controller.

*   **100:** (Default). 1 second to reach full power.
*   **40:** 2.5 seconds to reach full power. Recommended for high-current vehicles with weak batteries.
*   **0:** Disabled. No smoothing (instant response).

## Tuning & Behavior
*   **Default:** 100.
*   **Mechanical Protection:** If your Rover "jerks" violently when you touch the throttle, reduce this value to **50** or **75**.
*   **Electrical Stability:** If your flight controller reboots during hard acceleration, your battery cannot handle the current spike. Reducing this value will soften the ramp-up and may prevent the reboot.