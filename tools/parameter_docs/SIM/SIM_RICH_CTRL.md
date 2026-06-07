---
layout: parameter
name: SIM_RICH_CTRL
display_name: RichenPower Control Pin
description: Pin RichenPower is connected to (SITL).
default_value: -1
range: -1 16
units: 
group: SIM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_RichenPower.cpp#L10
---

# SIM_RICH_CTRL: RichenPower Control Pin

## Description
Pin RichenPower is connected to.

## Values
- **Range:** -1 to 16
- **Default:** -1 (Disabled)

## Description
This parameter configures the SITL (Simulator) to emulate a **RichenPower Hybrid Generator**.

- **Function:** It specifies the Sim-Pin used to simulate the control signal sent to the generator.
- **Usage:** Set to **8** (simulated UART or PWM pin) to enable the generator simulation logic, allowing you to test the generator drivers and failsafes without hardware.