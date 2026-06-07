---
layout: parameter
name: SAIL_WNDSPD_MIN
display_name: Sailboat Minimum Wind Speed
description: The wind speed threshold below which the boat will switch from sailing to motoring (if equipped).
default_value: 0
range: 0 5.0
units: m/s
group: SAIL
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/sailboat.cpp#L85
---

# Sailboat Minimum Wind Speed (SAIL_WNDSPD_MIN)

## Description
`SAIL_WNDSPD_MIN` defines the "Calm Water" transition point for autonomous boats.

If the measured wind speed (via [WNDVN_SPEED](WNDVN_SPEED.html)) falls below this value, the autopilot assumes there isn't enough wind to sail effectively. If the boat has an auxiliary motor, the autopilot will engage the motor to maintain its mission speed. If there is no motor, the boat will simply drift or hold position until the wind picks up.

## Tuning & Behavior
*   **Default:** 0 (Always try to sail).
*   **Recommendation:** Set to **0.5 m/s** to **1.0 m/s** to prevent the boat from "Gilled" (stuck with no speed) in very light air.
*   **Dependency:** Requires a functional wind speed sensor and an auxiliary motor if motoring is desired.