---
layout: parameter
name: EK3_GSF_RST_MAX
display_name: EKF3 GSF Reset Count Max
description: The maximum number of times the EKF is allowed to reset its yaw to the GSF estimate during a single flight.
default_value: 2
range: 1 10
units: 
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L633
---

# EKF3 GSF Reset Count Max (EK3_GSF_RST_MAX)

## Description
`EK3_GSF_RST_MAX` is a safety limit for the Emergency Yaw Recovery system.

The Gaussian Sum Filter (GSF) is a backup system that tries to figure out the drone's heading using GPS movement if the compass fails. If the main EKF detects a "Compass Variance" (Heading Error), it can perform an emergency reset to align with the GSF's estimate. This parameter limits how many times it can do this per flight.

*   **Why Limit It?** If the GSF keeps triggering resets, something is fundamentally wrong (e.g. GPS glitching). Infinite resets could cause the drone to spin uncontrollably. Limiting it forces the drone to eventually fail-safe (Land) rather than constantly jumping its heading.

## The Engineer's View
Defined in `AP_NavEKF3` as `_gsfResetMaxCount`.
This counter is incremented every time `resetYawToGSF()` is successfully called. Once the limit is reached, the EKF will refuse further corrections from the GSF, likely leading to a "EKF Compass Variance" failsafe if the primary compass is still bad.

## Tuning & Behavior
*   **Default Value:** 2.
*   **Recommendation:** Leave at **2**. If your drone needs to reset its heading more than twice in one flight, you should not be flying.
*   **Debug:** Set to **10** only if you are testing the GSF algorithm itself and want to force multiple resets.
