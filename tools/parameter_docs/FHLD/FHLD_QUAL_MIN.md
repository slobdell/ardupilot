---
layout: parameter
name: FHLD_QUAL_MIN
display_name: FlowHold Flow quality minimum
description: Minimum flow sensor quality required to enable FlowHold position keeping.
default_value: 10
range: 0 255
units: 
group: FHLD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold Flow quality minimum (FHLD_QUAL_MIN)

## Description
Threshold for the optical flow sensor's quality metric. If the sensor reports a quality below this value (due to poor lighting or low texture), the vehicle will fallback to AltHold behavior.