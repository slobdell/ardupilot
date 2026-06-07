---
layout: parameter
name: SID_F_STOP_HZ
display_name: System identification Stop Frequency
description: Frequency at the end of the sweep.
default_value: 40
range: 0.01 100
units: Hz
group: SID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_systemid.cpp#L34
---

# SID_F_STOP_HZ: System identification Stop Frequency

## Description
Frequency at the end of the sweep.

## Values
- **Range:** 0.01 to 100
- **Units:** Hz
- **Default:** 40

## Description
This parameter defines the highest frequency of the "Chirp" signal used during System ID.

- **Purpose:** High frequencies are used to identify the aircraft's fast dynamics, such as motor response, propeller inertia, and frame flexibility.
- **Tuning:** **40 Hz** (default) or **50 Hz** is sufficient for most multicopters. For very large vehicles, you might stop at **20 Hz** to avoid exciting structural resonances.
- **Warning:** Do not set this higher than half of your `SCHED_LOOP_RATE` (Nyquist limit). For a 400Hz loop, stay below 100Hz.

