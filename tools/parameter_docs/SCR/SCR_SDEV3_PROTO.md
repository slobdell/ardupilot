---
layout: parameter
name: SCR_SDEV3_PROTO
display_name: "Scripting serial protocol 3"
description: "Selects the communication protocol for the third virtual serial port accessible by Lua scripts."
default_value: -1
range: null
units: "Protocol"
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L195
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Scripting serial protocol 3 (SCR_SDEV3_PROTO)

## Description
This parameter defines the logical protocol for the third virtual serial device (`SDEV3`). It allows for a third independent serial integration via Lua, following the same logic as `SCR_SDEV1_PROTO`.

## The Mathematics
This is a standard protocol index ($P$):
*   **-1:** None/Disabled.
*   **Range:** Any valid ArduPilot `SERIALx_PROTOCOL` value.

## The Engineer's View
In `AP_Scripting.cpp`, this maps to `ports[2].state.protocol`. 
*   **Port Mapping:** Internally, this virtual port is assigned the index `AP_SERIALMANAGER_SCR_PORT_1 + 2`.
*   **Lua Access:** Obtained via `serial:find_serial(2)`.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled).
*   **Reboot Required:** Yes.
*   **Dependencies:** `SCR_SDEV_EN` must be 1.

