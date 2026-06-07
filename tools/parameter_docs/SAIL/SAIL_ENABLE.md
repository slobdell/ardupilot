---
layout: parameter
name: SAIL_ENABLE
display_name: Enable Sailboat
description: Enables the sailboat navigation and sail-trimming logic.
default_value: 0
range: 0 1
units: 
group: SAIL
visual_asset_id: sailboat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/sailboat.cpp#L31
---

# Enable Sailboat (SAIL_ENABLE)

## Description
`SAIL_ENABLE` turns on the specialized sailboat flight controller. 

When enabled, the vehicle will use wind direction data (from a wind vane) to automatically trim sails and perform "tacking" maneuvers (zigzagging) when navigating directly into the wind (the "No Go Zone"). This is only relevant for wind-powered aquatic vehicles.

*   **0: Disable.** The vehicle behaves like a standard motor-powered Rover/Boat.
*   **1: Enable.** Enables sail servos and sailboat navigation logic.

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Dependencies:** Requires a wind vane ([WNDVN_TYPE](WNDVN_TYPE.html)) to be configured and functional.