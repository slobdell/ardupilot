---
layout: parameter
name: RPM1_MAX
display_name: Maximum Reported RPM (Sensor 1)
description: The highest RPM value the sensor is allowed to report. Readings above this are discarded.
default_value: 100000
range: 0 200000
units: RPM
group: RPM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_Params.cpp#L41
---

# Maximum Reported RPM (RPM1_MAX)

## Description
`RPM1_MAX` is a safety filter to prevent "Spikes" or unrealistic data from affecting the autopilot.

Electrical interference or a loose sensor wire can sometimes cause a burst of pulses that look like the motor is spinning at an impossibly high speed (e.g. 500,000 RPM). If the autopilot used this data for a governor or dynamic notch filter, it could cause a crash. This parameter sets the "sanity limit" – any reading higher than this is ignored.

## Tuning & Behavior
*   **Default:** 100,000 RPM.
*   **Recommendation:** Set this to roughly **20% higher** than your motor's maximum possible physical RPM. For most small multicopters, 50,000 is plenty. For large gas engines, 10,000 might be appropriate.
*   **Context:** Only applies when using GPIO-based (pulse counting) RPM sensors.