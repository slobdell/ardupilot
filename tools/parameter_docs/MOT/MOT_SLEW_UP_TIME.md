---
layout: parameter
name: MOT_SLEW_UP_TIME
display_name: Output slew time for increasing throttle
description: The time (in seconds) it takes to ramp the motor output from 0% to 100% throttle.
default_value: 0
range: 0 0.5
units: s
group: MOT
visual_asset_id: mot_slew_time_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L133
---

# Output slew time for increasing throttle (MOT_SLEW_UP_TIME)

## Description
`MOT_SLEW_UP_TIME` prevents the flight controller from demanding impossible acceleration from the motors.

Large propellers (15"+) have significant inertia. If you command them to go from 10% to 90% throttle instantly, they physically can't do it. This causes the PID loop to "wind up" because it thinks the motor isn't responding. By telling ArduPilot how long the motor *actually* takes to spin up, the PID controller waits patiently, resulting in much better stability.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:**
    *   **5-10" Props:** 0.0 (Disabled).
    *   **15-20" Props:** 0.15s.
    *   **28"+ Props:** 0.3s.