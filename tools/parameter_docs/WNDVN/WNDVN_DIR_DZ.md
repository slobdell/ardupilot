---
layout: parameter
name: WNDVN_DIR_DZ
display_name: Wind Vane Analog Deadzone
description: The angular width (in degrees) of the mechanical gap in an analog wind vane's potentiometer.
default_value: 0
range: 0 360
units: deg
group: WNDVN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L105
---

# Wind Vane Analog Deadzone (WNDVN_DIR_DZ)

## Description
`WNDVN_DIR_DZ` compensates for the "Mechanical Gap" found in many analog wind vanes.

Most analog vanes use a simple potentiometer to measure direction. In a full 360-degree rotation, there is usually a tiny physical area where the metal "wiper" inside the sensor isn't touching the resistive track. In this gap, the sensor may output a random or incorrect voltage. This parameter tells the autopilot how many degrees wide that gap is, so it can ignore the data and "Hold" the last known good heading while the vane passes through that sector.

## Tuning & Behavior
*   **Default:** 0.
*   **Calibration:** Rotate the vane slowly. If you see the direction "Jump" wildly at one specific point in the circle, measure the width of that jump in degrees and enter it here.
*   **Note:** Only applicable for **Analog** wind vanes.