---
layout: parameter
name: ICE_RPM_CHAN
display_name: RPM instance channel to use
description: This is which of the RPM instances to use for detecting the RPM of the engine.
default_value: 0
range: 0 4
units: 
group: ICE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ICEngine/AP_ICEngine.cpp#L120
---

# ICE_RPM_CHAN: RPM instance channel to use

## Description
This is which of the RPM instances to use for detecting the RPM of the engine.

## Values
- **Range:** 0 to 4
- **Default:** 0

## Description
This parameter links the Internal Combustion Engine (ICE) controller to a specific RPM sensor.

- **0:** Use the first detected RPM sensor instance.
- **1:** Use RPM1.
- **2:** Use RPM2.
- **Setup:** You must have an RPM sensor configured (using the `RPM_` parameters) before the ICE controller can see any data.

