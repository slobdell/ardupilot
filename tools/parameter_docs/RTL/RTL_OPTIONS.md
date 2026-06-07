---
layout: parameter
name: RTL_OPTIONS
display_name: RTL Mode Options
description: Bitmask of options to change Return-to-Launch behavior.
default_value: 0
range: 0 4
units: 
group: RTL
visual_asset_id: rtl_options_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode.h#L1535
---

# RTL Mode Options (RTL_OPTIONS)

## Description
`RTL_OPTIONS` allows you to customize how the drone behaves while flying home.

*   **Bit 2 (4): Ignore Pilot Yaw.**
    *   **Unset (0):** The pilot can yaw (spin) the drone while it is returning home. This is useful for looking around with a camera during the flight.
    *   **Set (1):** The drone ignores yaw stick inputs. The nose will remain pointed towards the home point (or as defined by `WP_YAW_BEHAVIOR`).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Leave at **0** to allow pilot intervention/camera pointing.