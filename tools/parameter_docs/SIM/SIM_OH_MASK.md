---
layout: parameter
name: SIM_OH_MASK
display_name: SIM-on-Hardware Output Mask
description: A bitmask of output channels that are passed through to the physical servo rail when running SITL on hardware.
default_value: 0
range: 0 65535
units: 
group: SIM
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1258
---

# SIM-on-Hardware Output Mask (SIM_OH_MASK)

## Description
`SIM_OH_MASK` allows "Hardware-in-the-Loop" behavior without external software.

If you flash the SITL binary onto a real Pixhawk ("Sim on Hardware"), the physics run on the CPU, but the servo outputs are normally disabled. This mask enables specific physical pins so you can drive real servos or motors while flying a virtual drone.

## Tuning & Behavior
*   **Default Value:** 0 (All outputs disabled).
*   **Bit 0 (1):** Enable Servo 1.
*   **Bit 1 (2):** Enable Servo 2.