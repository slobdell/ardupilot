---
layout: parameter
name: WNDVN_DIR_V_MAX
display_name: Wind Vane Max Voltage
description: The maximum analog voltage reported by the wind vane at its 360-degree limit.
default_value: 3.3
range: 0 5.0
units: V
group: WNDVN
visual_asset_id: windvane_pin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L73
---

# Wind Vane Max Voltage (WNDVN_DIR_V_MAX)

## Description
`WNDVN_DIR_V_MAX` calibrates the "End" of the rotation for an **Analog** wind vane.

It defines the voltage that the autopilot should interpret as a full 360-degree rotation. Together with `V_MIN`, it establishes the scaling for the entire rotation circle.

## Tuning & Behavior
*   **Default:** 3.3V.
*   **Calibration:** Rotate the wind vane manually to its mechanical end point and observe the voltage in your GCS. Enter that value here.
*   **Important:** Most analog vanes have a small "Dead Zone" between 359° and 0° where the wiper doesn't touch the resistive track. See [WNDVN_DIR_DZ](WNDVN_DIR_DZ.html) to handle this gap.