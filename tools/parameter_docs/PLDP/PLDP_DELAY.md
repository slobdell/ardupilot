---
layout: parameter
title: PLDP_DELAY
name: Payload Place climb delay
group: PLDP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L1126
---

# PLDP_DELAY: Payload Place climb delay

## Description
Delay after release, in seconds, before aircraft starts to climb back to starting altitude.

## Values
- **Range:** 0 to 120
- **Units:** s
- **Default:** 0.0

## Description
This parameter is used during the "Payload Place" mission command.

- **Function:** After the drone detects the payload has touched down (via thrust loss or rangefinder check) and the gripper has released, the drone will wait for this many seconds on the ground (or hovering low) before ascending to return to the mission altitude.
- **Usage:** Useful to ensure the load is fully detached and the hook is clear before lifting off.

