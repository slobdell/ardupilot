---
alias_target: CAM_FEEDBAK_PIN
default_value: -1
description: pin number to use for save accurate camera feedback messages. If set
  to -1 then don't use a pin flag for this, otherwise this is a pin number which if
  held high after a picture trigger order, will save camera messages when camera really
  takes a picture. A universal camera hot shoe is needed. The pin should be held high
  for at least 2 milliseconds for reliable trigger detection.  Some common values
  are given, but see the Wiki's "GPIOs" page for how to determine the pin number for
  a given autopilot. See also the CAMx_FEEDBCK_POL option.
display_name: Camera feedback pin
group: CAM
investigation_status: alias
layout: parameter
name: CAM2_FEEDBAK_PIN
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.cpp#L68
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_Camera_Params.h#L30
units: ''
visual_asset_id: null
---

# Camera feedback pin

**Note:** This parameter functions identically to [CAM_FEEDBAK_PIN](../CAM/CAM_FEEDBAK_PIN.html).
