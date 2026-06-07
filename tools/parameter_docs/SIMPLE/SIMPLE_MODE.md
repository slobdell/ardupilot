---
layout: parameter
name: SIMPLE_MODE
display_name: Simple Mode Enable
description: Enables "Headless" orientation, where stick movements are relative to the pilot's takeoff position rather than the drone's current heading.
default_value: 0
range: 0 1
units: 
group: SIMPLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Simple Mode Enable (SIMPLE_MODE)

## Description
`SIMPLE_MODE` is a pilot-assistance feature that removes the need to track which way the drone is "facing" (its heading).

In **Normal** flight, if you push the stick right, the drone rolls to *its* right. If the drone is facing toward you, pushing right makes it move to *your* left. In **Simple Mode**, pushing the stick right *always* makes the drone move to the right relative to your starting position, regardless of which way the nose is pointing.

## Tuning & Behavior
*   **Default:** 0 (Disabled).
*   **Usage:** Excellent for beginners or for retrieving a drone that is so far away you can't tell which way it's pointing.
*   **Prerequisite:** Requires a functional GPS and compass lock. The "Home" position is recorded at the moment of arming and used as the reference point.