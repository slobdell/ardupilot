---
alias_target: H_SW_LIN_SVO
default_value: 0
description: This linearizes the swashplate servo's mechanical output to account for
  nonlinear output due to arm rotation.  This requires a specific setup procedure
  to work properly.  The servo arm must be centered on the mechanical throw at the
  servo trim position and the servo trim position kept as close to 1500 as possible.
  Leveling the swashplate can only be done through the pitch links.  See the ardupilot
  wiki for more details on setup.
display_name: Linearize Swashplate Servo Mechanical Throw
group: H
investigation_status: alias
layout: parameter
name: H_SW2_LIN_SVO
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Swash.cpp#L46
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Swash.h#L95
units: null
visual_asset_id: null
---

# Linearize Swashplate Servo Mechanical Throw

**Note:** This parameter functions identically to [H_SW_LIN_SVO](../H/H_SW_LIN_SVO.html).
