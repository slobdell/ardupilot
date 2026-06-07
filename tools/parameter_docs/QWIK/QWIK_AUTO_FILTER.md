---
layout: parameter
name: QWIK_AUTO_FILTER
display_name: Quicktune Auto Filter Enable
description: Automatically calculates and sets the PID filter frequencies (FLTT, FLTD) based on the current gyro filter (INS_GYRO_FILTER).
default_value: 1
range: 0 1
units: 
group: QWIK
visual_asset_id: quicktune_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L85
---

# Quicktune Auto Filter Enable (QWIK_AUTO_FILTER)

## Description
`QWIK_AUTO_FILTER` automates one of the most confusing parts of tuning: the PID filters.

For a sharp, high-performance tune, the PID filters (`FLTT`, `FLTD`, `FLTE`) should be related to the `INS_GYRO_FILTER`. When this parameter is enabled, Quicktune will automatically update your filter settings at the start of the tuning process to ensure they are optimal for your current hardware configuration.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled).
*   **Recommendation:** Keep enabled. It ensures that your filter settings evolve alongside your PID gains for a balanced tune.