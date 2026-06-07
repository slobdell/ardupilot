---
layout: parameter
name: SCR_SDEV2_PROTO
display_name: "Scripting serial protocol 2"
description: "Selects the communication protocol for the second virtual serial port accessible by Lua scripts."
default_value: -1
range: null
units: "Protocol"
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L187
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Scripting serial protocol 2 (SCR_SDEV2_PROTO)

## Description
This parameter defines the logical protocol for the second virtual serial device (`SDEV2`). It functions exactly like `SCR_SDEV1_PROTO`, allowing for a second independent serial integration via Lua.

## The Mathematics
This is a standard protocol index ($P$):
*   **-1:** None/Disabled.
*   **GPS (5):** If you are synthesizing a second GPS source in Lua, set this to 5.
*   **MAVLink (2):** If your script needs to speak MAVLink to a companion device.

## The Engineer's View
In `AP_Scripting.cpp`, this maps to `ports[1].state.protocol`. 
*   **Port Mapping:** Internally, this virtual port is assigned the index `AP_SERIALMANAGER_SCR_PORT_1 + 1`.
*   **Lua Access:** Obtained via `serial:find_serial(1)`.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled).
*   **Reboot Required:** Yes.
*   **Dependencies:** `SCR_SDEV_EN` must be 1.

