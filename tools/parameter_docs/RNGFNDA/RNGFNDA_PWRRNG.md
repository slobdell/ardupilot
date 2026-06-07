---
alias_target: RNGFND1_PWRRNG
default_value: 0
description: This parameter sets the estimated terrain distance in meters above which
  the sensor will be put into a power saving mode (if available). A value of zero
  means power saving is not enabled
display_name: Powersave range
group: RNGFNDA
investigation_status: alias
layout: parameter
name: RNGFNDA_PWRRNG
range: 0 32767
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L90
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RangeFinder/AP_RangeFinder_Params.h#L22
units: m
visual_asset_id: null
---

# Powersave range

**Note:** This parameter configures instance A. It functions identically to [RNGFND1_PWRRNG](../RNGFND1/RNGFND1_PWRRNG.html).
