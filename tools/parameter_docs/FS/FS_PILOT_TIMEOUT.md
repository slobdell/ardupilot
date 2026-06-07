---
layout: parameter
name: FS_PILOT_TIMEOUT
display_name: Pilot Input Failsafe Timeout
description: The number of seconds without stick input before a failsafe is triggered.
default_value: 3.0
range: 0.1 10.0
units: s
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L144
---

# Pilot Input Failsafe Timeout (FS_PILOT_TIMEOUT)

## Description
`FS_PILOT_TIMEOUT` sets the "Grace Period" for radio or joystick interruptions.

If the autopilot does not receive a new stick command within this many seconds, it triggers the [FS_PILOT_INPUT](FS_PILOT_INPUT.html) action.

## Tuning & Behavior
*   **Default:** 3.0 seconds.
*   **Recommendation:** Leave at **3.0**. A value too short (e.g. 0.5) might trigger the failsafe if the telemetry link has a brief, normal hiccup. A value too long (e.g. 10.0) might allow the drone to drift too far before reacting to a lost link.