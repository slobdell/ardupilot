---
layout: parameter
name: ICE_IDLE_RPM
display_name: RPM Setpoint for Idle Governor
description: The target RPM the autopilot attempts to maintain while the engine is at idle.
default_value: -1
range: -1 10000
units: RPM
group: ICE
visual_asset_id: ice_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L118
---

# RPM Setpoint for Idle Governor (ICE_IDLE_RPM)

## Description
`ICE_IDLE_RPM` enables the automated "Idle Governor."

Without this parameter (`-1`), the drone just holds a fixed throttle percentage (`ICE_IDLE_PCT`) when idle. With it enabled, the autopilot monitors the real-time RPM and dynamically adjusts the throttle to maintain this exact speed. This compensates for changes in air temperature, altitude, and engine warm-up.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled).
*   **Requirement:** Requires a functional RPM sensor (`RPM_CHAN` must be set).
*   **Note:** Use [ICE_IDLE_SLEW](ICE_IDLE_SLEW.html) to control how quickly the governor reacts to RPM changes.