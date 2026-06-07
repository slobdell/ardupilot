---
layout: parameter
name: MOT_THST_ASYM
display_name: Motor Thrust Asymmetry
description: Compensates for the difference between forward and reverse thrust on skid-steer rovers.
default_value: 1.0
range: 1.0 10.0
units: 
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_Motors/AP_MotorsUGV.cpp#L119
---

# Motor Thrust Asymmetry (MOT_THST_ASYM)

## Description
`MOT_THST_ASYM` is a calibration factor for **Skid-Steer** (tank-tread style) vehicles. 

Most electric motors and propellers/tires are significantly more efficient when spinning forward than backward. If you apply the same PWM signal to both directions, the vehicle might move much slower in reverse than it does forward. This parameter allows the autopilot to "Boost" the reverse power so that the vehicle's speed and steering response remain consistent in both directions.

*   **1.0 (Default):** Symmetric. Forward and reverse thrust are treated as equal.
*   **2.0:** High Asymmetry. Autopilot will command twice as much signal to achieve the same thrust in reverse.

## Tuning & Behavior
*   **Calibration:** Drive your rover in a straight line at a constant speed forward, then reverse. If reverse is much slower, increase this value until the speeds match.
*   **Note:** This only applies to Rover and Boat frames with skid-steering enabled.