---
layout: parameter
name: GPS_MB2_TYPE
display_name: Moving Base Type (GPS 2)
description: Controls the type of moving base used for GPS-based yaw calculation on the second GPS instance.
default_value: 0
range: 0 1
units: 
group: GPS
visual_asset_id: gps_heading_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/MovingBase.cpp#L10
---

# Moving Base Type (GPS_MB2_TYPE)

## Description
`GPS_MB2_TYPE` configures the second GPS unit for dual-GPS heading (GPS-Yaw).

See [GPS_MB1_TYPE](GPS_MB1_TYPE.html) for detailed theory of operation. This parameter is used when you have a second independent moving-baseline pair or a complex 3-antenna setup.