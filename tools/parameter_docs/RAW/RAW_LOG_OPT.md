---
layout: parameter
title: RAW_LOG_OPT
name: Raw logging options
group: RAW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L685
---

# RAW_LOG_OPT: Raw logging options

## Description
Raw logging options bitmask.

## Values
- **Bitmask:**
  - **Bit 0:** Log primary gyro only
  - **Bit 1:** Log all gyros
  - **Bit 2:** Post-filter (log data after the low-pass and notch filters)
  - **Bit 3:** Pre and post-filter (log both raw and filtered data)

- **Default:** 0

## Description
This parameter controls the high-speed "Raw IMU" logging, which is used for analyzing vibrations and tuning the **Harmonic Notch Filter**.

- **Usage:** Set to **1** to see the raw noise on all gyros. Set to **3** (1 + 2) to see both raw noise and how well your filters are removing it.
- **Warning:** High-rate logging creates extremely large log files. **Only enable this during tuning flights**, then set it back to 0 for regular operation to avoid wearing out your SD card and potentially causing CPU spikes.

## Source Code
[ardupilot/libraries/AP_InertialSensor/AP_InertialSensor.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L685)

