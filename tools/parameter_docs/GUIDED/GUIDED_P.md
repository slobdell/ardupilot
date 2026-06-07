---
layout: parameter
name: GUIDED_P
display_name: Guided Mode P Gain
description: The proportional gain for the Guided mode heading controller (Plane).
default_value: 1.0
range: 0 10
units: 
group: GUIDED
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Guided Mode P Gain (GUIDED_P)

## Description
Determines the responsiveness of the aircraft's heading correction when following offboard commands in Plane Guided mode.