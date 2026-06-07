---
layout: parameter
name: PLDP_RNG_MAX
display_name: Payload-Place Max Range
description: The maximum altitude (in meters) at which the autopilot will use the rangefinder to detect payload touchdown.
default_value: 0
range: 0 100
units: m
group: PLDP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L1185
---

# Payload-Place Max Range (PLDP_RNG_MAX)

## Description
`PLDP_RNG_MAX` is a configuration setting for the **Payload Place** autonomous mission command.

In "Payload Place" mode, the drone descends until it detects that the package has touched the ground. This detection relies on a rangefinder (Lidar) to see how far away the ground is. This parameter tells the autopilot: "Only start looking for the ground when the rangefinder says we are closer than this height."

*   **0:** Disabled.
*   **Value (m):** The height threshold (e.g. 5.0m) to begin the final placement phase.

## Tuning & Behavior
*   **Safety:** This prevents the drone from misinterpreting rangefinder "noise" at high altitudes as a landing event.