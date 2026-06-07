---
layout: parameter
name: SCR_SDEV1_PROTO
display_name: "Scripting serial protocol 1"
description: "Selects the communication protocol for the first virtual serial port accessible by Lua scripts."
default_value: -1
range: null
units: "Protocol"
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L180
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Scripting serial protocol 1 (SCR_SDEV1_PROTO)

## Description
This parameter defines the logical protocol for the first virtual serial device (`SDEV1`). When using Lua scripting to interact with serial hardware, you must first tell the system what kind of data is being handled. 

Setting this to a specific protocol (like MAVLink, GPS, or NMEA) allows the virtual port to benefit from ArduPilot's internal parsing and buffer management before the data is handed off to your Lua script.

## The Mathematics
This is a standard protocol index ($P$):
*   **-1:** None/Disabled.
*   **1:** MAVLink 1.
*   **2:** MAVLink 2.
*   **5:** GPS.
*   *(Refer to the SERIALx_PROTOCOL list for all available options).*

## The Engineer's View
In `AP_Scripting.cpp`, this parameter is part of the `_serialdevice` subgroup. 
*   **Mapping:** It maps to `ports[0].state.protocol`. 
*   **Serial Manager Integration:** When `AP_SerialManager` scans for devices, it includes these virtual `SDEV` instances. 
*   **Lua Access:** A script then uses `serial:find_serial(0)` to obtain a handle to this port. The internal driver will then automatically handle the baud rate and framing required by the chosen protocol.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled).
*   **Reboot Required:** Yes. Virtual device registration is a boot-time operation.
*   **Dependencies:** `SCR_SDEV_EN` must be set to 1.

