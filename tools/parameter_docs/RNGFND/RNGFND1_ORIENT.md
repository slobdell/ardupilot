---
layout: parameter
name: RNGFND1_ORIENT
display_name: Rangefinder orientation (Sensor 1)
description: The direction the rangefinder is pointing relative to the vehicle's body frame.
default_value: 25
range: 0 25
units: 
group: RNGFND
visual_asset_id: rngfnd_orientation_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L139
---

# Rangefinder orientation (RNGFND1_ORIENT)

## Description
`RNGFND1_ORIENT` defines the pointing vector of the distance sensor. 

Correct orientation is vital for the EKF and flight controllers to know whether they are measuring altitude (Down), distance to an obstacle (Forward/Side), or height above the vehicle (Up).

*   **25: Down.** (Most common). Used for altitude hold and precision landing.
*   **0: Forward.** Used for simple object avoidance.
*   **24: Up.** Used for ceiling-following or indoor flight.

## Tuning & Behavior
*   **Default:** 25 (Down).
*   **Warning:** If the orientation is set incorrectly (e.g., set to Forward when pointing Down), the drone may attempt to "climb" to avoid what it thinks is an obstacle in front of it.