---
layout: parameter
name: VISO_QUAL_MIN
display_name: Visual Odometry Minimum Quality
description: The confidence threshold (0-100%) required to trust the visual odometry data.
default_value: 0
range: -1 100
units: %
group: VISO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L115
---

# Visual Odometry Minimum Quality (VISO_QUAL_MIN)

## Description
`VISO_QUAL_MIN` defines the "Certainty Threshold" for your vision-based position data.

Computer vision systems (like the T265) report a "Confidence" score along with their position. In low light or over featureless surfaces (like smooth white floors), the system may become "lost" and start reporting random or drift-prone data. This parameter tells the autopilot to reject any vision data if the confidence falls below this level.

*   **0 (Default):** Use data if the sensor thinks it's okay.
*   **50:** Reject data if the sensor is less than 50% sure.
*   **-1:** Trust all data, even if the sensor says it is failed (DANGEROUS).

## Tuning & Behavior
*   **Recommendation:** Set to **50** or higher for safety. If the vision system fails this quality check, the autopilot will fall back to GPS (if available) or trigger an EKF failsafe.