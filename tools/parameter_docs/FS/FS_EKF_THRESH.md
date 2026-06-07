---
layout: parameter
name: FS_EKF_THRESH
display_name: EKF Failsafe Threshold
description: The maximum allowed variance in the Extended Kalman Filter (EKF) before a failsafe is triggered.
default_value: 0.8
range: 0.6 1.0
units: 
group: FS
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# EKF Failsafe Threshold (FS_EKF_THRESH)

## Description
`FS_EKF_THRESH` is the "Trust Limit" for your drone's brain.

The EKF merges data from the GPS, Compass, and IMU. It is constantly checking if these sensors agree with each other. If they don't (e.g. because the compass is glitching or the GPS has high interference), the EKF "Variance" increases.

*   **Higher Value (1.0):** More tolerant. The drone will keep flying even if the sensors are slightly inconsistent.
*   **Lower Value (0.6):** More sensitive. The drone will trigger a failsafe early if it detects any sensor disagreement.

## Tuning & Behavior
*   **Default Value:** 0.8.
*   **Recommendation:** Leave at **0.8**. If you are flying in an area with a lot of magnetic interference (near steel buildings), you might need to increase this slightly, but be aware that the drone's position will be less accurate.
*   **Action:** When this threshold is exceeded, the drone will trigger the action set in [FS_EKF_ACTION](FS_EKF_ACTION.html) (usually Landing or switching to a non-GPS mode).