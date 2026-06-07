---
layout: parameter
name: BARO_PRIMARY
display_name: "Primary barometer"
description: "Selects which barometer will be the primary if multiple barometers are found."
default_value: 0
range: 0 2
units: "Option"
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L125
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Primary barometer (BARO_PRIMARY)

## Description
This parameter selects the "Master" barometer instance to be used for altitude estimation. Many modern flight controllers have multiple barometers (one internal and one or more external via CAN or I2C) for redundancy. 

The primary barometer is the one whose data is prioritized by the EKF (Extended Kalman Filter) and reported to the pilot as the official barometric altitude.

## The Mathematics
This is a simple index selection ($i$):
*   **0:** 1st Baro (Instance 0)
*   **1:** 2nd Baro (Instance 1)
*   **2:** 3rd Baro (Instance 2)

## The Engineer's View
In `AP_Baro::update()`, the logic selects the index stored in `_primary_baro`.
If the selected barometer becomes unhealthy during flight, ArduPilot has a failover mechanism that will automatically switch to the first healthy sensor it finds. However, `BARO_PRIMARY` defines the starting preference.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** If you have an external, high-precision barometer (e.g., inside a GPS module mounted away from wind/prop wash), set this to that instance number (often 1).
*   **Detection:** You can check which barometer is which by looking at the `HWID` or `ID` logs, or by blowing on the sensors and watching the `BARO[x]` altitude response in your Ground Control Station's status tab.

