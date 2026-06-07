---
layout: parameter
name: TRQD_TYPE
display_name: Torqeedo Connection Type
description: Enables control of a Torqeedo electric motor and selects the communication mode.
default_value: 0
range: 0 2
units: 
group: TRQD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L13
---

# Torqeedo Connection Type (TRQD_TYPE)

## Description
`TRQD_TYPE` enables the autopilot to communicate with a **Torqeedo** electric outboard motor (common on large autonomous boats). 

The autopilot communicates with the motor's internal controller over a serial link (usually via an RS485 converter). This allows ArduPilot to command thrust precisely and read back live telemetry like battery status and power consumption from the motor itself.

*   **0: Disabled.**
*   **1: Tiller.** Commands the motor as if the autopilot were the physical Torqeedo tiller.
*   **2: Motor.** Direct motor control mode.

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Integration:** You must also configure the ON/OFF pin ([TRQD_ONOFF_PIN](TRQD_ONOFF_PIN.html)) and the Serial port protocol (`SERIALx_PROTOCOL = 39`).