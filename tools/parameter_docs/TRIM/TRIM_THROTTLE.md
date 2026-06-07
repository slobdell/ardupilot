---
layout: parameter
title: TRIM_THROTTLE
name: Throttle cruise percentage
group: TRIM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1022
---

# TRIM_THROTTLE: Throttle cruise percentage

## Description
Target percentage of throttle to apply for flight in automatic throttle modes and throttle percentage that maintains `AIRSPEED_CRUISE`.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Default:** 45

## Description
This parameter sets the baseline throttle level that the autopilot will use to maintain the target cruise airspeed in level flight.

- **Function:** It is the "Feed-Forward" term for the throttle controller. If `TRIM_THROTTLE` is set correctly, the drone will fly at `AIRSPEED_CRUISE` without the throttle PID loop having to do much work.
- **Tuning:** Fly in FBWB or Cruise mode at your desired speed. Note the throttle percentage on your OSD or logs. Set `TRIM_THROTTLE` to this value.
- **Important:** If you don't have an airspeed sensor, this parameter *defines* your cruise speed.
