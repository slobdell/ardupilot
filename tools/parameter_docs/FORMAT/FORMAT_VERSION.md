---
layout: parameter
name: FORMAT_VERSION
display_name: "Eeprom format version number"
description: "Internal storage format version"
default_value: 0
range: 
units: ""
group: FORMAT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L86
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Eeprom format version number (FORMAT_VERSION)

## Description
This is an internal system parameter used by the DroneCAN peripheral firmware to track the structure of its parameter storage (EEPROM/Flash). It ensures that if the firmware is updated to a version with a different storage layout, the system can detect the mismatch and perform a factory reset to prevent data corruption.

## The Mathematics
Integer version comparison.

## The Engineer's View
Defined in `Tools/AP_Periph/Parameters.cpp`.

## Tuning & Behavior
*   **Read Only:** Do not edit. Modifying this will likely cause a factory reset of all peripheral parameters on the next boot.