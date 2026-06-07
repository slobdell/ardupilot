---
layout: parameter
name: RNGFND1_TYPE
display_name: Rangefinder Type (Sensor 1)
description: Selects the driver for the first rangefinder.
default_value: 0
range: 0 42
units: 
group: RNGFND
visual_asset_id: rngfnd_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L20
---

# Rangefinder Type (RNGFND1_TYPE)

## Description
`RNGFND1_TYPE` enables the primary altitude/distance sensor.

*   **0: None.** Disabled.
*   **1: Analog.** Voltage-based sensors.
*   **2: Maxbotix I2C.**
*   **4: PulsedLight I2C.** (LIDAR-Lite).
*   **10: MavLink.**
*   **15: TFmini.** (Serial).
*   **24: DroneCAN.**

## Tuning & Behavior
*   **Default:** 0
*   **Reboot Required:** Yes.
*   **Setup:** After setting the type, you must reboot, then configure `RNGFND1_MIN_CM` and `RNGFND1_MAX_CM`.

