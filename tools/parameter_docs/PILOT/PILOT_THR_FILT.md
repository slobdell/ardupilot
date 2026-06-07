---
layout: parameter
name: PILOT_THR_FILT
display_name: Pilot Throttle Filter
description: Low-pass filter frequency for manual throttle inputs.
default_value: 0
range: 0 10.0
units: Hz
group: PILOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Pilot Throttle Filter (PILOT_THR_FILT)

## Description
`PILOT_THR_FILT` smooths your manual throttle movements.

If you have "shaky" hands or a transmitter with noisy potentiometers, this filter prevents the drone's motors from reacting to every tiny, unintended vibration in the stick. 

*   **0: Disabled (Default).** 
*   **Value (Hz):** Cutoff frequency. A value of **2.0 Hz** provides good smoothing without making the throttle feel "laggy."