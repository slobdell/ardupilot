---
layout: parameter
name: SOAR_CRSE_ARSPD
display_name: Soaring Cruise Airspeed
description: The airspeed (in m/s) the glider uses when flying between thermals.
default_value: 0
range: -1 50
units: m/s
group: SOAR
visual_asset_id: glider_polar_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Soaring/AP_Soaring.cpp#L134
---

# Soaring Cruise Airspeed (SOAR_CRSE_ARSPD)

## Description
`SOAR_CRSE_ARSPD` determines the speed of travel when hunting for the next thermal.

*   **0 (Default):** Use `AIRSPEED_CRUISE`.
*   **-1:** **Speed-To-Fly (STF) Mode.** This is the "Genius Mode." The autopilot uses your drag polar to calculate the mathematically perfect speed to fly based on the current wind and expected strength of the *next* thermal.
*   **Positive Value:** Hold this specific speed.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **-1** for the most advanced autonomous glider performance.