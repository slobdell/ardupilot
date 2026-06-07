---
alias_target: INS_HNTCH_MODE
default_value: (int8_t
description: 'Selects the type of rotor speed control used to determine throttle output
  to the HeliRSC servo channel when motor interlock is enabled (throttle hold off).
  RC Passthrough sends the input from the RC Motor Interlock channel as throttle output.  External
  Gov SetPoint sends the RSC SetPoint parameter value as throttle output.  Throttle
  Curve uses the 5 point throttle curve to determine throttle output based on the
  collective output.  AutoThrottle requires a rotor speed sensor, contains an advanced
  autothrottle governor and is primarily for piston and turbine engines. WARNING:
  Throttle ramp time and throttle curve MUST be tuned properly using Throttle Curve
  mode before using AutoThrottle'
display_name: Rotor Speed Control Mode
group: INS
investigation_status: alias
layout: parameter
name: INS_HNTC3_MODE
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp#L65
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_RSC.h#L49
units: null
visual_asset_id: null
---

# Rotor Speed Control Mode

**Note:** This parameter functions identically to [INS_HNTCH_MODE](../INS/INS_HNTCH_MODE.html).
