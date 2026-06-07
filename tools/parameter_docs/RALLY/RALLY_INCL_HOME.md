---
layout: parameter
name: RALLY_INCL_HOME
display_name: Rally Include Home
description: Controls whether the "Home" position is treated as a valid destination for RTL when Rally Points are also configured.
default_value: 1
range: 0 1
units: 
group: RALLY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Rally/AP_Rally.cpp#L49
---

# Rally Include Home (RALLY_INCL_HOME)

## Description
`RALLY_INCL_HOME` defines the drone's decision logic for Return-to-Launch when multiple "Safe Zones" exist.

**Rally Points** are pre-programmed safe landing locations. When you trigger RTL, the drone normally finds the *closest* Rally point and flies there. This parameter determines if the drone's original takeoff point (**Home**) should also be considered in that "closest" calculation.

*   **1: Enabled (Default).** The drone will fly to either Home or the nearest Rally point, whichever is physically closer to its current location.
*   **0: Disabled.** The drone will ignore Home and **only** fly to a Rally point. This is useful if the takeoff point is no longer safe (e.g., you are launching from a moving boat or a crowded area).

## Tuning & Behavior
*   **Default:** 1.
*   **Recommendation:** Leave at **1** for most users. Only disable if your landing site is strictly restricted to designated Rally zones.