---
layout: parameter
name: EK3_SRC1_VELZ
display_name: Vertical Velocity Source (Set 1)
description: Selects the primary source of vertical velocity data for the EKF3.
default_value: 3
range: 0 6
units: 
group: EK3
visual_asset_id: ekf_source_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF/AP_NavEKF_Source.cpp#L52
---

# Vertical Velocity Source (EK3_SRC1_VELZ)

## Description
`EK3_SRC1_VELZ` defines where the Extended Kalman Filter (EKF) gets its vertical velocity (climb/descent rate) information. 

Correct vertical velocity is essential for altitude hold and vertical position control. Most GPS modules provide a high-quality vertical velocity measurement based on Doppler shift, which is more responsive than deriving velocity from pressure changes (Barometer).

*   **0: None.**
*   **3: GPS.** (Standard for most outdoor drones).
*   **4: Beacon.**
*   **6: ExternalNav.** (For VIO or OptiTrack systems).

## Tuning & Behavior
*   **Default:** 3 (GPS).
*   **Indoor Flight:** If flying indoors without GPS, this is typically set to **0** or provided by **ExternalNav**.