---
layout: parameter
name: CAN_NODE
display_name: "DroneCAN node ID used by this node on all networks"
description: "DroneCAN Node ID"
default_value: 0
range: 0 127
units: ""
group: CAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L94
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# DroneCAN node ID used by this node on all networks (CAN_NODE)

## Description
This parameter sets the Node ID for the DroneCAN peripheral. The Node ID is the unique address of the device on the CAN bus.

## The Mathematics
Address Arbitration.

## The Engineer's View
Defined in `Tools/AP_Periph/Parameters.cpp`.
*   **0:** Dynamic Node Allocation (DNA). The device listens for the flight controller (Node Allocator) to assign it a free ID.
*   **1-125:** Static ID. The device claims this ID immediately.

## Tuning & Behavior
*   **Default Value:** 0 (Dynamic)
*   **Recommendation:** Use 0 for most setups. Use static IDs if you need fixed addressing for specific scripting or redundancy requirements.