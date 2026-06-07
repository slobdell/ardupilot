---
layout: parameter
name: MODE_CH
display_name: "Mode channel"
description: "RC Channel to use for driving mode control"
default_value: MODE_CHANNEL
range: 
units: ""
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L172
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Mode channel (MODE_CH)

## Description
The **Mode Channel** parameter selects which Radio Control (RC) input channel is used to switch between flight/drive modes (e.g., Manual, Acro, Auto, Loiter) on the vehicle. This is a fundamental setup step that maps a physical switch on your transmitter to the vehicle's mode selection logic. The value corresponds to the RC channel number (1-16).

## The Mathematics
The logic performs a direct mapping from the Pulse Width Modulation (PWM) value of the selected channel to a mode index.

$$ \text{Selected Mode} = f(\text{PWM}(\text{MODE_CH})) $$

The PWM range (typically 1000us to 2000us) is divided into 6 segments, allowing for up to 6 different modes to be selected via a single channel (often mixed with switches on the transmitter).

## The Engineer's View
This parameter is defined in `Rover/Parameters.cpp` as a `GSCALAR` (Global Scalar). It is read into the `mode_channel` variable. The `RC_Channel::read_mode_switch()` function checks the PWM input of the specified channel against standard thresholds (1230, 1360, 1490, 1620, 1750) to determine the active mode index (0-5).

## Tuning & Behavior
*   **Default Value:** 0 (Disabled) or vehicle specific default.
*   **Range:** 0 - 16
*   **0:** Disabled (Mode switching via RC is turned off; vehicle remains in initial mode or controlled via GCS).
*   **1-16:** The RC input channel number to use for mode switching.