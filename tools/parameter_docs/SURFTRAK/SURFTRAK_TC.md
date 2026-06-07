---
layout: parameter
name: SURFTRAK_TC
display_name: Surface Tracking Filter Time Constant
description: Time to achieve 63.2% of the surface altitude measurement change. If 0 filtering is disabled.
default_value: 1.0
range: 0 5
units: s
group: SURFTRAK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L1209
---

# SURFTRAK_TC: Surface Tracking Filter Time Constant

## Description
Time to achieve 63.2% of the surface altitude measurement change. If 0 filtering is disabled.

## Values
- **Range:** 0 to 5
- **Units:** s
- **Default:** 1.0

## Description
This parameter smooths the data coming from the rangefinder before it is used for Surface Tracking flight modes.

- **Function:** Rangefinders (especially Lidar over grass or Sonar over uneven ground) can be noisy. This Low-Pass Filter (LPF) smooths out spikes to prevent the drone from twitching vertically as it flies over small obstacles like bushes or rocks.
- **Trade-off:**
    - **Higher Value (More Filtering):** Smoother flight, but the drone reacts slower to terrain changes. Dangerous if flying fast towards a steep hill.
    - **Lower Value (Less Filtering):** Faster reaction to terrain, but "jumpier" flight characteristics.

