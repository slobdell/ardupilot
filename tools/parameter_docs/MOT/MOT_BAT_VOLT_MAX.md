---
layout: parameter
name: MOT_BAT_VOLT_MAX
display_name: Battery voltage compensation maximum voltage
description: The battery voltage at which no thrust scaling is applied (full charge).
default_value: 0
range: 6 53
units: V
group: MOT
visual_asset_id: mot_bat_volt_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L64
---

# Battery voltage compensation maximum voltage (MOT_BAT_VOLT_MAX)

## Description
`MOT_BAT_VOLT_MAX` helps your drone feel consistent from the start to the end of a battery pack.

At 16.8V (full charge), your motors produce more thrust for 50% throttle than they do at 14.0V (empty). This parameter tells the autopilot what "Full Voltage" looks like so it can scale the throttle output down slightly at the start of the flight to match the performance at the end.

## The Mathematics
$$ \text{Scale Factor} = \frac{\text{Current Voltage}}{\text{MOT\_BAT\_VOLT\_MAX}} $$

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **4.2V * Cell Count**.
    *   **4S:** 16.8V
    *   **6S:** 25.2V
*   **Benefit:** Makes your PID tuning valid for the entire flight, preventing "oscillations at takeoff" (due to high voltage) and "sluggishness at landing" (due to low voltage).