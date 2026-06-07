---
layout: parameter
name: THROW_ALT_MAX
display_name: Throw Mode Max Altitude
description: The maximum height above home allowed for the autopilot to attempt throw detection.
default_value: 0
range: 0 500.0
units: m
group: THROW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L707
---

# Throw Mode Max Altitude (THROW_ALT_MAX)

## Description
`THROW_ALT_MAX` provides an upper safety boundary for Throw Mode. 

This prevents the drone from attempting a launch if it is already at an extreme altitude (e.g., if you are trying to release it from a high-altitude platform and it has already drifted past your safe zone).

*   **0 (Default):** Check is disabled.