---
layout: parameter
name: CRUISE_THROTTLE
display_name: Target Cruise Throttle
description: The estimated throttle percentage required to achieve the target cruise speed.
default_value: 50
range: 0 100
units: %
group: CRUISE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp#L97
---

# Target Cruise Throttle (CRUISE_THROTTLE)

## Description
`CRUISE_THROTTLE` provides the "Feed-Forward" value for the speed controller.

It tells the autopilot: "To go at [CRUISE_SPEED](CRUISE_SPEED.html), you typically need about X% throttle." This gives the controller a starting point. If the vehicle is moving too slowly, the autopilot will increase throttle above this value; if moving too fast, it will decrease it.

## Tuning & Behavior
*   **Default:** 50%.
*   **Calibration:** Drive your vehicle in Manual or Acro mode at your desired cruise speed. Note the throttle percentage shown on your GCS. Enter that value here.
*   **Effect:** A correctly set cruise throttle leads to much smoother acceleration and more stable speed tracking during autonomous missions.