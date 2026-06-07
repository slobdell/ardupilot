---
layout: parameter
name: SIM_ADSB_TX
display_name: Simulated ADSB Transmission
description: Enables simulation of an ADSB Transceiver (Out) capability.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_adsb_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated ADSB Transmission (SIM_ADSB_TX)

## Description
`SIM_ADSB_TX` simulates the presence of an ADSB "Out" unit on your drone.

When enabled, the simulator will act as if it is broadcasting your position to the world. This is primarily for checking that the `ADSB_RF_SELECT` and other transponder settings are configured correctly in the GCS.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **1:** Enabled.