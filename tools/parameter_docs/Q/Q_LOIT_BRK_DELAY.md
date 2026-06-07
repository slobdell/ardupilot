---alias_target: LOIT_BRK_DELAY
default_value: LOITER_BRAKE_START_DELAY_DEFAULT
description: Loiter brake start delay (in seconds)
display_name: Loiter brake start delay (in seconds)
group: Q
investigation_status: alias
layout: parameter
name: Q_LOIT_BRK_DELAY
range: 0 2
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L73
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.h#L83
units: s
visual_asset_id: null
---
# Loiter brake start delay (in seconds)

**QuadPlane Note:** This parameter configures the VTOL motors/behavior. It functions identically to the standard Copter parameter [LOIT_BRK_DELAY](../LOIT/LOIT_BRK_DELAY.html).

Please refer to the [LOIT_BRK_DELAY](../LOIT/LOIT_BRK_DELAY.html) documentation for detailed tuning instructions.
