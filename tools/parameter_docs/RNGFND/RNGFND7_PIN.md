---
alias_target: RNGFND1_PIN
default_value: -1
description: Analog or PWM input pin that rangefinder is connected to. Analog RSSI
  or Airspeed ports can be used for Analog inputs (some autopilots provide others
  also), Non-IOMCU Servo/MotorOutputs can be used for PWM input when configured as
  "GPIOs". Values for some autopilots are given as examples. Search wiki for "Analog
  pins" for analog pin or "GPIOs", if PWM input type, to determine pin number.
display_name: Rangefinder pin
group: RNGFND
investigation_status: alias
layout: parameter
name: RNGFND7_PIN
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L27
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.h#L26
units: ''
visual_asset_id: null
---

# Rangefinder pin

**Note:** This parameter functions identically to [RNGFND1_PIN](../RNGFND/RNGFND1_PIN.html).
