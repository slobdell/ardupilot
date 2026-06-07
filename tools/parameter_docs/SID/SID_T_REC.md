---
layout: parameter
name: SID_T_REC
display_name: System identification Total Sweep length
description: Time taken to complete the sweep.
default_value: 70
range: 0 255
units: s
group: SID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_systemid.cpp#L44
---

# SID_T_REC: System identification Total Sweep length

## Description
Time taken to complete the sweep.

## Values
- **Range:** 0 to 255
- **Units:** s
- **Default:** 70

## Description
This parameter defines the total duration of the System ID experiment (excluding fade-in and fade-out).

- **Function:** A longer sweep time means the autopilot spends more time at each frequency, resulting in higher resolution and more accurate data for the System ID algorithm.
- **Requirement:** You must have enough battery life and airspace to fly in one direction (or hover) for this duration while the test is running.
- **Tuning:** **70 to 100 seconds** is usually sufficient for a high-quality model.
- **Note:** If the drone hits a fence or the pilot takes manual control, the test is aborted.

