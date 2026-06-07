---
layout: parameter
name: SAVE_CFG
display_name: Save GPS configuration
description: Determines whether the configuration for this GPS should be written to non-volatile memory on the GPS. Currently working for UBlox 6 series and above.
default_value: 2
range: 0 2
units: 
group: SAVE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/AP_GPS.cpp#L199
---

# SAVE_CFG: Save GPS configuration

## Description
Determines whether the configuration for this GPS should be written to non-volatile memory on the GPS.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Do not save config |
| 1 | Save config |
| 2 | Save only when needed |

- **Default:** 2

## Description
This parameter controls whether the autopilot's GPS configuration commands (baud rate, update rate, protocol settings) are permanently stored in the GPS module's own memory (Flash/EEPROM).

- **Benefit:** If the config is saved on the GPS, it will boot up in the correct state even if the autopilot's serial port hasn't fully initialized.
- **Normal Operation (2):** The autopilot checks if the current GPS configuration matches what it wants. If not, it sends the new config and commands the GPS to save it. This is the most efficient and recommended setting.
- **Save Only (1):** Forces a save command after every boot.
- **Disable (0):** Useful if you have a custom GPS config that you don't want the autopilot to overwrite permanently.

