---
layout: parameter
name: BCN_LONGITUDE
display_name: "Beacon origin's longitude"
description: "Beacon origin's longitude"
default_value: 0
range: -180 180
units: "deg"
group: BCN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.cpp#L53
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.h#L128
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Beacon origin's longitude (BCN_LONGITUDE)

## Description
This parameter sets the global Longitude (in degrees) that corresponds to the local origin $(0, 0, 0)$ of the beacon system.

Together with `BCN_LATITUDE`, it anchors the local Cartesian coordinate system (X, Y) of the indoor positioning system to the Earth's geodetic frame. This allows the EKF (Extended Kalman Filter) to output a global position estimate even when relying on local beacons.

## The Mathematics
The autopilot uses this value as the reference point for a Local-to-Global projection.

$$ Lon_{global} = BCN\_LONG + \Delta Lon(X_{local}) $$

Note that longitude scaling varies with latitude ($ \cos(Lat) $), which the internal projection functions handle automatically.

## The Engineer's View
In `AP_Beacon::get_origin()`, this value is multiplied by $1.0 \times 10^7$ to convert it to the internal integer format (`int32_t` scaled by 1e7) used by ArduPilot's `Location` class.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** -180 to +180 Degrees
*   **Setting:** Set this to the precise longitude of the Beacon System's (0,0) point.
*   **Dependencies:** Works in tandem with `BCN_LATITUDE` and `BCN_ALT`.

