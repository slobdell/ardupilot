---
layout: parameter
name: GPS_SAVE_CFG
display_name: Save GPS Configuration
description: Controls whether ArduPilot writes its configuration to the GPS module's permanent memory.
default_value: 2
range: 0 2
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp#L199
---

# Save GPS Configuration (GPS_SAVE_CFG)

## Description
`GPS_SAVE_CFG` determines if the flight controller should permanently save the settings (Baud rate, update frequency, constellations) into the GPS module's own flash memory.

*   **0: Do Not Save.** Autopilot configures the GPS on every boot, but the GPS reverts to factory defaults if powered off.
*   **1: Save.** Autopilot saves the settings to the GPS flash.
*   **2: Save only when needed (Default).** Autopilot only writes to the GPS flash if the configuration has changed.

## Tuning & Behavior
*   **Default:** 2.
*   **Advantage:** Saving the configuration can make the "GPS Lock" and "Detection" phase of the boot process slightly faster, as the GPS doesn't need to be fully reconfigured from scratch every time.
*   **Note:** This is primarily supported by **u-blox** (6 series and newer) modules.