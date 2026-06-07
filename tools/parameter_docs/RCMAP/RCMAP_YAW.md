---
layout: parameter
title: RCMAP_YAW
name: Yaw channel
group: RCMAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RCMapper/AP_RCMapper.cpp#L43
---

# RCMAP_YAW: Yaw channel

## Description
Yaw channel number. This is useful when you have a RC transmitter that can't change the channel order easily. Yaw (also known as rudder) is normally on channel 4, but you can move it to any channel with this parameter.

## Values
- **Range:** 1 to 16
- **Increment:** 1
- **Default:** 4

## Description
This parameter maps the physical radio channel for Yaw (Rudder) to the autopilot's internal Yaw control.

- **Usage:** If your radio outputs Rudder on Channel 4 (Default), leave this at 4. If you have a 4-channel radio and want to swap Rudder and Aileron, you would change this and `RCMAP_ROLL`.
- **Reboot Required:** You MUST reboot the flight controller for changes to this parameter to take effect.

