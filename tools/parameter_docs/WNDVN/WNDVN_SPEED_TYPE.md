---
layout: parameter
name: WNDVN_SPEED_TYPE
display_name: Wind Speed Sensor Type
description: Selects the hardware or method for determining wind speed (anemometer).
default_value: 0
range: 0 11
units: 
group: WNDVN
visual_asset_id: windvane_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L122
---

# Wind Speed Sensor Type (WNDVN_SPEED_TYPE)

## Description
`WNDVN_SPEED_TYPE` enables the measurement of wind speed (Anemometer). 

This is critical for sailboats to calculate "True Wind" and for any vehicle that needs to record local weather conditions. If enabled, the autopilot will use this data to improve navigation and sail control.

*   **0: None.** No wind speed sensor.
*   **1: Airspeed Library.** Uses the drone's existing pitot tube.
*   **2: Modern Devices.** (Analog).
*   **3: RPM Library.** Calculates wind speed based on the rotation rate of a cup-style anemometer.
*   **4: NMEA.**

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Integration:** If using an analog sensor, you must also set [WNDVN_SPEED_PIN](WNDVN_SPEED_PIN.html).