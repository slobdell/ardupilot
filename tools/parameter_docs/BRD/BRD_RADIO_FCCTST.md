---
layout: parameter
name: BRD_RADIO_FCCTST
display_name: Internal Radio FCC Test Mode
description: Enables continuous transmission on a specific channel for regulatory (FCC) testing.
default_value: 0
range: 0 100
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L80
---

# Internal Radio FCC Test Mode (BRD_RADIO_FCCTST)

## Description
`BRD_RADIO_FCCTST` is used for regulatory compliance testing (FCC/CE).

When set to a non-zero value, the integrated radio will lock onto that specific frequency channel and transmit a continuous signal (or specific test pattern). This is required by labs to measure things like "Occupied Bandwidth" and "Max Power."

## Tuning & Behavior
*   **0: Disabled (Default).** Normal flight operation.
*   **1-100:** Sets the radio to transmit on the corresponding channel.
*   **Warning:** **RC input is disabled while this mode is active.** You cannot fly while this parameter is non-zero.