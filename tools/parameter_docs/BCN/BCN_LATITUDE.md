---
layout: parameter
name: BCN_LATITUDE
display_name: "Beacon origin's latitude"
description: "Beacon origin's latitude"
default_value: 0
range: -90 90
units: "deg"
group: BCN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.cpp#L45
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.h#L127
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Beacon origin's latitude (BCN_LATITUDE)

## Description
This parameter sets the global Latitude (in degrees) that corresponds to the local origin $(0, 0, 0)$ of the beacon system.

Beacon systems typically operate in a local coordinate frame (X/Y in meters). By providing the real-world GPS coordinates of the beacon system's origin, the autopilot can convert these local measurements into global Latitude and Longitude. This allows you to fly autonomous missions using GPS waypoints even when navigating purely via indoor beacons.

## The Mathematics
The autopilot uses this value as the reference point for a Local-to-Global projection (typically an Equirectangular projection or WGS84 calculation depending on the library used).

$$ Lat_{global} = BCN\_LAT + \Delta Lat(Y_{local}) $$

## The Engineer's View
In `AP_Beacon::get_origin()`, this value is multiplied by $1.0 \times 10^7$ to convert it to the internal integer format (`int32_t` scaled by 1e7) used by ArduPilot's `Location` class.

It is critical that this value is non-zero if you want `AP_Beacon::get_origin()` to return true, which is often a prerequisite for the EKF to accept the beacon data as an absolute position source.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** -90 to +90 Degrees
*   **Setting:** Set this to the precise latitude of the Beacon System's (0,0) point. You can measure this by placing a GPS-equipped phone or drone at the origin point outdoors, or by using Google Maps satellite view.
*   **Dependencies:** Works in tandem with `BCN_LONGITUDE` and `BCN_ALT`.

