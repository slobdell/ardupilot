---
layout: parameter
name: FLOW_MAX
display_name: FlowHold Flow Rate Max
description: Controls maximum apparent flow rate in flowhold.
default_value: 0.6
range: 0.1 2.5
units: 
group: FLOW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold Flow Rate Max (FLOW_MAX)

## Description
Limits the maximum optical flow rate considered valid during FlowHold mode.

## Tuning & Behavior
*   **Default Value:** 0.6
*   **Range:** 0.1 2.5