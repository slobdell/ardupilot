---
layout: parameter
name: WNDVN_DIR_OFS
display_name: Wind Vane Direction Offset
description: Mechanical offset for the wind vane direction (zero-degree reference).
default_value: 0
range: 0 360
units: deg
group: WNDVN
visual_asset_id: windvane_pin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L82
---

# Wind Vane Direction Offset (WNDVN_DIR_OFS)

## Description
`WNDVN_DIR_OFS` allows you to calibrate your wind vane without having to physically remount it. It defines the angle the sensor reports when the wind is coming directly from the front of the vehicle.

*   **Units:** Degrees.
*   **Calibration:** Point the vehicle directly into the wind and hold the wind vane at its "neutral" position. If the HUD reports 10 degrees, set the offset to -10 (or 350).

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Use this to align the digital "Front" of the sensor with the physical "Front" of your vehicle.