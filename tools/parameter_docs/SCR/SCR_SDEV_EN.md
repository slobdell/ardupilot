---
layout: parameter
name: SCR_SDEV_EN
display_name: "Scripting serial device enable"
description: "Enable virtual serial ports for use by Lua scripts."
default_value: 0
range: 0 1
units: "Option"
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L172
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Scripting serial device enable (SCR_SDEV_EN)

## Description
This parameter enables the use of "Scripting Serial Devices." These are virtual serial ports that allow Lua scripts running on the autopilot to communicate directly with external hardware or sensors connected via a physical UART, without requiring a C++ driver.

When enabled, it allocates resources for up to three virtual serial instances (`SDEV1`, `SDEV2`, `SDEV3`) which can be bound to Lua `serial` objects. This is a powerful feature for rapid prototyping of custom hardware integrations.

## The Mathematics
This parameter acts as a memory allocation gate ($G_{mem}$):

$$ \text{IF } SCR\_SDEV\_EN == 1 \rightarrow \text{Allocate } [N \times \text{SerialPortState}] $$

Where $N$ is defined by `AP_SCRIPTING_SERIALDEVICE_NUM_PORTS` (typically 3). Each port then maps to a virtual index in the `AP_SerialManager` device list.

## The Engineer's View
In `AP_Scripting.cpp`, this maps to the `_serialdevice.enable` flag.
*   **Initialization:** During boot, `AP_Scripting::init_serialdevice_ports()` checks this parameter. If active, it registers virtual ports with the Serial Manager.
*   **Lua Binding:** In a Lua script, these ports are accessed using `serial:find_serial(instance)`, where `instance` corresponds to the `SDEV` number.
*   **Data Integrity:** Enabling this also activates internal buffers for script-to-UART communication, which are cleared during script restarts to prevent stale data from being sent.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **0:** No virtual ports are created; saves a small amount of RAM.
*   **1:** Enables the `SCR_SDEVx_PROTO` parameters for configuration.
*   **Reboot Required:** Yes. Virtual port registration happens only during the early boot phase.
*   **Dependencies:** `SCR_ENABLE` must be 1. You must also set the physical UART protocol (e.g., `SERIAL2_PROTOCOL`) to **Scripting (28)** and then configure the corresponding `SCR_SDEVx_PROTO`.

