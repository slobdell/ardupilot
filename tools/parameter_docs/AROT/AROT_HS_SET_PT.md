---
layout: parameter
name: AROT_HS_SET_PT
display_name: Target Head Speed
description: The target head speed in RPM during autorotation. Start by setting to desired hover speed and tune from there as necessary.
default_value: 1500
range: 1000 2800
units: RPM
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# Target Head Speed (AROT_HS_SET_PT)

## Description
Defines the desired rotor RPM to be maintained during the autorotation glide.

## Tuning & Behavior
*   **Default Value:** 1500 RPM
*   **Range:** 1000 to 2800 RPM
*   **Setting this too low may result in insufficient lift for flare; too high may cause excessive descent rates.**
