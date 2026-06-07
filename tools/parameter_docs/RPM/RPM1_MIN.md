---
layout: parameter
name: RPM1_MIN
display_name: Minimum Reported RPM (Sensor 1)
description: The lowest RPM value the sensor will report. Readings below this are treated as 0.
default_value: 10
range: 0 1000
units: RPM
group: RPM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_Params.cpp#L48
---

# Minimum Reported RPM (RPM1_MIN)

## Description
`RPM1_MIN` acts as a "Noise Gate" for the RPM sensor. 

At extremely low speeds or when the motor is stopped, electrical noise on the sensor pin can sometimes look like a valid pulse, causing the GCS to show "Ghost RPM" (e.g. 2 or 3 RPM). This parameter tells the autopilot to ignore any calculated RPM below this value and simply report **0**.

## Tuning & Behavior
*   **Default:** 10 RPM.
*   **Usage:** For large, slow-moving rotors (like on a large helicopter), you might need to lower this to **5**. For high-speed racing motors, you can increase this to **100** or more to ensure a clean zero-reading when disarmed.
*   **Context:** Only applies when using GPIO-based (pulse counting) RPM sensors.