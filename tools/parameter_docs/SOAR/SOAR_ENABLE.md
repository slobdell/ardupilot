---
layout: parameter
name: SOAR_ENABLE
display_name: Soaring Enable
description: Enables the autonomous soaring and thermal-hunting features for gliders.
default_value: 0
range: 0 1
units: 
group: SOAR
visual_asset_id: soaring_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L19
---

# Soaring Enable (SOAR_ENABLE)

## Description
`SOAR_ENABLE` activates "ArduSoar" – a sophisticated suite of algorithms that allow a glider to autonomously find, track, and orbit inside thermals (rising columns of air) to gain altitude without using the motor.

When enabled, the autopilot monitors the Variometer (climb rate) and longitudinal acceleration. If it detects that the plane is being lifted by a thermal, it can automatically switch to `THERMAL` mode, bank into a circle, and climb. Once the thermal weakens or the altitude limit is reached, it returns to its mission.

*   **0: Disabled (Default).**
*   **1: Enabled.**

## Tuning & Behavior
*   **Default Value:** 0.
*   **Operational Standard:** This is typically mapped to an RC switch using `RCx_OPTION = 88` (Soaring Enable). This allows the pilot to give the drone permission to "Go Hunting" for lift.
*   **Prerequisite:** Requires a well-calibrated airspeed sensor for best performance.
