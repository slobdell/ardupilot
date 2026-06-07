---
layout: parameter
name: SIM_ADSB_COUNT
display_name: Simulated ADSB Aircraft Count
description: The number of simulated aircraft to generate in the vicinity of the vehicle.
default_value: -1
range: -1 100
units: 
group: SIM
visual_asset_id: sim_adsb_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated ADSB Aircraft Count (SIM_ADSB_COUNT)

## Description
`SIM_ADSB_COUNT` populates the sky with fake airplanes.

This allows you to test the "ADSB Avoidance" logic (`AVOID_ADSB`) without needing a real ADSB receiver or real planes flying nearby.

*   **-1:** Disabled.
*   **0:** Enabled but 0 planes.
*   **1+:** Generates X random aircraft flying near your home location.

## Tuning & Behavior
*   **Default Value:** -1 (Disabled).
*   **Testing:** Set to **5** to see random traffic on your GCS map. Fly towards them to verify your drone triggers a failsafe or avoidance maneuver.