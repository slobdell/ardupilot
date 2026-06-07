---
layout: parameter
name: SAIL_ANGLE_MAX
display_name: Sail Maximum Angle
description: The angle between the vehicle centerline and the boom when the sail is fully let out.
default_value: 90
range: 0 90
units: deg
group: SAIL
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/sailboat.cpp#L49
---

# Sail Maximum Angle (SAIL_ANGLE_MAX)

## Description
`SAIL_ANGLE_MAX` defines the mechanical limit of your sailboat's rig. 

It represents the angle of the boom relative to the boat's longitudinal axis when the mainsheet servo is at its maximum travel (loose). This value is used by the sailing controller to calculate how much to "Sheet In" or "Sheet Out" based on the wind direction.

*   **Standard Setting:** 90 degrees (Boom can swing fully perpendicular to the boat).

## Tuning & Behavior
*   **Default:** 90.
*   **Measurement:** Let your mainsheet out completely and measure the angle of the boom. If your rigging prevents the boom from reaching 90 degrees (e.g. hitting the shrouds), enter the actual maximum angle here.
*   **Note:** For rotating masts (wing sails), this parameter defines the rotation limit.