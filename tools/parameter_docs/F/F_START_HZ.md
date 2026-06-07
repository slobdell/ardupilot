---
layout: parameter
name: F_START_HZ
display_name: System identification Start Frequency
description: Frequency at the start of the frequency sweep for System ID mode.
default_value: 0.5
range: 0.01 100
units: Hz
group: F
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_systemid.cpp
---

# System identification Start Frequency (F_START_HZ)

## Description
Defines the starting frequency of the automated "chirp" signal used in the System Identification flight mode to analyze aircraft dynamics.