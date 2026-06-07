---
layout: parameter
name: SIM_VICON_TMASK
display_name: Simulation Vicon Type Mask
description: Bitmask of external position and velocity messages sent by the simulated Vicon system.
default_value: 3
range: 0 31
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L540
---

# Simulation Vicon Type Mask (SIM_VICON_TMASK)

## Description
`SIM_VICON_TMASK` controls which "Languages" the virtual motion capture system uses to talk to the autopilot.

Different external systems (Vicon, Optitrack, Marvelmind) use different MAVLink packets to report position and speed.

*   **Bit 0 (1):** VISION_POSITION_ESTIMATE
*   **Bit 1 (2):** VISION_SPEED_ESTIMATE
*   **Bit 2 (4):** VICON_POSITION_ESTIMATE
*   **Bit 3 (8):** VISION_POSITION_DELTA
*   **Bit 4 (16):** ODOMETRY

## Tuning & Behavior
*   **Default Value:** 3 (Position + Speed estimates).
