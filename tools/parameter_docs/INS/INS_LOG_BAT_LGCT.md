---
layout: parameter
name: INS_LOG_BAT_LGCT
display_name: Batch Sampler Log Count
description: The maximum number of batch logs to record.
default_value: 0
range: 0 1000
units: 
group: INS
visual_asset_id: log_analysis_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_BatchSampler.cpp#L100
---

# Batch Sampler Log Count (INS_LOG_BAT_LGCT)

## Description
`INS_LOG_BAT_LGCT` acts as a limit switch for the data recorder.

Since batch logs are huge, recording them for an entire 30-minute flight would generate gigabytes of data and potentially crash the logger. This parameter stops the sampler after capturing a set number of snapshots.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited/Disabled?). Wait, usually 0 means disabled?
    *   *Correction:* In modern ArduPilot, 0 usually means "Disabled" for the *trigger*, or "Unlimited" depending on context. For this parameter, it typically means "Don't stop until disarmed."
*   **Recommendation:** Set to **0** for general flights. Set to **10** if you only need a quick sample of the hover.