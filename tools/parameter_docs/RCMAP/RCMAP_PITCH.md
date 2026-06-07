---
layout: parameter
title: RCMAP_PITCH
name: Pitch channel
group: RCMAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RCMapper/AP_RCMapper.cpp#L25
---

# RCMAP_PITCH: Pitch channel

## Description
Pitch channel number. This is useful when you have a RC transmitter that can't change the channel order easily. Pitch is normally on channel 2, but you can move it to any channel with this parameter.

## Values
- **Range:** 1 to 16
- **Increment:** 1
- **Default:** 2

## Description
This parameter maps the physical radio channel for Pitch (Elevator) to the autopilot's internal Pitch control.

- **Usage:** If your radio outputs Elevator on Channel 2 (Default), leave this at 2. If it uses a different order (e.g., AETR vs TAER), adjust this to match.
- **Reboot Required:** You MUST reboot the flight controller for changes to this parameter to take effect.

