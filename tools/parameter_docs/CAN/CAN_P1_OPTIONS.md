---
layout: parameter
name: CAN_P1_OPTIONS
display_name: CAN Port 1 Options
description: A bitmask of specialized options for the first physical CAN port.
default_value: 0
range: 0 31
units: 
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_CANManager/AP_CANIfaceParams.cpp#L43
---

# CAN Port 1 Options (CAN_P1_OPTIONS)

## Description
`CAN_P1_OPTIONS` provides hardware-level tweaks for the CAN interface.

*   **Bit 0 (1): Log All Frames.** Records every single CAN packet to the DataFlash log. (WARNING: Generates huge logs).
*   **Bit 1 (2): Require Timestamps.** Rejects frames that don't have hardware timestamps.

## Tuning & Behavior
*   **Default Value:** 0.
