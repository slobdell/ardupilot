---
layout: parameter
name: SPEC_GRAV
display_name: Specific Gravity (For water depth measurement)
description: This sets the specific gravity of the fluid when flying an underwater ROV.
default_value: 1.0
range: 1.0 1.1
units: 
group: SPEC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L139
---

# SPEC_GRAV: Specific Gravity (For water depth measurement)

## Description
This sets the specific gravity of the fluid when flying an underwater ROV (ArduSub). 1.0 for fresh water, 1.025 for salt water.

## Values
- **Range:** 1.0 to 1.1
- **Default:** 1.0

## Description
This parameter is critical for **ArduSub** (underwater ROVs) to accurately measure their depth using a pressure sensor.

- **Function:** Water pressure increases as you go deeper. However, salt water is denser than fresh water, so the pressure increases faster.
- **Accuracy:** If you dive in the ocean with this set to 1.0 (Fresh Water), your reported depth will be slightly incorrect (it will think you are deeper than you actually are). 
- **Tuning:** Always set this to match the body of water you are currently operating in. For example, use **1.025** for typical sea water.

