---
layout: parameter
name: FLASH_BOOTLOADER
display_name: "Trigger bootloader update"
description: "Trigger a bootloader update on next boot"
default_value: 0
range: 0 1
units: ""
group: FLASH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L198
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Trigger bootloader update (FLASH_BOOTLOADER)

## Description
**DANGER ZONE.** This parameter is a command trigger. When set to 1, the DroneCAN peripheral will attempt to upgrade its own bootloader using the version embedded in its current firmware image. This is a critical operation; power loss during this process can brick the device.

## The Mathematics
N/A. State Machine Trigger.

## The Engineer's View
Defined in `Tools/AP_Periph/Parameters.cpp`.
*   **Mechanism:** On set, the system validates the embedded bootloader image, erases the bootloader sector, and writes the new image.
*   **Safety:** Do not touch unless instructed by release notes.

## Tuning & Behavior
*   **Default Value:** 0
*   **1:** Perform update. Parameter usually resets to 0 automatically or requires a reboot.