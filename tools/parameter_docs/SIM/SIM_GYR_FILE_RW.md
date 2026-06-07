---
layout: parameter
name: SIM_GYR_FILE_RW
display_name: Simulated Gyroscope File Read/Write
description: Controls whether gyroscope data is read from or written to a file for replay.
default_value: 0
range: 0 3
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Gyroscope File Read/Write (SIM_GYR_FILE_RW)

## Description
`SIM_GYR_FILE_RW` works exactly like `SIM_ACC_FILE_RW` but for the gyroscope.

Use this to replay real-world gyro noise (propeller vibration) into the simulator. This is the gold standard for testing Harmonic Notch Filter settings without risking a crash.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Procedure:**
    1.  Set to **2** (Write).
    2.  Fly/Hover for 1 minute.
    3.  Copy the generated file to your SITL directory.
    4.  Set to **1** (Read) and run SITL.