---
layout: parameter
name: LAND_DS_SLOPE_B
display_name: Deepstall Slope B
description: The offset coefficient for the deepstall landing distance calculation (Distance = A * Wind + B).
default_value: 1
range: 
units: m
group: LAND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L54
---

# LAND_DS_SLOPE_B: Deepstall Slope B

## Description
The offset coefficient for the deepstall landing distance calculation (Distance = A * Wind + B).

## Values
- **Default:** 1
- **Units:** m

## Description
This parameter represents the **base horizontal distance** the aircraft travels during a deepstall descent in zero wind conditions.

- **Formula:** `Travel Distance = (LAND_DS_SLOPE_A * Wind_Speed) + LAND_DS_SLOPE_B`
- **Function:** It accounts for the forward travel due to the plane's drag profile and entry speed.
- **Tuning:** Perform test deepstalls in calm conditions to determine this baseline distance.

