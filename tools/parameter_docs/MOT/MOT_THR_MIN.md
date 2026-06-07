---
layout: parameter
name: MOT_THR_MIN
display_name: Throttle Minimum (Rover/Boat)
description: The minimum throttle percentage the autopilot will apply during autonomous flight.
default_value: 0
range: 0 20
units: %
group: MOT
visual_asset_id: mot_thr_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_Motors/AP_MotorsUGV.cpp#L62
---

# Throttle Minimum (MOT_THR_MIN)

## Description
`MOT_THR_MIN` sets the "Idle" limit for your Rover or Boat's powertrain. 

This is particularly useful for vehicles with Internal Combustion Engines (Gasoline/Nitro), where setting a minimum throttle ensures the engine doesn't stall when the autopilot commands zero speed. It can also be used for electric vehicles to overcome static friction (stiction) in a drivetrain.

*   **0:** (Default). No minimum limit.
*   **10:** Autopilot will never command less than 10% throttle unless disarmed.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** For ICE vehicles, set this to the percentage that maintains a reliable idle. For electric rovers that won't start moving until 5% throttle, set this to **5** to improve responsiveness.
*   **Note:** This only applies to Rover and Boat. For Multicopters, use `MOT_SPIN_ARM`.