---
layout: parameter
name: AROT_FWD_I
display_name: Autorotation Forward Velocity I Gain (Alias)
description: The integral gain for forward velocity control during autonomous autorotation.
default_value: 0
range: 
units: 
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Autorotation Forward Velocity I Gain (AROT_FWD_I)

**Note:** This parameter is likely a legacy alias or reserved slot. The current autorotation controller primarily uses P and FeedForward terms for forward speed.