---
layout: parameter
name: YAW_SLEW_TIME
display_name: Yaw Slew Time
description: The minimum time (in seconds) for the tracker to complete a full 360-degree rotation.
default_value: 2
range: 0 20
units: s
group: YAW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/AntennaTracker/Parameters.cpp#L44
---

# Yaw Slew Time (YAW_SLEW_TIME)

## Description
`YAW_SLEW_TIME` acts as a speed governor for the Antenna Tracker's pan axis.

It forces the tracker to move smoothly between targets rather than snapping instantly. This reduces mechanical stress on the gears and prevents the heavy high-gain antenna from wobbling when it stops.

*   **0:** Unlimited speed (Servo max speed).
*   **2 (Default):** Takes at least 2 seconds to do a full rotation.

## Tuning & Behavior
*   **Recommendation:** Increase this value if you have a heavy antenna array. Smoother movement is generally better for video link quality than jerky tracking.