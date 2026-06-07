---
layout: parameter
name: QUAL_MIN
display_name: FlowHold Flow quality minimum
description: Minimum flow quality to use flow position hold.
default_value: 10
range: 0 255
units: 
group: QUAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_flowhold.cpp#L62
---

# QUAL_MIN: FlowHold Flow quality minimum

## Description
Minimum flow quality to use flow position hold.

## Values
- **Range:** 0 to 255
- **Default:** 10

## Description
This parameter sets the reliability threshold for the Optical Flow sensor in **FlowHold** mode.

- **Function:** The optical flow sensor reports a "quality" metric (0-255) with each reading, indicating how confident it is in the surface texture it sees.
- **Below Threshold:** If quality drops below `QUAL_MIN` (e.g., flying over water, low light, or featureless concrete), FlowHold stops trying to hold position and behaves like **AltHold** (drift with wind) to prevent runaway accumulation of errors.
- **Above Threshold:** FlowHold actively fights drift using the flow sensor data.

