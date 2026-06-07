---
layout: parameter
name: LAND_DS_SLOPE_A
display_name: Deepstall Slope A
description: The wind coefficient for the deepstall landing distance calculation (Distance = A * Wind + B).
default_value: 1
range: 
units: 
group: LAND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L48
---

# LAND_DS_SLOPE_A: Deepstall Slope A

## Description
The wind coefficient for the deepstall landing distance calculation (Distance = A * Wind + B).

## Values
- **Default:** 1

## Description
This parameter is part of the **DeepStall** landing system. It helps predict how far the plane will travel horizontally during the deepstall descent based on the wind speed.

- **Formula:** `Travel Distance = (LAND_DS_SLOPE_A * Wind_Speed) + LAND_DS_SLOPE_B`
- **Function:** The autopilot uses this estimate to decide exactly when to trigger the stall so that the plane lands on the target point.
- **Tuning:** Requires empirical testing. Measure the landing distance vs. wind speed over several flights to determine the slope.

