---
layout: parameter
name: SIM_MAG_ALY_HGT
display_name: Simulated Magnetic Anomaly Height
description: The altitude (in meters) at which a simulated magnetic anomaly is injected.
default_value: 0
range: 0 1000
units: m
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Magnetic Anomaly Height (SIM_MAG_ALY_HGT)

## Description
`SIM_MAG_ALY_HGT` creates a virtual "Magnetic Distortion Field" at a specific altitude.

This is useful for simulating flying near a large steel structure (like a bridge or tower). You can test if the EKF correctly rejects the bad compass data or if the drone starts to toilet-bowl.

## Tuning & Behavior
*   **Default Value:** 0.