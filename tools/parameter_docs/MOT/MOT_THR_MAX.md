---
layout: parameter
name: MOT_THR_MAX
display_name: Throttle Maximum (Rover/Boat)
description: The maximum throttle percentage the autopilot will apply.
default_value: 100
range: 30 100
units: %
group: MOT
visual_asset_id: mot_thr_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_Motors/AP_MotorsUGV.cpp#L71
---

# Throttle Maximum (MOT_THR_MAX)

## Description
`MOT_THR_MAX` sets the "Speed Governor" for your Rover or Boat. 

Even if you push the transmitter stick to 100%, the autopilot will limit the actual power sent to the motors to this percentage. This is useful for high-powered vehicles to prevent overheating motors and ESCs, or to make a fast vehicle safer for beginners.

*   **100:** (Default). Full power available.
*   **50:** Half power limit.

## Tuning & Behavior
*   **Default:** 100.
*   **Usage:** If your motors get too hot to touch after a short run, reduce this value to **70** or **80**.
*   **Note:** This only applies to Rover and Boat. For Multicopters, use `MOT_SPIN_MAX`.