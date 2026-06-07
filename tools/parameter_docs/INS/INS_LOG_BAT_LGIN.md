---
layout: parameter
name: INS_LOG_BAT_LGIN
display_name: Batch Sampler Log Interval
description: The time interval (in milliseconds) between capturing batch logs.
default_value: 20
range: 0 10000
units: ms
group: INS
visual_asset_id: log_analysis_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_BatchSampler.cpp#L100
---

# Batch Sampler Log Interval (INS_LOG_BAT_LGIN)

## Description
`INS_LOG_BAT_LGIN` controls the "Frame Rate" of the vibration recorder.

It sets the delay between finishing one batch and starting the next.

## Tuning & Behavior
*   **Default Value:** 20 ms.
*   **0:** Disabled (or continuous if supported).
*   **Recommendation:** Keep default. Faster logging uses more SD card bandwidth.