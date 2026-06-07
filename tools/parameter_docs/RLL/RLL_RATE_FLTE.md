---
layout: parameter
name: RLL_RATE_FLTE
display_name: Roll Rate Error Filter
description: The cutoff frequency (in Hz) for the error term filter in the roll rate controller.
default_value: 0
range: 0 50
units: Hz
group: RLL
visual_asset_id: filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate Error Filter (RLL_RATE_FLTE)

## Description
`RLL_RATE_FLTE` smooths out the "Error" signal (the difference between desired and actual rate). This helps prevent high-frequency noise from triggering jerky control surface movements.