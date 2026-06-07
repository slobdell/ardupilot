---
alias_target: ARSPD_TUBE_ORDR
default_value: 2
description: This parameter allows you to control whether the order in which the tubes
  are attached to your pitot tube matters. If you set this to 0 then the first (often
  the top) connector on the sensor needs to be the stagnation pressure (the pressure
  at the tip of the pitot tube). If set to 1 then the second (often the bottom) connector
  needs to be the stagnation pressure. If set to 2 (the default) then the airspeed
  driver will accept either order. The reason you may wish to specify the order is
  it will allow your airspeed sensor to detect if the aircraft is receiving excessive
  pressure on the static port compared to the stagnation port such as during a stall,
  which would otherwise be seen as a positive airspeed.
display_name: Control pitot tube order
group: ARSPD
investigation_status: alias
layout: parameter
name: ARSPD2_TUBE_ORDR
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp#L99
units: ''
visual_asset_id: null
---

# Control pitot tube order

**Note:** This parameter functions identically to [ARSPD_TUBE_ORDR](../ARSPD/ARSPD_TUBE_ORDR.html).
