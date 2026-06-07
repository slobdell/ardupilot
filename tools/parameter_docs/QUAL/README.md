# Quality Thresholds (QUAL)

## Overview
The **QUAL** parameter group (specifically `QUAL_MIN` or `FLOW_QUAL_MIN`) defines the confidence requirements for visual sensors.

## Key Concepts

### 1. Optical Flow Quality
Optical Flow sensors (like the PX4Flow or HereFlow) output a "Quality" score (0-255) for every sample. This score indicates how many distinct features the camera can see and track on the ground.
*   **`QUAL_MIN`**: The minimum acceptable quality score.
*   **Action:** If the live quality drops below this threshold (due to low light or flying over water/sand), the autopilot will reject the flow data and trigger a failsafe (usually falling back to AltHold mode).

## Developer Notes
*   **Library:** `libraries/AP_OpticalFlow`.
*   **Tuning:** If you find your drone constantly dropping out of Loiter indoors, check the logs for `QUAL`. You may need to lower the threshold or improve lighting.