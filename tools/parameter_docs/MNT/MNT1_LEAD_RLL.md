---
layout: parameter
name: MNT1_LEAD_RLL
display_name: Mount Roll Lead Time
description: Latency compensation for gimbal servos on the roll axis.
default_value: 0
range: 0 0.2
units: s
group: MNT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L145
---

# Mount Roll Lead Time (MNT1_LEAD_RLL)

## Description
`MNT1_LEAD_RLL` compensates for mechanical and signal lag on your gimbal's roll axis. 

It is similar to [MNT1_LEAD_PTCH](MNT1_LEAD_PTCH.html) but for banking movements. If your video horizon "leans" during a turn and then slowly levels out, increasing this value will make the gimbal react faster to keep the camera flat.

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Start with **0.01s**. 
*   **Optimal Setting:** The horizon should stay perfectly horizontal even during aggressive "S-turns" or bank-and-yank maneuvers.