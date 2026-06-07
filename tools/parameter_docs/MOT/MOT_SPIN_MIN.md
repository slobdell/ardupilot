---
layout: parameter
name: MOT_SPIN_MIN
display_name: Motor Spin minimum
description: The minimum throttle output to the motors during flight.
default_value: 0.15
range: 0.0 0.3
units: 
group: MOT
visual_asset_id: mot_spin_min_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L116
---

# Motor Spin minimum (MOT_SPIN_MIN)

## Description
`MOT_SPIN_MIN` sets the lower limit for the throttle during active flight. Even if you cut the throttle stick to zero (while armed and not landed), the motors will not spin slower than this value.

**Critical Safety Function:** This prevents the motors from stalling or desyncing during aggressive maneuvers or rapid descents. If the props spin too slowly in the airflow, the ESC might lose synchronization, causing the motor to stop and the drone to tumble.

## The Mathematics
The throttle output sent to the ESC is clamped:
$$ \text{Output} \ge \text{MOT\_SPIN\_MIN} $$
(Scaled by PWM/DShot range).

## The Engineer's View
Must be higher than `MOT_SPIN_ARM`.
Ideally, this is set to the lowest RPM where the motor still produces reliable, non-stuttering thrust under load (prop wash).

## Tuning & Behavior
*   **Default Value:** 0.15 (15%)
*   **Range:** 0.0 - 0.3 (0% - 30%)
*   **Recommendation:**
    *   **5" Racing Quad:** 0.07 - 0.10 (7-10%).
    *   **Large (15"+) Props:** 0.15 - 0.20 (15-20%). Large props have high inertia and stall easily in turbulent air.
    *   **Rule of Thumb:** Set `MOT_SPIN_MIN` = `MOT_SPIN_ARM` + 0.03 (at least 3% higher).
*   **Symptoms of Low Setting:** "Desyncs" or death-rolls at the bottom of a dive or flip.
*   **Symptoms of High Setting:** Drone won't descend quickly (floaty).