---
alias_target: RLL_RATE_SMAX
default_value: 0
description: 'Sets an upper limit on the slew rate produced by the combined P and
  D gains. If the amplitude of the control action produced by the rate feedback exceeds
  this value, then the D+P gain is reduced to respect the limit. This limits the amplitude
  of high frequency oscillations caused by an excessive gain. The limit should be
  set to no more than 25% of the actuators maximum slew rate to allow for load effects.
  Note: The gain will not be reduced to less than 10% of the nominal value. A value
  of zero will disable this feature.'
display_name: Slew rate limit
group: YAW
investigation_status: alias
layout: parameter
name: YAW_RATE_SMAX
range: 0 200
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_HELI_PID.cpp#L70
units: null
visual_asset_id: null
---

# Slew rate limit

**Note:** This parameter configures instance SMAX. It functions identically to [RLL_RATE_SMAX](../RLL/RLL_RATE_SMAX.html).
