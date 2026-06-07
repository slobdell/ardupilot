---
layout: parameter
name: ADSB_SQUAWK
display_name: Squawk code
description: VFR squawk (Mode 3/A) code is a pre-programmed default code when the pilot is flying VFR and not in contact with ATC. In the USA, the VFR squawk code is octal 1200 (hex 0x280, decimal 640) and in most parts of Europe the VFR squawk code is octal 7000. If an invalid octal number is set then it will be reset to 1200.
default_value: 1200
range: 0 7777
units: octal
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# Squawk code (ADSB_SQUAWK)

## Description
Pre-programmed default VFR squawk code.

## Tuning & Behavior
*   **Default Value:** 1200
*   **Range:** 0 to 7777 (Octal)
