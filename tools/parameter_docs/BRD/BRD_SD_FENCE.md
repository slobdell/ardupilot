---
layout: parameter
name: BRD_SD_FENCE
display_name: SDCard Fence size
description: Amount of storage in kilobytes reserved on the microSD card for fence storage.
default_value: 0
range: 0 64
units: kB
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# SDCard Fence size (BRD_SD_FENCE)

## Description
Allocates dedicated storage space on the SD card for complex geofence definitions (fence.stg).
