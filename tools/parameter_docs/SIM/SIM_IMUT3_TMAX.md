---
alias_target: SIM_IMUT1_TMAX
default_value: 70
description: The maximum temperature that the calibration is valid for. This must
  be at least 10 degrees above TMIN for calibration
display_name: Temperature calibration max
group: SIM
investigation_status: alias
layout: parameter
name: SIM_IMUT3_TMAX
range: -70 80
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.cpp#L75
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.h#L68
units: degC
visual_asset_id: null
---

# Temperature calibration max

**Note:** This parameter functions identically to [SIM_IMUT1_TMAX](../SIM/SIM_IMUT1_TMAX.html).
