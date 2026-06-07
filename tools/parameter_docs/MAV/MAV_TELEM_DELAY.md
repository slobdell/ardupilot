---
layout: parameter
name: MAV_TELEM_DELAY
display_name: Telemetry startup delay
description: The amount of time (in seconds) to delay radio telemetry to prevent an Xbee bricking on power up.
default_value: 0
range: 0 30
units: s
group: MAV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L58
---

# MAV_TELEM_DELAY: Telemetry startup delay

## Description
The amount of time (in seconds) to delay radio telemetry to prevent an Xbee bricking on power up.

## Values
- **Range:** 0 to 30
- **Units:** s
- **Increment:** 1
- **Default:** 0

## Description
This parameter adds a pause before the telemetry ports are initialized during boot.

- **Purpose:** Some older telemetry radios (specifically certain XBee modules) could enter a "bricked" or unresponsive state if they received data immediately upon power-up while their internal bootloader was running. This delay ensures the flight controller waits until the radio is fully booted before sending any MAVLink data.
- **Modern Hardware:** Most modern radios (SiK, RFD900, WiFi) do not require this, so it can typically be left at 0.

## Source Code
[ardupilot/Rover/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L58)

