---
layout: parameter
name: MIS_DONE_BEHAVE
display_name: Mission done behavior
description: Determines what the Rover or Boat does after the final waypoint in a mission is reached.
default_value: 0
range: 0 3
units: 
group: MIS
visual_asset_id: mission_done_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L349
---

# Mission done behavior (MIS_DONE_BEHAVE)

## Description
`MIS_DONE_BEHAVE` is a **Rover/Boat-specific** parameter. It tells the vehicle what to do when the mission "finish line" is crossed.

*   **0: Hold (Default).** The vehicle stops and enters **Hold** mode.
*   **1: Loiter.** (Recommended for Boats). The vehicle stays at the final location, fighting wind or current.
*   **2: Acro.** Switches to Acro mode.
*   **3: Manual.** Switches to Manual mode.

## The Engineer's View
Controlled in the Rover vehicle logic.
For boats, **Loiter (1)** is almost always better than **Hold (0)**, because a boat in "Hold" mode will drift away with the tide, whereas in "Loiter" it will use its motors to stay on the final waypoint.

## Tuning & Behavior
*   **Default Value:** 0 (Hold)
*   **Recommendation:**
    *   **Cars/Mowers:** Use **0 (Hold)**.
    *   **Boats:** Use **1 (Loiter)**.