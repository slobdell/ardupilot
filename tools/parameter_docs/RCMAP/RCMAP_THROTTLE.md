---
layout: parameter
title: RCMAP_THROTTLE
name: Throttle channel
group: RCMAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RCMapper/AP_RCMapper.cpp#L34
---

# RCMAP_THROTTLE: Throttle channel

## Description
Throttle channel number. This is useful when you have a RC transmitter that can't change the channel order easily. Throttle is normally on channel 3, but you can move it to any channel with this parameter.

## Values
- **Range:** 1 to 16
- **Increment:** 1
- **Default:** 3

## Description
This parameter maps the physical radio channel for Throttle to the autopilot's internal Throttle control.

- **Usage:** If your radio outputs Throttle on Channel 3 (Default), leave this at 3. Adjust if using a non-standard radio configuration.
- **Reboot Required:** You MUST reboot the flight controller for changes to this parameter to take effect.

