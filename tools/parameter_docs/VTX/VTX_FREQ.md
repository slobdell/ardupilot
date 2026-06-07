---
layout: parameter
name: VTX_FREQ
display_name: Video Transmitter Frequency (Manual)
description: Sets the exact operating frequency (in MHz) for the video transmitter.
default_value: 5800
range: 1000 6000
units: MHz
group: VTX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VideoTX/AP_VideoTX.cpp#L69
---

# Video Transmitter Frequency (VTX_FREQ)

## Description
`VTX_FREQ` allows you to specify a custom frequency for your video link, rather than using the standard [VTX_BAND](VTX_BAND.html) and [VTX_CHANNEL](VTX_CHANNEL.html) presets.

## Tuning & Behavior
*   **Default:** 5800 MHz.
*   **Note:** In most cases, it is better to use the Band and Channel parameters to ensure compatibility with standard video goggles.