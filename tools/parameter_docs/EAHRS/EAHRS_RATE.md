---
layout: parameter
name: EAHRS_RATE
display_name: AHRS data rate
description: Requested update rate for the external AHRS device in Hz.
default_value: 50
range: 50 400
units: Hz
group: EAHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ExternalAHRS/AP_ExternalAHRS.cpp
---

# AHRS data rate (EAHRS_RATE)

## Description
Configures the frequency at which the flight controller requests orientation and navigation data from the external AHRS module.
*   **Minimum value is 50 Hz.**