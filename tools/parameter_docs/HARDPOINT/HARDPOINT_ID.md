---
layout: parameter
name: HARDPOINT_ID
display_name: "Hardpoint ID"
description: "UAVCAN/DroneCAN Hardpoint ID"
default_value: 0
range: 0 15
units: ""
group: HARDPOINT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L383
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Hardpoint ID (HARDPOINT_ID)

## Description
This parameter assigns a specific ID to the PWM output of a DroneCAN peripheral, designating it as a "Hardpoint" (e.g., a weapon release, magnet, or gripper). The flight controller can then actuate this specific output by sending a matching DroneCAN hardpoint command.

## The Mathematics
ID Matching:
$$ \text{Actuate} \iff \text{Command.ID} == \text{HARDPOINT_ID} $$

## The Engineer's View
Defined in `Tools/AP_Periph/Parameters.cpp`. Enables the `uavcan.equipment.hardpoint` subscriber.

## Tuning & Behavior
*   **Default Value:** 0
*   **Usage:** Set unique IDs for different mechanisms (e.g., Left Wing Release = 1, Right Wing Release = 2).