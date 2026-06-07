---
layout: parameter
name: SYSID_TARGET
display_name: "Target vehicle's MAVLink system ID"
description: "The MAVLink System ID of the vehicle to track"
default_value: 0
range: 0 255
units: ""
group: SYSID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L35
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Target vehicle's MAVLink system ID (SYSID_TARGET)

## Description
This parameter tells the Antenna Tracker which MAVLink stream to listen to. In a swarm environment or at a flying field with multiple drones, this ensures your tracker points at *your* drone, not someone else's.

## The Mathematics
MAVLink Message Filter:
$$ \text{Accept Packet} \iff (\text{Packet.SysID} == \text{SYSID_TARGET}) \lor (\text{SYSID_TARGET} == 0) $$

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`.
*   **0 (Auto):** The tracker will lock onto the first vehicle it receives a heartbeat from. Convenient for solo operations.
*   **1-255:** The tracker will strictly ignore all MAVLink traffic except that from the specified System ID.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Set to match your vehicle's `SYSID_THISMAV` (usually 1) to prevent accidental tracking of other aircraft.