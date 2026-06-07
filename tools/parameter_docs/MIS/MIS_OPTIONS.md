---
layout: parameter
name: MIS_OPTIONS
display_name: Mission Options
description: Bitmask for advanced mission behaviors.
default_value: 0
range: 0 7
units: 
group: MIS
visual_asset_id: mission_options_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Mission/AP_Mission.cpp#L45
---

# Mission Options (MIS_OPTIONS)

## Description
`MIS_OPTIONS` provides a set of toggle-able rules for how missions are handled.

*   **Bit 0 (1): Clear on Reboot.** If enabled, the drone will wipe its mission memory every time you power it off. (Useful for data security or ensuring you don't accidentally fly an old mission).
*   **Bit 2 (4): ContinueAfterLand.** (Copter Only). If a mission includes a `LAND` command, the drone will stay armed and continue to the next waypoint (usually a takeoff) after landing. Without this, the mission ends at the landing.

## The Engineer's View
Used in `AP_Mission::init()` (for clear on boot) and `AP_Mission::continue_after_land_check_for_takeoff()`.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Usually leave at **0**. Use **Bit 2 (4)** only if your mission requires multiple stop-and-go landings (e.g., package delivery).