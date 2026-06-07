---
layout: parameter
name: FS_LEAK_ENABLE
display_name: Leak Failsafe Enable
description: Selects the action to take when a leak is detected.
default_value: 0
range: 0 3
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L94
---

# Leak Failsafe Enable (FS_LEAK_ENABLE)

## Description
`FS_LEAK_ENABLE` defines the emergency response for water-based vehicles (ROVs and Boats) if their internal leak sensors are triggered.

*   **0: Warn Only.** Displays a warning on the GCS but takes no autonomous action.
*   **1: Surface.** (ArduSub). Commands the ROV to climb to the surface immediately.
*   **2: Hold.** Stops all movement and maintains current position.

## Tuning & Behavior
*   **Default:** 0 (Warning).
*   **Recommendation:** Set to **1 (Surface)** for ROVs to ensure the vehicle is recoverable if the hull is compromised.
*   **Prerequisite:** Requires at least one leak sensor ([LEAK1_TYPE](LEAK1_TYPE.html)) to be enabled.