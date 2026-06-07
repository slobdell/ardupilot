---
layout: parameter
name: PUP_NG_LIM
display_name: Maximum normal load factor during pullup
description: This is the nominal maximum value of normal load factor used during the closed loop pitch rate control of the pullup.
default_value: 2.0
range: 1.0 4.0
units: G
group: PUP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/pullup.cpp#L30
---

# PUP_NG_LIM: Maximum normal load factor during pullup

## Description
This is the nominal maximum value of normal load factor used during the closed loop pitch rate control of the pullup.

## Values
- **Range:** 1.0 to 4.0
- **Units:** G (Gravities)
- **Default:** 2.0

## Description
This parameter sets the G-force limit for the autonomous pull-up.

- **Function:** During the recovery from a vertical dive, the autopilot calculates a pitch rate that will produce this specific Normal Acceleration (G-load).
- **Safety:** It prevents the autopilot from pulling up so hard that it snaps the wings off the glider.
- **Tuning:** Set this according to your airframe's structural limits (e.g., 2.0 G is generally safe for foamies, 4.0 G requires composite reinforcement).

