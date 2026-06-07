---
layout: parameter
name: FS_ACTION
display_name: Failsafe Action (Rover)
description: Defines the behavior of the Rover when a radio or GCS failsafe is triggered.
default_value: 0
range: 0 4
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp#L114
---

# Failsafe Action (FS_ACTION)

## Description
`FS_ACTION` tells your Rover what to do if it loses its connection to the pilot (Radio or GCS).

*   **0: Nothing.** The Rover continues whatever it was doing (DANGEROUS).
*   **1: RTL.** The Rover returns to its home location.
*   **2: Hold.** The Rover stops and waits for the signal to return.
*   **3: SmartRTL.** The Rover retraces its path back to home.
*   **4: SmartRTL or RTL.** 

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Set to **1 (RTL)** or **2 (Hold)** for safety.
*   **Dependencies:** Requires a valid Home position if using RTL.