---
layout: parameter
name: MIS_TOTAL
display_name: "Total Mission Commands"
description: "The number of mission items currently stored in the flight controller's EEPROM/FRAM."
default_value: 0
range: 0 32766
units: "Commands"
group: MIS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Mission/AP_Mission.cpp#L30
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Total Mission Commands (MIS_TOTAL)

## Description
This parameter serves as a counter for the total number of waypoints and mission commands currently saved in the autopilot's onboard memory. It tells the flight controller exactly how many steps are in the current flight plan.

**Important:** This is a read-only parameter managed by the system. Users should never manually edit this value. The Ground Control Station (GCS) updates it automatically whenever you upload or clear a mission.

## The Mathematics
The value $N$ represents the count of valid mission items:
$$ N = \text{MIS\_TOTAL} $$
The valid range of command indices is $[0, N-1]$, where index 0 is typically the "Home" location.

The maximum possible value depends on the available EEPROM or FRAM storage on your specific flight controller board.

## The Engineer's View
In `AP_Mission.cpp`, this parameter maps to `_cmd_total`. 
*   **Storage Logic:** When `write_cmd_to_storage()` is called (e.g., during a mission upload), this counter is incremented.
*   **Sanity Check:** During `init()`, the code checks if `_cmd_total` exceeds the calculated maximum capacity of the storage device (`_commands_max`). If it does (indicating corruption), the mission is wiped, and `_cmd_total` is reset to 0.
*   **Truncation:** The `truncate()` function uses this parameter to logically "delete" items from the end of the mission list by simply reducing the count.

## Tuning & Behavior
*   **Default Value:** 0 (Empty Mission).
*   **Update:** Automatically updated by GCS operations.
*   **Troubleshooting:** If your vehicle refuses to enter AUTO mode, check `MIS_TOTAL`. If it is 0 or 1 (just Home), the vehicle knows it has no mission to fly.
