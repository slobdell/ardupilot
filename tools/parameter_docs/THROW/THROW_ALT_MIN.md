---
layout: parameter
name: THROW_ALT_MIN
display_name: Throw Mode Min Altitude
description: The minimum height above home required for the autopilot to attempt throw detection.
default_value: 0
range: 0 50.0
units: m
group: THROW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L700
---

# Throw Mode Min Altitude (THROW_ALT_MIN)

## Description
`THROW_ALT_MIN` is a safety filter for **Throw Mode**. 

It prevents the motors from starting if the drone thinks it is too close to the ground. This protects the pilot's hands and the drone if it is accidentally bumped while sitting on the floor.

*   **0 (Default):** Check is disabled.
*   **Value (m):** The drone must be at least this high (e.g. 1.5 meters) before the "Throw" detection logic becomes active.