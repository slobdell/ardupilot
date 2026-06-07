---
layout: parameter
name: EK3_EAS_I_GATE
display_name: EKF3 Airspeed Innovation Gate
description: The number of standard deviations allowed before an airspeed measurement is rejected by the EKF.
default_value: 400
range: 100 1000
units: '%'
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Airspeed Innovation Gate (EK3_EAS_I_GATE)

## Description
`EK3_EAS_I_GATE` prevents the EKF from trusting bad airspeed data.

Pitot tubes can get clogged with rain or bugs. If the airspeed sensor reports a value that disagrees wildly with the GPS and IMU (e.g., claiming 100m/s when the GPS says 0), this gate rejects the reading to prevent the plane from stalling or diving.

## Tuning & Behavior
*   **Default Value:** 400 (4 Sigma).
*   **Recommendation:** Set to **300** for better protection against bad sensors.