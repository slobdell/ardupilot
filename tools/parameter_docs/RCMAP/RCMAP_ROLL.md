---
layout: parameter
title: RCMAP_ROLL
name: Roll channel
group: RCMAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RCMapper/AP_RCMapper.cpp#L16
---

# RCMAP_ROLL: Roll channel

## Description
Roll channel number. This is useful when you have a RC transmitter that can't change the channel order easily. Roll is normally on channel 1, but you can move it to any channel with this parameter.

## Values
- **Range:** 1 to 16
- **Increment:** 1
- **Default:** 1

## Description
This parameter maps the physical radio channel for Roll (Aileron) to the autopilot's internal Roll control.

- **Usage:** If your radio outputs Aileron on Channel 3 instead of Channel 1, set this parameter to 3.
- **Why it matters:** Allows ArduPilot to work with any radio brand (Futaba, Spektrum, FrSky) regardless of their native channel order (AETR, TAER, etc.).
- **Reboot Required:** You MUST reboot the flight controller for changes to this parameter to take effect.

