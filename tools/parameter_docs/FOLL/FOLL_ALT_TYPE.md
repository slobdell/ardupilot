---
layout: parameter
name: FOLL_ALT_TYPE
display_name: "Follow Altitude Type"
description: "Determines whether the drone maintains altitude relative to Home or uses Absolute AMSL altitude when following."
default_value: 1
range: 0 1
units: "Option"
group: FOLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L134
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Follow Altitude Type (FOLL_ALT_TYPE)

## Description
This parameter defines the "Vertical Reference Frame" used when calculating the target's position. It tells the drone whether it should try to match the target's absolute height above sea level or its relative height above the launch point.

This is critical for terrain following. If the target climbs a hill, you need to know if the drone should also climb (Relative) or stay at a fixed barometric altitude (Absolute).

## The Mathematics
The parameter selects the altitude source mode:

*   **0: Absolute (AMSL).** The drone targets the raw GPS Mean Sea Level altitude reported by the lead vehicle.
    $$ Alt_{target} = Alt_{Lead\_AMSL} + Offset_Z $$
*   **1: Relative (Above Home).** The drone targets an altitude relative to its own home position.
    $$ Alt_{target} = (Alt_{Lead\_AMSL} - Alt_{Home}) + Offset_Z $$

## The Engineer's View
In `AP_Follow::handle_global_position_int_message()` (`libraries/AP_Follow/AP_Follow.cpp`):
1.  The code receives a `GLOBAL_POSITION_INT` MAVLink message.
2.  If `_alt_type == 1` (Relative), it converts the packet's `relative_alt` field into an `ABOVE_HOME` frame location.
3.  If `_alt_type == 0` (Absolute), it uses the packet's raw `alt` (AMSL) field directly.

## Tuning & Behavior
*   **Default Value:** 1 (Relative).
*   **Rover/Boat:** Usually set to **1**. If the boat is at "0m" relative to the water, the drone will fly "0m + Offset" above the water.
*   **Aircraft:** Set to **0** if you want the follower to stay at a specific barometric altitude regardless of where the leader goes (e.g., for formation flight at a safe ATC-cleared altitude).

