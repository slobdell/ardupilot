---
alias_target: EK3_GPS_CHECK
default_value: ARMING_CHECK_ALL
description: Checks prior to arming motor. This is a bitmask of checks that will be
  performed before allowing arming. For most users it is recommended to leave this
  at the default of 1 (all checks enabled). You can select whatever checks you prefer
  by adding together the values of each check type to set this parameter. For example,
  to only allow arming when you have GPS lock and no RC failsafe you would set ARMING_CHECK
  to 72.
display_name: Arm Checks to Perform (bitmask)
group: EK2
investigation_status: alias
layout: parameter
name: EK2_GPS_CHECK
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Arming/AP_Arming.cpp#L164
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Arming/AP_Arming.h#L169
units: null
visual_asset_id: null
---

# Arm Checks to Perform (bitmask)

**Note:** This parameter functions identically to [EK3_GPS_CHECK](../EK3/EK3_GPS_CHECK.html) for EKF2.
