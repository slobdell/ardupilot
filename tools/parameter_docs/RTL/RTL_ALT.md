---
layout: parameter
name: RTL_ALT
display_name: RTL Altitude
description: The altitude (in centimeters) the vehicle will climb to before returning to home.
default_value: 1500
range: 0 8000
units: cm
group: RTL
visual_asset_id: rtl_alt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L946
---

# RTL Altitude (RTL_ALT)

## Description
`RTL_ALT` sets the "Safe Height" for Return-to-Launch.

When RTL is triggered (e.g. by a failsafe or switch), the drone will climb to this altitude before flying home. This ensures it clears trees, buildings, and hills.

*   **0:** Stay at current altitude (Dangerous if low).
*   **1500 (Default):** 15 meters.
*   **Recommendation:** Set to at least **2000-3000 (20-30m)** to clear most suburban obstacles.

## The Mathematics
$$ \text{Target Alt} = \max(\text{Current Alt}, \text{RTL\_ALT}) $$

## Tuning & Behavior
*   **Default Value:** 1500 cm.
*   **Note:** If the drone is already *higher* than this value, it will stay at its current altitude to fly home. It will never descend to `RTL_ALT`.