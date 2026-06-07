---
layout: parameter
name: SBAS_MODE
display_name: SBAS Mode
description: This sets the SBAS (satellite based augmentation system) mode if available on this GPS. If set to 2 then the SBAS mode is not changed in the GPS. Otherwise the GPS will be reconfigured to enable/disable SBAS.
default_value: 2
range: 0 2
units: 
group: SBAS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/AP_GPS.cpp#L158
---

# SBAS_MODE: SBAS Mode

## Description
This parameter selects the behavior for SBAS (Satellite Based Augmentation System) like WAAS, EGNOS, or MSAS.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled (Turn off SBAS on the GPS) |
| 1 | Enabled (Turn on SBAS on the GPS) |
| 2 | No Change (Use the GPS module's current internal setting) |

- **Default:** 2

## Description
**SBAS** uses a network of ground stations and geostationary satellites to provide corrections to your GPS receiver, potentially improving accuracy from ~2.5m down to ~1m.

- **Usage:** In North America (WAAS), Europe (EGNOS), and Japan (MSAS), enabling this (1) usually improves position stability.
- **Why Disable?** In some regions, SBAS satellites are very low on the horizon, or the ground station baseline is so long that the "corrections" actually add more noise than accuracy.
- **Default (2):** This is the safest setting, as it leaves the decision to the GPS manufacturer's factory defaults.

