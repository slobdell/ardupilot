---
layout: parameter
name: TMODE_LOAD_TYPE
display_name: Toy Mode Load Test Type
description: Selects the specific pattern of thrust applied during a Load Test.
default_value: 1
range: 0 2
units: 
group: TMODE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/toy_mode.cpp#L173
---

# Toy Mode Load Test Type (TMODE_LOAD_TYPE)

## Description
`TMODE_LOAD_TYPE` is used for factory testing and battery performance analysis on consumer drones using Toy Mode.

When a Load Test is active (triggered via specialized commands), this parameter determines the thrust profile:
*   **0: Constant Thrust.** The drone applies a steady, fixed amount of power.
*   **1: Log Replay 1.** Follows a pre-defined sequence of thrust variations to simulate a real flight profile.
*   **2: Log Replay 2.** An alternative test sequence.

## Tuning & Behavior
*   **Default:** 1.
*   **Warning:** This is an engineering/diagnostic feature. Activating a load test while the drone is on the ground can cause it to flip or fly away if propellers are attached.