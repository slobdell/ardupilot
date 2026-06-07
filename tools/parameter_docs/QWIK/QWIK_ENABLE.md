---
layout: parameter
name: QWIK_ENABLE
display_name: Quicktune Enable
description: Enables the in-flight automated PID tuning system (Quicktune).
default_value: 0
range: 0 1
units: 
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L25
---

# Quicktune Enable (QWIK_ENABLE)

## Description
`QWIK_ENABLE` activates an automated, in-flight PID tuning assistant.

Quicktune is a C++ implementation of the popular "QuickTune" Lua script. It works by slowly increasing your drone's P and D gains while you fly until it detects a small oscillation. It then backs off the gain to a safe margin. This allows you to get a high-performance tune in minutes without needing to use the full AutoTune mode.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Usage:** Once enabled, you must assign an RC channel to `RCx_OPTION = 129` (QuickTune) to start/stop the tuning process in flight.
*   **Reboot Required:** Yes.