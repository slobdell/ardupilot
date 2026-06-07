---
alias_target: MNT1_LEAD_RLL
default_value: 0.0f
description: Servo mount roll angle output leads the vehicle angle by this amount
  of time based on current roll rate. Increase until the servo is responsive but does
  not overshoot
display_name: Mount Roll stabilization lead time
group: MNT
investigation_status: alias
layout: parameter
name: MNT2_LEAD_RLL
range: 0.0 0.2
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L145
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.h#L30
units: s
visual_asset_id: null
---

# Mount Roll stabilization lead time

**Note:** This parameter functions identically to [MNT1_LEAD_RLL](../MNT/MNT1_LEAD_RLL.html).
