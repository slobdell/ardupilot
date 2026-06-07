---
layout: parameter
title: TRUE_FILT
name: True speed and direction low pass filter frequency
group: TRUE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_WindVane/AP_WindVane.cpp#L159
---

# TRUE_FILT: True speed and direction low pass filter frequency

## Description
True speed and direction low pass filter frequency. A value of -1 disables the filter.

## Values
- **Range:** -1 to 10
- **Units:** Hz
- **Default:** 0.05

## Description
This parameter smooths the calculated "True Wind" vector on autonomous sailboats.

- **Function:** The autopilot calculates True Wind by subtracting the boat's own velocity (from GPS) from the Apparent Wind (from the Wind Vane). Since both GPS and Vane data can be noisy, this Low-Pass Filter smooths the result.
- **Tuning:**
    - **0.05 Hz (Default):** Very slow filter (20 second period). Good for average wind conditions.
    - **Higher:** Faster response to gusts, but noisier steering.
    - **-1:** Disabled.
