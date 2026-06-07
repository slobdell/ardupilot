---
layout: parameter
name: BRD_IO_DSHOT
display_name: Load DShot FW on IO
description: This loads the DShot firmware on the IO co-processor.
default_value: 0
range: 0 1
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Load DShot FW on IO (BRD_IO_DSHOT)

## Description
Enables DShot digital ESC protocol support on the primary I/O outputs (channels 1-8) by loading specialized firmware onto the IOMCU.