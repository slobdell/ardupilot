---
alias_target: SIM_BARO_WCF_FWD
default_value: 0.0
description: This is the ratio of static pressure error to dynamic pressure generated
  by a positive wind relative velocity along the X body axis. If the baro height estimate
  rises during forwards flight, then this will be a negative number. Multirotors can
  use this feature only if using EKF3 and if the EK3_DRAG_BCOEF_X and EK3_DRAG_BCOEF_Y
  parameters have been tuned.
display_name: Pressure error coefficient in positive X direction (forward)
group: SIM
investigation_status: alias
layout: parameter
name: SIM_BAR2_WCF_FWD
range: -1.0 1.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro_Wind.cpp#L22
units: null
visual_asset_id: null
---

# Pressure error coefficient in positive X direction (forward)

**Note:** This parameter functions identically to [SIM_BARO_WCF_FWD](../SIM/SIM_BARO_WCF_FWD.html).
