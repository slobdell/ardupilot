---
layout: parameter
name: ICE_IDLE_DB
display_name: Deadband for Idle Governor
description: This configures the deadband that is tolerated before adjusting the idle setpoint.
default_value: 50
range: 0 1000
units: RPM
group: ICE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L147
---

# ICE_IDLE_DB: Deadband for Idle Governor

## Description
This configures the deadband that is tolerated before adjusting the idle setpoint.

## Values
- **Range:** 0 to 1000
- **Units:** RPM
- **Default:** 50

## Description
This parameter stabilizes the automatic idle control for internal combustion engines.

- **Function:** If the engine RPM is within `+/- ICE_IDLE_DB` of the target idle speed, the governor will not make any adjustments to the throttle servo.
- **Benefit:** Prevents the throttle servo from "hunting" or jittering constantly in response to minor, natural RPM fluctuations of a gas engine.

