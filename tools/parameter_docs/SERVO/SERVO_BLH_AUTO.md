---
layout: parameter
name: SERVO_BLH_AUTO
display_name: BLHeli pass-thru auto-enable
description: Automatically enables BLHeli pass-thru and DShot for all channels assigned to multicopter motors.
default_value: 0
range: 0 1
units: 
group: SERVO
visual_asset_id: servo_blh_auto_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L61
---

# BLHeli pass-thru auto-enable (SERVO_BLH_AUTO)

## Description
`SERVO_BLH_AUTO` is a "smart" version of `SERVO_BLH_MASK`. Instead of you having to manually calculate the bitmask for your motors, ArduPilot looks at your `SERVOx_FUNCTION` settings.

If a pin is set to **Motor 1, Motor 2, etc.**, ArduPilot will automatically enable DShot and BLHeli pass-thru on those pins.

## The Engineer's View
If set to **1**, the initialization logic in `AP_BLHeli` automatically adds all outputs with functions 33 through 40 (standard motors) and 82 through 85 (extra motors) to the digital output mask.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Set to **1** for most modern drone builds. it simplifies configuration and ensures that if you move a motor to a different pin, the digital protocol follows the function mapping automatically.