---
layout: parameter
name: RUDDER_ONLY
display_name: "Rudder only aircraft"
description: "Enable rudder only mode for 2-channel aircraft"
default_value: 0
range: 0 1
units: ""
group: Rudder
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L628
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Rudder only aircraft (RUDDER_ONLY)

## Description
This parameter configures ArduPlane for "2-Channel" aircraft (Throttle + Rudder/Elevator) that lack ailerons, such as polyhedral gliders or vintage designs. When enabled, the autopilot's roll control logic drives the rudder servo instead of aileron servos to turn the aircraft.

## The Mathematics
The roll controller output (PID) is re-routed:
$$ \text{Rudder Output} = \text{Yaw Control} + \text{Roll Control} \times \text{KFF_RDDRMIX} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`.
*   **Setup:** The transmitter's Aileron stick should be mapped to the `RCMAP_YAW` channel. The Rudder servo connects to the Yaw output.
*   **Constraint:** Ground steering logic is disabled or altered in this mode.
*   **Damping:** Requires `YAW2SRV_DAMP` tuning to prevent oscillation.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **1:** Enable Rudder Only mode.
*   **Note:** You must ensure `KFF_RDDRMIX` is set (typically 1.0) for the roll controller to have authority over the rudder.