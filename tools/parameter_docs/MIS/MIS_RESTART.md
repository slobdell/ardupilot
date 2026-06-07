---
layout: parameter
name: MIS_RESTART
display_name: Mission Restart
description: Controls whether the mission restarts from the first command or resumes from the last active command when entering Auto mode.
default_value: 0
range: 0 1
units: 
group: MIS
visual_asset_id: mission_restart_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Mission/AP_Mission.cpp#L40
---

# Mission Restart (MIS_RESTART)

## Description
`MIS_RESTART` determines the drone's "Memory" when you switch into **Auto** mode.

*   **0: Resume (Default).** If you were mid-mission, switched to manual to avoid an obstacle, and then switched back to Auto, the drone will continue from where it left off (the last active waypoint).
*   **1: Restart.** Every time you enter Auto mode, the drone will fly back to Waypoint #1 and start the mission from the beginning.

## The Engineer's View
Defined in `AP_Mission.cpp`.
When the vehicle enters `MISSION_RUNNING` state, the `start_or_resume()` function is called. This parameter acts as the logic gate between `start()` (reset indices) and `resume()` (keep current index).

## Tuning & Behavior
*   **Default Value:** 0 (Resume)
*   **Recommendation:** Keep at **0**. It is much safer to resume a mission than to have the drone unexpectedly turn around and fly back to the start of a large field.
*   **Note:** If the mission has reached the final waypoint and completed, entering Auto mode will always restart from #1 regardless of this parameter.