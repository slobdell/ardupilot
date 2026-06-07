---
layout: parameter
name: TECS_LAND_SRC
display_name: TECS Landing Height Source
description: Selects the source for landing height (0=Baro, 1=Rangefinder, 2=Terrain Database).
default_value: 0
range: 0 2
units: 
group: TECS
visual_asset_id: tecs_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L100
---

# TECS Landing Height Source (TECS_LAND_SRC)

## Description
`TECS_LAND_SRC` tells the plane what "Ground" is.

*   **0 (Baro/GPS mix):** Standard. Lands at the altitude of the Home waypoint (Relative 0). Good for flat fields.
*   **1 (Rangefinder):** Uses Lidar/Sonar. Required for precision auto-landing. The plane will follow the actual contour of the ground.
*   **2 (Terrain DB):** Uses map data stored on the SD card. Useful for landing in hilly areas if you don't have a Lidar.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **1 (Rangefinder)** if you have a Lidar installed (`RNGFND_LANDING` enabled).