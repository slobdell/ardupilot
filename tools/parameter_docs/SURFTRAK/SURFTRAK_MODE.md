---
layout: parameter
name: SURFTRAK_MODE
display_name: Surface Tracking Mode
description: Set which surface to track in surface tracking.
default_value: 1
range: 0 2
units: 
group: SURFTRAK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L1040
---

# SURFTRAK_MODE: Surface Tracking Mode

## Description
Set which surface to track in surface tracking.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Do not track |
| 1 | Ground (Track distance to ground) |
| 2 | Ceiling (Track distance to ceiling) |

- **Default:** 1 (Ground)

## Description
This parameter configures the **Surface Tracking** library, which allows the vehicle to maintain a set distance from a surface using a rangefinder (Lidar/Sonar).

- **Ground (1):** Standard Terrain Following. The vehicle adjusts its altitude to maintain a constant height AGL (Above Ground Level).
- **Ceiling (2):** Used for indoor inspection or tunnel flight. The vehicle uses an upward-facing rangefinder to maintain a constant distance from the roof.
- **Do not track (0):** Disables surface tracking features.

