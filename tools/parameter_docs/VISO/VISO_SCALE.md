---
layout: parameter
name: VISO_SCALE
display_name: Visual Odometry Scale Factor
description: A multiplier applied to the position and velocity reported by the vision sensor.
default_value: 1.0
range: 0.1 2.0
units: 
group: VISO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L75
---

# Visual Odometry Scale Factor (VISO_SCALE)

## Description
`VISO_SCALE` allows you to calibrate the "Ruler" used by your vision sensor.

Sometimes, due to camera lens distortion or inaccuracies in the vision algorithm, the sensor might think it has moved 1.0 meters when it has actually moved 1.1 meters. This scaling factor allows you to correct that error so that simulated movement matches real-world distance.

*   **1.0 (Default):** No scaling.
*   **1.1:** Increases the reported distance by 10%.

## Tuning & Behavior
*   **Calibration:** Place the drone on a long measuring tape. Move it manually from 0 to 5 meters. Observe the reported `VISO` position in the GCS. 
    *   $$ \text{Scale} = \frac{\text{Actual Distance}}{\text{Reported Distance}} $$
*   **Note:** If your scale factor is far from 1.0 (e.g. 1.5 or 0.5), it usually indicates a more fundamental problem with the vision sensor's calibration or lens FOV settings.