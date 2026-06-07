---
layout: parameter
name: OA_DB_QUEUE_SIZE
display_name: OADatabase Queue Size
description: The maximum number of incoming sensor points stored in the buffer before they are processed into obstacles.
default_value: 80
range: 1 200
units: 
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OADatabase.cpp#L61
---

# OADatabase Queue Size (OA_DB_QUEUE_SIZE)

## Description
`OA_DB_QUEUE_SIZE` defines the size of the "Inbox" for sensor data.

Proximity sensors (like Lidars) send huge amounts of data. This queue holds the raw points until the flight controller has enough spare CPU time to process them into the obstacle database.

*   **Higher Value:** Can handle larger bursts of data without losing points. Good for high-resolution Lidars.
*   **Lower Value:** Saves RAM on small flight controllers.