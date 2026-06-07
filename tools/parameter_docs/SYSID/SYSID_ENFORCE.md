---
layout: parameter
name: SYSID_ENFORCE
display_name: GCS sysid enforcement
description: This controls whether packets from other than the expected GCS system ID will be accepted.
default_value: 0
range: 0 1
units: 
group: SYSID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Rover/Parameters.cpp#L411
---

# SYSID_ENFORCE: GCS sysid enforcement

## Description
This controls whether packets from other than the expected GCS system ID will be accepted.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Not Enforced (Accept packets from any GCS) |
| 1 | Enforced (Only accept packets from `SYSID_MYGCS`) |

- **Default:** 0

## Description
This parameter adds a layer of security to the MAVLink communication link.

- **Function:** When enabled (1), the vehicle ignores all uplink commands (like mode changes or waypoint uploads) unless they come from a Ground Control Station whose System ID matches the value stored in `SYSID_MYGCS`.
- **Usage:** Useful if multiple pilots are flying in the same area on the same frequency/network to prevent cross-control.
- **Warning:** If you enable this and your GCS changes its System ID (or you use a different computer), you will be locked out of controlling the vehicle until you reset this parameter (e.g., via USB).

