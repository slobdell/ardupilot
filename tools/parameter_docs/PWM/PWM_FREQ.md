---
layout: parameter
name: PWM_FREQ
display_name: Motor Output PWM freq for brushed motors
description: Motor Output PWM freq for brushed motors.
default_value: 16
range: 1 20
units: kHz
group: PWM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AR_Motors/AP_MotorsUGV.cpp#L46
---

# PWM_FREQ: Motor Output PWM freq for brushed motors

## Description
Motor Output PWM freq for brushed motors.

## Values
- **Range:** 1 to 20
- **Units:** kHz
- **Increment:** 1
- **Default:** 16

## Description
This parameter sets the Pulse Width Modulation (PWM) frequency used to drive brushed motors on a Rover or Boat.

- **Usage:** Only applies when `MOT_PWM_TYPE` (or `PWM_TYPE` on Rover) is set to a "Brushed" mode (e.g., `3` for BrushedWithRelay or `4` for BrushedBiPolar).
- **Default (16kHz):** A high enough frequency to be outside the audible range of human hearing (silent operation).
- **Lower Values:** May be required for some high-current motor drivers or to reduce switching losses (heat), but the motors may "whine" audibly.
