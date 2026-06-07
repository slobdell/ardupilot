---
alias_target: SIM_BARO_WCF_UP
default_value: 0.0
description: This is the ratio of static pressure error to dynamic pressure generated
  by a positive wind relative velocity along the Z body axis. If the baro height estimate
  rises above truth height during climbing flight (or forward flight with a high forwards
  lean angle), then this should be a negative number. Multirotors can use this feature
  only if using EKF3 and if the EK3_DRAG_BCOEF_X and EK3_DRAG_BCOEF_Y parameters have
  been tuned.
display_name: Pressure error coefficient in positive Z direction (up)
group: SIM
investigation_status: alias
layout: parameter
name: SIM_BAR3_WCF_UP
range: -1.0 1.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro_Wind.cpp#L54
units: null
visual_asset_id: null
---

# Pressure error coefficient in positive Z direction (up)

**Note:** This parameter functions identically to [SIM_BARO_WCF_UP](../SIM/SIM_BARO_WCF_UP.html).
