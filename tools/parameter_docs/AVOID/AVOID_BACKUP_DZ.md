---
layout: parameter
name: AVOID_BACKUP_DZ
display_name: Avoidance Backup Deadzone
description: The deadzone (in meters) around the AVOID_DIST_MAX boundary where no backing up occurs.
default_value: 0.1
range: 0 1
units: m
group: AVOID
visual_asset_id: avoid_logic_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L106
---

# Avoidance Backup Deadzone (AVOID_BACKUP_DZ)

## Description
`AVOID_BACKUP_DZ` prevents the drone from "jittering" back and forth.

If the drone is exactly at the `AVOID_DIST_MAX` limit (e.g. 2.0m from a wall), sensor noise might report 1.99m then 2.01m. Without a deadzone, the drone would twitch forward and backward. This parameter adds a buffer.

## Tuning & Behavior
*   **Default Value:** 0.1 m.
*   **Recommendation:** Leave at **0.1** or increase to **0.2** if your Lidar is noisy.