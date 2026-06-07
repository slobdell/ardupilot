---
layout: parameter
name: ORIGIN_LON
display_name: EKF Backup Origin Longitude
description: The manual longitude used as a reference point (Origin) when the vehicle is operating without a GPS.
default_value: 0
range: -180 180
units: deg
group: ORIGIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp
---

# EKF Backup Origin Longitude (ORIGIN_LON)

## Description
Provides the manual longitude coordinate for an EKF origin without GPS.