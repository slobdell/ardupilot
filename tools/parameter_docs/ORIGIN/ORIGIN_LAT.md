---
layout: parameter
name: ORIGIN_LAT
display_name: EKF Backup Origin Latitude
description: The manual latitude used as a reference point (Origin) when the vehicle is operating without a GPS.
default_value: 0
range: -90 90
units: deg
group: ORIGIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L722
---

# EKF Backup Origin Latitude (ORIGIN_LAT)

## Description
`ORIGIN_LAT` (working with [ORIGIN_LON](ORIGIN_LON.html)) provides a "Start Map Here" coordinate for the drone's position estimator (EKF).

If you are flying indoors or using an **ArduSub** ROV without GPS, the drone doesn't know where it is on the planet. However, it still needs a global coordinate to satisfy internal math and GCS mapping. This parameter allows you to manually set that starting point.

## Tuning & Behavior
*   **Usage:** Set this to the coordinates of your dive site or indoor arena.
*   **Significance:** Even if you only care about relative movement (e.g. "Move 5 meters left"), providing a valid origin ensures that logs and maps show your vehicle in the correct general area of the world.