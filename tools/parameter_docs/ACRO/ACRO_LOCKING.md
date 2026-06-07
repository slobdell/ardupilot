---
layout: parameter
name: ACRO_LOCKING
display_name: Acro Mode Attitude Locking
description: Enables the autopilot to maintain the drone's attitude when sticks are released in ACRO mode.
default_value: 0
range: 0 1
units: 
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Acro Mode Attitude Locking (ACRO_LOCKING)

## Description
`ACRO_LOCKING` (also known as "Stick Locking") helps the drone stay exactly where you point it.