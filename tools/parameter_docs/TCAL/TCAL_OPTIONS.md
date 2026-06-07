---
layout: parameter
name: TCAL_OPTIONS
display_name: "Temperature Calibration Options"
description: "Bitmask for advanced thermal calibration features, including saving values to the bootloader sector for permanence."
default_value: 0
range: null
units: "Bitmask"
group: TCAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L663
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Temperature Calibration Options (TCAL_OPTIONS)

## Description
This parameter provides advanced control over how thermal calibration data is stored and managed. It specifically enables the "Persistence" feature, which allows the autopilot to save calibrated sensor values into a special protected area of memory (the bootloader sector). 

Saving values here ensures that your high-fidelity temperature calibration remains intact even if you perform a "Reset to Defaults" on all other parameters. It is highly recommended for industrial-grade vehicles where re-performing a 20-minute thermal calibration in the field is not practical.

## The Mathematics
This is a bitmask ($B$):

*   **Bit 0 (Value 1): PersistTemps.** Saves the temperature-related calibration constants to the bootloader sector.
*   **Bit 1 (Value 2): PersistAccels.** Saves the accelerometer-related thermal constants to the bootloader sector.

## The Engineer's View
In `AP_InertialSensor.cpp`, this maps to `tcal_options`. 
*   **Safety:** The bootloader sector is used because it is rarely erased and exists outside the standard parameter storage area. 
*   **Transfer:** During the next bootloader update or specific GCS command, the autopilot will copy the volatile RAM-based calibration into this persistent storage.
*   **Recall:** On every subsequent boot, ArduPilot checks the bootloader sector first. If valid calibration is found there, it is loaded into the active sensor drivers automatically.

## Tuning & Behavior
*   **Default Value:** 0 (Persistence disabled; values stored in standard EEPROM only).
*   **Recommended:** Set to **3 (Bit 0 + Bit 1)** once you have achieved a "Perfect" thermal calibration.
*   **Industrial Use:** This is standard for factory-calibrated aircraft where the sensor drift profiles are fixed for the life of the airframe.

