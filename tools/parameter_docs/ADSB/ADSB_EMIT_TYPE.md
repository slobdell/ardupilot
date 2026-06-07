---
layout: parameter
name: ADSB_EMIT_TYPE
display_name: Emitter type
description: ADSB classification for the type of vehicle emitting the transponder signal. Default value is 14 (UAV).
default_value: 14
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# Emitter type (ADSB_EMIT_TYPE)

## Description
ADSB classification for the vehicle type.

## Tuning & Behavior
*   **Default Value:** 14 (UAV)
*   **Values:** 0:NoInfo, 1:Light, 2:Small, 3:Large, 4:HighVortexlarge, 5:Heavy, 6:HighlyManuv, 7:Rotocraft, 8:RESERVED, 9:Glider, 10:LightAir, 11:Parachute, 12:UltraLight, 13:RESERVED, 14:UAV, 15:Space, 16:RESERVED, 17:EmergencySurface, 18:ServiceSurface, 19:PointObstacle
