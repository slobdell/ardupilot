---
layout: parameter
name: F_STOP_HZ
display_name: System identification Stop Frequency
description: Frequency at the end of the frequency sweep for System ID mode.
default_value: 40
range: 0.01 100
units: Hz
group: F
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_systemid.cpp
---

# System identification Stop Frequency (F_STOP_HZ)

## Description
Defines the ending frequency of the automated "chirp" signal used in the System Identification flight mode.