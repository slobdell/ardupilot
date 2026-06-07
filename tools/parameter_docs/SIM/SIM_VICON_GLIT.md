---
layout: parameter
name: SIM_VICON_GLIT
display_name: Simulation Vicon Position Glitch
description: The magnitude (in meters) of a sudden position step-change injected into the Vicon data.
default_value: 0
range: 0 10
units: m
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SITL.cpp#L570
---

# Simulation Vicon Position Glitch (SIM_VICON_GLIT)

## Description
`SIM_VICON_GLIT` injects a "Jump" into the external navigation data.

When using an external motion capture system (like Vicon or OptiTrack) for indoor flight, the data is usually perfect. This parameter allows you to simulate a tracking error where the system momentarily reports the drone is in a different location.

## Tuning & Behavior
*   **Default:** 0 (No glitch).
*   **Usage:** Set to **1.0** or **2.0** to simulate a large tracking jump.
*   **Goal:** Use this to verify that the EKF (Extended Kalman Filter) correctly rejects the bad data or that the Failsafe logic engages.
*   **Note:** This applies the glitch to the **Down** (Vertical) axis.