---
layout: parameter
name: RALLY_TOTAL
display_name: Rally Total
description: Number of rally points currently loaded.
default_value: 0
range: 0 50
units: 
group: RALLY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Rally/AP_Rally.cpp#L34
---

# RALLY_TOTAL: Rally Total

## Description
Number of rally points currently loaded.

## Values
- **Range:** 0 to 50
- **Default:** 0

## Description
This parameter indicates how many Rally Points (safe landing/loiter locations) are currently stored in the autopilot's persistent memory.

- **Usage:** This is typically updated automatically by the Ground Control Station (GCS) when you upload a Rally Point list. You should not normally edit this manually.
- **Function:** The autopilot uses this count to know how many points to check when looking for the nearest safe location during an RTL (Return to Launch).

