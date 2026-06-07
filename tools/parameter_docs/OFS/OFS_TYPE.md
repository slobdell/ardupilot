---
layout: parameter
title: OFS_TYPE
name: Follow offset type
group: OFS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L84
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.h#L150
---

# OFS_TYPE: Follow offset type

## Description
Follow offset type.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | North-East-Down (NED) |
| 1 | Relative to lead vehicle heading |

- **Default:** 0 (NED)

## Description
This parameter defines how the Follow Mode interprets the offset vector (X, Y, Z).

- **0 (NED):** The offsets are fixed to the compass. If X=10, the drone stays 10 meters North of the target, regardless of which way the target is facing.
- **1 (Relative):** The offsets rotate with the target. If X=10, the drone stays 10 meters *in front* of the target. If Y=10, it stays 10 meters to the *right*. This is usually the preferred mode for "Follow Me".

## Source Code
[ardupilot/libraries/AP_Follow/AP_Follow.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L84)

