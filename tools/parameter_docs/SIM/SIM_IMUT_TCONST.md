---
layout: parameter
name: SIM_IMUT_TCONST
display_name: Simulated IMU Thermal Time Constant
description: The time constant (in seconds) for the exponential temperature rise of the simulated IMU.
default_value: 300
range: 1 3600
units: s
group: SIM
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1101
---

# Simulated IMU Thermal Time Constant (SIM_IMUT_TCONST)

## Description
`SIM_IMUT_TCONST` determines how fast the flight controller heats up.

It defines the "Slope" of the temperature curve. A value of 300 seconds (5 minutes) means the drone will reach its steady-state temperature fairly slowly, mimicking a real flight controller on a workbench.

## The Mathematics
The temperature $T(t)$ at time $t$ is modeled as an exponential approach:

$$ T(t) = T_{start} + (T_{end} - T_{start}) \times (1 - e^{-t / \tau}) $$

Where $\tau$ is the `SIM_IMUT_TCONST`.