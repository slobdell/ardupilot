---
layout: parameter
name: OUT_BLH_3DMASK
display_name: BLHeli 3D Mode Mask
description: A bitmask of output channels that use 3D (reversible) mode for BLHeli ESCs.
default_value: 0
range: 0 4294967295
units: 
group: OUT
visual_asset_id: dshot_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L100
---

# BLHeli 3D Mode Mask (OUT_BLH_3DMASK)

## Description
`OUT_BLH_3DMASK` enables "3D Mode" (reversible throttle) for specific motors.

In standard flight, 0 throttle is stop, 100% is full speed.
In 3D mode, 50% throttle is stop, 100% is full forward, and 0% is full reverse.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Usage:** Used for 3D aerobatic quads (flying upside down) or rovers/boats with reversible ESCs.
*   **Safety:** Ensure your props are tight! Reversing direction in flight exerts huge torque on the prop nut.