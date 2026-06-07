---
layout: parameter
name: FWD_BAT_VOLT_MAX
display_name: Forward Battery Voltage Max
description: Maximum voltage of the battery used for forward thrust. Used for scaling throttle for consistent thrust.
default_value: 0
range: 0 100
units: V
group: FWD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Forward Battery Voltage Max (FWD_BAT_VOLT_MAX)

## Description
Defines the "full battery" voltage for the forward propulsion system in a QuadPlane. This allows the flight controller to automatically increase throttle as the battery voltage drops, maintaining consistent forward thrust.