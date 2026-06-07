---
layout: parameter
name: FS_EKF_FILT
display_name: EKF Failsafe Filter Frequency
description: The low-pass filter frequency (in Hz) applied to the EKF variance monitoring.
default_value: 0.5
range: 0.1 5.0
units: Hz
group: FS
visual_asset_id: filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# EKF Failsafe Filter Frequency (FS_EKF_FILT)

## Description
`FS_EKF_FILT` determines how "Stable" the failsafe trigger is.

The EKF variance is constantly jumping up and down. This parameter smooths those jumps out. 

*   **Higher Value:** Faster reaction. The drone will failsafe immediately if a sensor glitches.
*   **Lower Value:** Slower, more robust reaction. The drone will ignore tiny "Spikes" in variance but will take longer to realize if a sensor has truly failed.