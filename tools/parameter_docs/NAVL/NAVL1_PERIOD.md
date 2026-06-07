---
layout: parameter
name: NAVL1_PERIOD
display_name: L1 Navigation Period
description: Sets the "Look-Ahead" responsiveness for the L1 navigation controller.
default_value: 17
range: 1 60
units: s
group: NAVL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_L1_Control/AP_L1_Control.cpp#L15
---

# L1 Navigation Period (NAVL1_PERIOD)

## Description
`NAVL1_PERIOD` is the primary tuning knob for how your plane or rover follows a line.

ArduPilot's **L1 controller** works by picking a point on the path ahead of the vehicle and steering toward it. This parameter effectively sets the distance to that point.

*   **Lower Value (e.g. 10):** Very aggressive tracking. The drone will stick to the line tightly and make sharp turns.
*   **Higher Value (e.g. 25):** Soft, smooth tracking. The drone will wander more from the line but the flight will be much more stable.

## Tuning & Behavior
*   **Default:** 17.
*   **Recommendation:** For small agile planes, use **12 to 15**. For large, slow planes, use **20 to 25**.
*   **Warning:** If you set this too low, the aircraft will oscillate (weaving) rapidly across the path.