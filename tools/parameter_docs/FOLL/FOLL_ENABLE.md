---
layout: parameter
name: FOLL_ENABLE
display_name: Follow Mode Enable
description: Enables the "Follow Me" capability for chasing a target vehicle or person.
default_value: 0
range: 0 1
units: 
group: FOLL
visual_asset_id: follow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L100
---

# Follow Mode Enable (FOLL_ENABLE)

## Description
`FOLL_ENABLE` activates the dedicated control logic for chasing a target.

When enabled, the drone can receive position data from another vehicle (Lead drone) or a GCS-enabled device (like a phone in your pocket) and automatically fly to maintain a specific distance and orientation relative to that target.

*   **0: Disabled.**
*   **1: Enabled.**

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Requirement:** You must also set the Target's MAVLink System ID in [FOLL_SYSID](FOLL_SYSID.html).