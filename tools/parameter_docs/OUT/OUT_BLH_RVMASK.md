---
layout: parameter
name: OUT_BLH_RVMASK
display_name: BLHeli Reversed Mask
description: A bitmask of output channels to reverse the motor rotation direction via DShot.
default_value: 0
range: 0 4294967295
units: 
group: OUT
visual_asset_id: dshot_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli Reversed Mask (OUT_BLH_RVMASK)

## Description
`OUT_BLH_RVMASK` allows you to change motor direction without soldering.

If Motor 1 is spinning clockwise but needs to spin counter-clockwise, you can simply check the box for Bit 0 in this mask. ArduPilot sends a DShot command to the ESC to invert its rotation.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use this during setup to fix motor directions.
*   **Note:** Only works with DShot-capable ESCs (BLHeli_S, BLHeli_32, AM32).