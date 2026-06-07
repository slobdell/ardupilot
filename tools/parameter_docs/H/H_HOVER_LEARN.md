---
layout: parameter
name: H_HOVER_LEARN
display_name: Hover Value Learning
description: Enable/Disable automatic learning of hover collective.
default_value: 2
range: 0 2
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli.cpp
---

# Hover Value Learning (H_HOVER_LEARN)

## Description
Controls whether the flight controller automatically updates the H_COL_HOVER parameter based on actual flight data.
*   **0: Disabled**
*   **1: Learn (Volatile)**
*   **2: Learn and Save (Permanent)**