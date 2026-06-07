---
layout: parameter
name: WNDVN_CAL
display_name: Wind Vane Calibration Trigger
description: Starts the automatic calibration process for an analog wind vane.
default_value: 0
range: 0 2
units: 
group: WNDVN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L96
---

# Wind Vane Calibration Trigger (WNDVN_CAL)

## Description
`WNDVN_CAL` initiates a specialized routine to find the voltage limits of your analog wind vane.

Instead of manually typing in the [V_MIN](WNDVN_DIR_V_MIN.html) and [V_MAX](WNDVN_DIR_V_MAX.html) voltages, you can use this trigger to let the autopilot learn them.

*   **1: Start Calibration.** The autopilot begins recording the highest and lowest voltages it sees.
*   **2: Finish and Save.** Saves the learned values to the `V_MIN/V_MAX` parameters and resets this trigger to 0.

## Tuning & Behavior
*   **Default:** 0.
*   **Procedure:**
    1. Set `WNDVN_CAL` to 1.
    2. Manually rotate your wind vane through several full 360-degree circles.
    3. Set `WNDVN_CAL` to 2 to lock in the results.