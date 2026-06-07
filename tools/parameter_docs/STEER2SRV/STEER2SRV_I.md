---
layout: parameter
name: STEER2SRV_I
display_name: Steering I Gain
description: The integral gain for the Rover steering controller. Corrects for long-term steering offsets (e.g. imbalanced wheel alignment).
default_value: 0.2
range: 0 1.0
units: 
group: STEER2SRV
visual_asset_id: rover_steering_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_SteerController.cpp#L101
---

# Steering I Gain (STEER2SRV_I)

## Description
`STEER2SRV_I` handles "Drift" on Rovers.

If your Rover's wheels are slightly misaligned, or if you are driving on a slope, the Rover will naturally pull to one side. The I-term builds up steering pressure to cancel out this bias and keep the Rover driving straight.