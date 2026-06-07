---
layout: parameter
name: EAHRS_TYPE
display_name: AHRS type
description: Specifies the hardware type of the external AHRS device.
default_value: 0
range: 
units: 
group: EAHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ExternalAHRS/AP_ExternalAHRS.cpp
---

# AHRS type (EAHRS_TYPE)

## Description
Enables the External AHRS library and selects the driver for the specific third-party inertial navigation system (INS) or AHRS hardware.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Values:** 0:None, 1:VectorNav, 2:MicroStrain5, 5:InertialLabs, 7:MicroStrain7
*   **Requires reboot after changing to initialize the external device communication.**