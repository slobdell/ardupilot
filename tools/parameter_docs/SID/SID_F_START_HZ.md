---
layout: parameter
name: SID_F_START_HZ
display_name: System identification Start Frequency
description: Frequency at the start of the sweep.
default_value: 0.5
range: 0.01 100
units: Hz
group: SID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_systemid.cpp#L28
---

# SID_F_START_HZ: System identification Start Frequency

## Description
Frequency at the start of the sweep.

## Values
- **Range:** 0.01 to 100
- **Units:** Hz
- **Default:** 0.5

## Description
This parameter defines the lowest frequency of the "Chirp" signal used during System ID.

- **Function:** The chirp starts at this frequency and slowly increases until it hits `SID_F_STOP_HZ`.
- **Purpose:** Low frequencies are used to identify the aircraft's rigid-body dynamics and long-term stability.
- **Tuning:** **0.5 Hz** is a good starting point for most vehicles. For very large, slow aircraft, you might reduce this to **0.1 Hz**.

