---
layout: parameter
name: TUNE_SELECTOR
display_name: In-Flight Tuning Selector Channel
description: Selects the RC channel used to cycle through or lock in tuning parameters.
default_value: 0
range: 0 16
units: 
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Tuning/AP_Tuning.cpp#L41
---

# In-Flight Tuning Selector Channel (TUNE_SELECTOR)

## Description
`TUNE_SELECTOR` allows you to manage multiple tuning parameters from a single knob on your transmitter.

While [TUNE_CHAN](TUNE_CHAN.html) is the knob that actually changes the value, `TUNE_SELECTOR` is a separate switch (usually a 2-position spring-loaded switch) that tells the autopilot to:
1.  **Toggle between parameters:** (If multiple parameters are in the set).
2.  **Lock in the value:** Saves the current knob position to the parameter.
3.  **Re-center:** Resets the knob's effect.

## Tuning & Behavior
*   **Default:** 0 (Disabled).
*   **Recommendation:** Assign to a momentary switch on your transmitter. This allows you to "Dial in" a value with the knob, then "Click" the switch to save it before moving to the next parameter.