---
alias_target: BATT_ARM_MAH
default_value: 0
description: Battery capacity remaining which is required to arm the aircraft. Set
  to 0 to allow arming at any capacity. Note that execept for smart batteries rebooting
  the vehicle will always reset the remaining capacity estimate, which can lead to
  this check not providing sufficent protection, it is recommended to always use this
  in conjunction with the @PREFIX@ARM_VOLT parameter.
display_name: Required arming remaining capacity
group: BATT
investigation_status: alias
layout: parameter
name: BATT8_ARM_MAH
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L150
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L41
units: mAh
visual_asset_id: null
---

# Required arming remaining capacity

**Note:** This parameter functions identically to [BATT_ARM_MAH](../BATT/BATT_ARM_MAH.html).
