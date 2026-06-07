---
alias_target: OUT_BLH_OTYPE
default_value: 0
description: When set to a non-zero value this overrides the output type for the output
  channels given by SERVO_BLH_MASK. This can be used to enable DShot on outputs that
  are not part of the multicopter motors group.
display_name: BLHeli output type override
group: SERVO
investigation_status: alias
layout: parameter
name: SERVO_BLH_OTYPE
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L118
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L76
units: null
visual_asset_id: null
---

# BLHeli output type override

**Legacy Note:** `SERVO_*` parameters have been renamed to `OUT_*` in newer firmware versions. This parameter functions identically to [OUT_BLH_OTYPE](../OUT/OUT_BLH_OTYPE.html).
