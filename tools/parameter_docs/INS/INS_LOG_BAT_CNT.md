---
layout: parameter
name: INS_LOG_BAT_CNT
display_name: Batch Sampler Sample Count
description: The number of samples to capture in each batch log.
default_value: 1024
range: 512 16384
units: 
group: INS
visual_asset_id: log_analysis_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_BatchSampler.cpp#L100
---

# Batch Sampler Sample Count (INS_LOG_BAT_CNT)

## Description
`INS_LOG_BAT_CNT` determines the resolution of your FFT graph.

A larger sample count means you can see finer frequency details (e.g., distinguishing between 100Hz and 102Hz). However, larger batches take longer to write to the SD card, potentially causing log gaps.

## Tuning & Behavior
*   **Default Value:** 1024 samples.
*   **Recommendation:** 1024 is sufficient for most tuning. Use **4096** for precision analysis.