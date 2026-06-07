---
layout: parameter
name: BARO1_GND_PRESS
display_name: Ground Pressure (Sensor 1)
description: The calibrated air pressure at the home location.
default_value: 0
range: 0 110000
units: Pa
group: BARO
visual_asset_id: baro_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp#L98
---

# Ground Pressure (BARO1_GND_PRESS)

## Description
`BARO1_GND_PRESS` stores the atmospheric pressure measured when the drone was last "Zeroed" (usually at arming or during the initial power-up). 

The autopilot uses this as the reference (Sea Level equivalent) to calculate relative altitude. 

*   **Units:** Pascals (Pa).
*   **Standard Pressure:** Approximately 101325 Pa.

## The Engineer's View
Stored in `AP_Baro::sensors[0].ground_pressure`. 
It is updated during the ground calibration phase. The EKF uses this value to initialize the altitude state.

## Tuning & Behavior
*   **Default:** 0 (Updated automatically).
*   **Maintenance:** You should not need to edit this manually. If your drone reports a large altitude offset immediately after arming, ensure the barometer is not covered by foam or exposed to direct sunlight/wind.