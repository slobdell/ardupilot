---
layout: parameter
name: FOLL_SYSID
display_name: Follow Target System ID
description: The MAVLink System ID of the target vehicle or device to follow.
default_value: 0
range: 0 255
units: 
group: FOLL
visual_asset_id: follow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L102
---

# Follow Target System ID (FOLL_SYSID)

## Description
`FOLL_SYSID` identifies who your drone is supposed to be chasing.

Every device on a MAVLink network (Drones, Laptops, Phones) has a unique ID number. By setting this parameter, you tell your drone to ignore other traffic and only follow the position updates coming from the specific ID entered here.

*   **Default:** 0 (Follow the first target detected).
*   **Recommendation:** Set this explicitly to your phone or lead drone's ID for safety and reliability.