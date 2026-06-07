---
layout: parameter
name: EK3_OGN_HGT_MASK
display_name: EKF3 Origin Height Mask
description: Controls how the EKF aligns the GPS altitude datum when using non-GPS height sources (like Barometer or Lidar).
default_value: 0
range: 0 7
units: 
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L550
---

# EKF3 Origin Height Mask (EK3_OGN_HGT_MASK)

## Description
`EK3_OGN_HGT_MASK` keeps your "Mean Sea Level" (MSL) altitude accurate even when you are flying using a Barometer or Lidar.

If you fly using `EK3_SRC1_POSZ = 1` (Baro), the EKF tracks your height relative to the takeoff point. However, barometers drift with weather changes. This parameter tells the EKF to use the GPS height (if available) to slowly correct the "Origin" height in the background, so that your logged global altitude remains valid over long flights.

## Tuning & Behavior
*   **Bit 0:** Correct datum when using **Baro** height.
*   **Bit 1:** Correct datum when using **Range Finder** height.
*   **Bit 2:** Apply corrections to **Local Position** (instead of Origin). *Experimental.*

## Recommendation
*   **Default Value:** 0.
*   **Surveying:** If accurate MSL geotags are critical, set Bit 0 (Value 1).