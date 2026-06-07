---
layout: parameter
name: BCN_ALT
display_name: "Beacon origin's altitude above sealevel in meters"
description: "Beacon origin's altitude above sealevel in meters"
default_value: 0
range: 0 10000
units: "m"
group: BCN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.cpp#L61
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.h#L129
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Beacon origin's altitude above sealevel in meters (BCN_ALT)

## Description
This parameter sets the Altitude above Mean Sea Level (AMSL) in meters for the beacon system's local origin $(0, 0, 0)$.

This establishes the vertical reference ("Z" axis anchor) for the indoor positioning system. By knowing the real-world altitude of the floor (or wherever the beacon zero-point is defined), the autopilot can report accurate AMSL altitude to the Ground Control Station and other systems.

## The Mathematics
$$ Alt_{global} = BCN\_ALT + Z_{local} $$

(Note: The sign of $Z_{local}$ depends on whether the beacon system uses NED (North-East-Down) or NEU (North-East-Up) coordinates, but the driver typically handles this normalization).

## The Engineer's View
In `AP_Beacon::get_origin()`, this value is multiplied by 100 to convert it to centimeters (`int32_t` cm) used by ArduPilot's `Location` class for altitude.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** 0 to 10000 meters
*   **Setting:** Set this to the known AMSL altitude of the beacon origin.
*   **Dependencies:** Works in tandem with `BCN_LATITUDE` and `BCN_LONGITUDE`.

