---
layout: parameter
name: FS_GCS_TIMEOUT
display_name: GCS Failsafe Timeout
description: The maximum time (in seconds) that the Ground Control Station (GCS) telemetry link can be lost before a failsafe is triggered.
default_value: 5
range: 2 120
units: s
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# GCS Failsafe Timeout (FS_GCS_TIMEOUT)

## Description
`FS_GCS_TIMEOUT` sets the "Grace Period" for your telemetry link.

If you are using a laptop or tablet to control your drone (MAVLink control), this parameter defines how many seconds the autopilot will wait after losing the connection before it decides the link is broken and starts its failsafe action (usually RTL).

## Tuning & Behavior
*   **Default Value:** 5 seconds.
*   **Recommendation:** Leave at **5** for most operations. If you are flying in an area with known signal gaps, you can increase this slightly, but be aware that the drone will continue its last commanded action until the timer expires.