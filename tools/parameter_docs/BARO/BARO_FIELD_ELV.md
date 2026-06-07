---
layout: parameter
name: BARO_FIELD_ELV
display_name: "Field elevation"
description: "User provided field elevation in meters"
default_value: 0
range: 
units: "m"
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L236
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.h#L306
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Field elevation (BARO_FIELD_ELV)

## Description
This parameter allows the user to manually enter the known elevation of the takeoff location (field elevation) in meters above mean sea level (AMSL). This provides a known reference altitude for the EKF and barometer before a GPS fix is obtained, ensuring more accurate absolute altitude reporting from startup.

## The Mathematics
$$ \text{Altitude}_{\text{AMSL}} \approx \text{Altitude}_{\text{Baro}} + \text{BARO_FIELD_ELV} $$

If `BARO_FIELD_ELV` is 0, the system attempts to initialize the origin altitude from GPS or other sources once available.

## The Engineer's View
Defined in `libraries/AP_Baro/AP_Baro.cpp`. The parameter `_field_elevation` is used to set `_field_elevation_active`. It is non-persistent across reboots in typical usage (resets to 0) to prevent taking off from a different location with an incorrect fixed elevation, though the parameter definition itself allows storage. The code logic often resets it or prioritizes GPS data once valid.

## Tuning & Behavior
*   **Default Value:** 0 m
*   **Set to:** Known altitude of the launch site (e.g., 100m).
*   **Note:** This is primarily for advanced users or operations in GPS-denied environments where absolute altitude reference is required from power-on.