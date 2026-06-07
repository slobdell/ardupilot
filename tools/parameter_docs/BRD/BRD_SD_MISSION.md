---
layout: parameter
name: BRD_SD_MISSION
display_name: SDCard Mission size
description: Amount of storage in kilobytes reserved on the microSD card for waypoint storage.
default_value: 0
range: 0 64
units: kB
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# SDCard Mission size (BRD_SD_MISSION)

## Description
Allocates dedicated storage space on the SD card for mission command storage (mission.stg), allowing for much larger missions than internal EEPROM.
