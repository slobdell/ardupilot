---
layout: parameter
name: RST_SWITCH_CH
display_name: "Reset Switch Channel"
description: "RC channel to reset to last flight mode after fence breach"
default_value: 0
range: 0 16
units: ""
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L27
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Reset Switch Channel (RST_SWITCH_CH)

## Description
This parameter assigns a specific RC switch channel to the "Reset" function. This is primarily used in Rover to clear a Geofence Breach state or to return control to the pilot after a failsafe event has triggered an autonomous mode change.

## The Mathematics
N/A. Logic trigger.

## The Engineer's View
Defined in `Rover/Parameters.cpp`. Checks for a PWM change (low to high) on the specified channel.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Set to:** An unused channel (e.g., 7 or 8) mapped to a momentary switch on your transmitter.