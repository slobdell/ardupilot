---
layout: parameter
name: OUT1_FUNCTION
display_name: "Relay function"
description: "Function assigned to Relay 1"
default_value: 0
range: 0 100
units: ""
group: OUT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Relay/AP_Relay_Params.cpp#L36
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Relay/AP_Relay_Params.h#L70
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Relay function (OUT1_FUNCTION)

## Description
This parameter defines the function of the **Relay 1** output. Relays are simple On/Off (GPIO) switches used for things like camera triggers, parachutes, or powering lights.

## The Mathematics
N/A. Function Mapping.

## The Engineer's View
Defined in `libraries/AP_Relay/AP_Relay_Params.cpp`. Matches the `Relay::function` enum.
*   **0:** None
*   **1:** Relay (General purpose)
*   **...**

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Set to:** 1 (Relay) to control via `RELAY_PIN`.