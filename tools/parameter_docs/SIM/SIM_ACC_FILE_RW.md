---
layout: parameter
name: SIM_ACC_FILE_RW
display_name: Simulated Accelerometer File Read/Write
description: Controls whether accelerometer data is read from or written to a file for replay.
default_value: 0
range: 0 3
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Accelerometer File Read/Write (SIM_ACC_FILE_RW)

## Description
`SIM_ACC_FILE_RW` allows you to "record" the vibration and movement of a real flight and "replay" it in the simulator.

This is an incredibly powerful tool for tuning filters. You can fly your real drone, capture the raw accelerometer noise, and then feed that exact noise into the simulator to test if your notch filters or EKF settings can handle it.

*   **0:** Disabled (Standard simulation).
*   **1:** Read data from file (Replay).
*   **2:** Write data to file (Record).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **2** during a short hover to capture a noise profile, then **1** to replay it while tuning `INS_HNTCH_FREQ`.