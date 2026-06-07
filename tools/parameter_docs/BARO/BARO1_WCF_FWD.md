---
layout: parameter
name: BARO1_WCF_FWD
display_name: Baro Wind Compensation Forward (Sensor 1)
description: Coefficient to correct barometer errors caused by forward airflow.
default_value: 0
range: -1.0 1.0
units: 
group: BARO
visual_asset_id: baro_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro_Wind.cpp#L22
---

# Baro Wind Compensation Forward (BARO1_WCF_FWD)

## Description
`BARO1_WCF_FWD` compensates for the "Pressure Hull" effect. 

When a drone flies forward at high speed, air can pile up or create a vacuum around the barometer sensor (depending on the fuselage shape and venting). This creates a false pressure reading, making the drone think it is climbing or diving when it is actually level. This coefficient allows the EKF to use airspeed/acceleration data to cancel out this error.

*   **Positive Value:** Corrects for high pressure (compression).
*   **Negative Value:** Corrects for low pressure (suction).

## Tuning & Behavior
*   **Default:** 0.
*   **Tuning:** Fly at high speed in a straight line. If the drone loses altitude as it speeds up (thinking it is higher than it is), adjust this coefficient until the altitude remains steady.
*   **Dependencies:** Requires a functional EKF3 and correctly configured drag coefficients.