---
layout: parameter
name: OA_DB_BEAM_WIDTH
display_name: OADatabase Beam Width
description: The angular width of the incoming Lidar pulses, used to estimate the physical size of detected obstacles.
default_value: 5.0
range: 1 10
units: deg
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OADatabase.cpp#L78
---

# OADatabase Beam Width (OA_DB_BEAM_WIDTH)

## Description
`OA_DB_BEAM_WIDTH` helps the drone estimate how "Wide" a detected object is.

Most Lidars have a divergent beam. If the sensor detects something 10 meters away, ArduPilot uses this angle to calculate the minimum radius of the obstacle. This ensures the path planner doesn't try to fly through a gap that is too small for the drone's actual size.