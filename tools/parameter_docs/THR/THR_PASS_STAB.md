---
layout: parameter
name: THR_PASS_STAB
display_name: Throttle Pass-Through in Stabilize
description: Enables direct RC throttle control in semi-autonomous modes (Stabilize, FBWA, Acro).
default_value: 0
range: 0 1
units: 
group: THR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L413
---

# Throttle Pass-Through in Stabilize (THR_PASS_STAB)

## Description
`THR_PASS_STAB` is a specialized setting for ArduPlane, primarily used for combustion (gas/nitro) engines.

Normally, ArduPilot clamps the throttle between [THR_MIN](THR_MIN.html) and [THR_MAX](THR_MAX.html). For a gas engine, your "Min" throttle is usually set to a fast idle. If you wanted to kill the engine using a switch on your transmitter, the autopilot's clamping would normally prevent you from reaching the "cutoff" PWM. Enabling this parameter allows the autopilot to ignore its own limits and pass the raw stick signal directly to the motor in non-GPS modes.

*   **0: Disabled (Default).** Autopilot limits apply in all modes.
*   **1: Enabled.** direct control in Stabilize, FBWA, and Acro.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Enable this if you have a "Throttle Cut" safety switch configured on your transmitter that needs to pull the PWM below the idle threshold.