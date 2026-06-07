---
layout: parameter
name: VTX_MAX_POWER
display_name: Video Transmitter Max Power Limit
description: Caps the maximum power (in mW) that can be requested via an auxiliary RC switch.
default_value: 800
range: 25 1000
units: mW
group: VTX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VideoTX/AP_VideoTX.cpp#L76
---

# Video Transmitter Max Power Limit (VTX_MAX_POWER)

## Description
`VTX_MAX_POWER` acts as a safety "Cap" for your video transmitter.

If you have assigned an RC channel to change your VTX power while flying, this parameter prevents you from accidentally selecting a power level higher than your hardware can safely handle. 

## Tuning & Behavior
*   **Default:** 800 mW.
*   **Recommendation:** Set this to the maximum rated output of your physical VTX. If your VTX only supports up to 400mW, set this to **400** to avoid sending unsupported commands to the hardware.