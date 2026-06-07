---
alias_target: ARSPD_SKIP_CAL
default_value: 0
description: This parameter allows you to skip airspeed offset calibration on startup,
  instead using the offset from the last calibration. This may be desirable if the
  offset variance between flights for your sensor is low and you want to avoid having
  to cover the pitot tube on each boot.
display_name: Skip airspeed offset calibration on startup
group: ARSPD
investigation_status: alias
layout: parameter
name: ARSPD3_SKIP_CAL
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp#L106
units: ''
visual_asset_id: null
---

# Skip airspeed offset calibration on startup

**Note:** This parameter functions identically to [ARSPD_SKIP_CAL](../ARSPD/ARSPD_SKIP_CAL.html).
