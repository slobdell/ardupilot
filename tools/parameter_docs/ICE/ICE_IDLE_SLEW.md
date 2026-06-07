---
layout: parameter
name: ICE_IDLE_SLEW
display_name: Slew Rate for idle control
description: This configures the slewrate used to adjust the idle setpoint in percentage points per second.
default_value: 1
range: 1 100
units: %/s
group: ICE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L152
---

# ICE_IDLE_SLEW: Slew Rate for idle control

## Description
This configures the slewrate used to adjust the idle setpoint in percentage points per second.

## Values
- **Range:** 1 to 100
- **Units:** %/s
- **Default:** 1

## Description
This parameter controls how quickly the engine governor can change the idle throttle position.

- **Function:** It limits the rate of change of the throttle servo output when the governor is active.
- **Safety:** Prevents the servo from slamming open or closed too quickly, which could cause the engine to stall or surge unexpectedly.
- **Tuning:** Increase this value if the governor is too slow to catch a dropping RPM (e.g., when disengaging a load).

