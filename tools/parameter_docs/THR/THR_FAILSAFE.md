---
layout: parameter
name: THR_FAILSAFE
display_name: Throttle Failsafe Enable (Plane)
description: Enables or disables the RC loss failsafe mechanism for fixed-wing aircraft.
default_value: 1
range: 0 2
units: 
group: THR
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L420
---

# Throttle Failsafe Enable (THR_FAILSAFE)

## Description
`THR_FAILSAFE` is the master switch for RC signal loss protection on ArduPlane.

*   **0: Disabled.** The plane will not react to a loss of radio signal. (Highly Dangerous).
*   **1: Enabled (Standard).** Triggers a failsafe action (like RTL) if the throttle signal drops below `THR_FS_VALUE` or if the receiver reports a lost link.
*   **2: Enabled (No Action).** Ignores RC inputs if a failsafe is detected but does not trigger an autonomous return-to-launch.

## Tuning & Behavior
*   **Default:** 1 (Enabled).
*   **Requirement:** Requires [THR_FS_VALUE](THR_FS_VALUE.html) to be calibrated correctly.
*   **Safety:** Always test your failsafe behavior on the ground (with propellers removed) by turning off your transmitter and verifying the flight mode changes to RTL.