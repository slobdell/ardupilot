---
alias_target: MNT1_LEAD_PTCH
default_value: 0.0f
description: Servo mount pitch angle output leads the vehicle angle by this amount
  of time based on current pitch rate. Increase until the servo is responsive but
  does not overshoot
display_name: Mount Pitch stabilization lead time
group: MNT
investigation_status: alias
layout: parameter
name: MNT2_LEAD_PTCH
range: 0.0 0.2
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L154
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.h#L31
units: s
visual_asset_id: null
---

# Mount Pitch stabilization lead time

**Note:** This parameter functions identically to [MNT1_LEAD_PTCH](../MNT/MNT1_LEAD_PTCH.html).
