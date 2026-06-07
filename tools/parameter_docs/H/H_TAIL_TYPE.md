---
layout: parameter
name: H_TAIL_TYPE
display_name: Tail Type
description: Selects the mechanical type of the tail rotor system.
default_value: 0
range: 0 4
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_Single.cpp
---

# Tail Type (H_TAIL_TYPE)

## Description
Defines the hardware configuration used for yaw control on a single-rotor helicopter.
*   **0: Servo only (Standard mechanical tail)**
*   **1: Servo with External Gyro**
*   **2: DirectDrive VarPitch (Motor on tail, pitch servo controlled)**
*   **3: DirectDrive FixedPitch CW (Motor speed controls yaw, clockwise rotor)**
*   **4: DirectDrive FixedPitch CCW (Motor speed controls yaw, counter-clockwise rotor)**