---
layout: parameter
name: SIM_WAVE_AMP
display_name: Simulated Wave Amplitude
description: The height (in meters) of the simulated waves.
default_value: 0.5
range: 0 5
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wave Amplitude (SIM_WAVE_AMP)

## Description
`SIM_WAVE_AMP` sets the "Roughness" of the sea.

A value of 1.0 means the peaks of the waves are 1 meter high. Large waves will cause significantly more rocking and may wash over the deck of low-profile boats.

## Tuning & Behavior
*   **Default Value:** 0.5 m.