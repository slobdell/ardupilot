---
layout: parameter
name: PUP_ARSPD_START
display_name: Pullup target airspeed
description: Target airspeed for initial airspeed wait.
default_value: 30
range: 0 100
units: m/s
group: PUP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/pullup.cpp#L54
---

# PUP_ARSPD_START: Pullup target airspeed

## Description
Target airspeed for initial airspeed wait.

## Values
- **Range:** 0 to 100
- **Units:** m/s
- **Default:** 30

## Description
This parameter sets the **Minimum Airspeed Trigger** for the pull-up maneuver.

- **Function:** If an airspeed sensor is available, the autopilot will wait until the vehicle reaches this speed during the freefall before attempting to pull up.
- **Purpose:** Prevents stalling the control surfaces. The control surfaces need airflow to be effective; pulling up at 0 airspeed does nothing but stall the servos.

