---
layout: parameter
name: FS_PILOT_INPUT
display_name: Pilot Input Failsafe Action
description: Selects the autonomous action taken if no stick input is received within the timeout period.
default_value: 0
range: 0 2
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L136
---

# Pilot Input Failsafe Action (FS_PILOT_INPUT)

## Description
`FS_PILOT_INPUT` defines the vehicle's "Dead Man's Switch" behavior.

This is primarily used for **ArduSub** (underwater ROVs). Since these vehicles are often tethered, a loss of communication can happen. If the flight controller doesn't see any stick movement or heartbeat from the pilot for a certain amount of time, it assumes the pilot is incapacitated or the link is broken.

*   **0: Disarm/Disable.** Stops motors immediately.
*   **1: Hold.** (Recommended). Maintains current depth and position.
*   **2: Surface.** Commanded ascent to the surface.

## Tuning & Behavior
*   **Default:** 0.
*   **Requirement:** Requires [FS_PILOT_TIMEOUT](FS_PILOT_TIMEOUT.html) to be set.
*   **Safety:** For ROVs, **Hold (1)** is usually the safest option to prevent the tether from becoming tangled in a prop while the vehicle "Ghost drifts."