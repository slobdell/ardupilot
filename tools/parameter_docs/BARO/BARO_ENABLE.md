---
layout: parameter
name: BARO_ENABLE
display_name: "Barometer Enable"
description: "Master enable for the barometric pressure sensor driver."
default_value: 1
range: 0 1
units: "Option"
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L283
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Barometer Enable (BARO_ENABLE)

## Description
This parameter is the master switch for the barometer driver. It is primarily used on CAN-based peripheral nodes (`AP_Periph`) to enable or disable the onboard pressure sensor.

If your peripheral node has a physical barometer installed, setting this to **1** allows the node to start measuring pressure and reporting it to the main flight controller over the CAN bus.

## The Mathematics
This is a binary switch:
*   **0:** Disabled (Driver not initialized)
*   **1:** Enabled (Driver initialized and reporting)

## The Engineer's View
In `AP_Periph` code, this parameter maps to `g.baro_enable`. It is used during the boot sequence to decide whether to call `baro.init()`. If disabled, no memory is allocated for barometer drivers, and no DroneCAN barometer messages are transmitted.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled).
*   **Usage:** Only set to 0 if your hardware lacks a barometer or if you are using the node for a different purpose (like a dedicated GPS) and want to reduce CAN bus traffic.
*   **Reboot Required:** Yes. Driver initialization happens only at startup.

