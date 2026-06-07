---
layout: parameter
name: DSPOILER_OPTS
display_name: Crow flap options
description: Options for crow flap behavior.
default_value: 3
range: 
units: 
group: DSPOILER
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Crow flap options (DSPOILER_OPTS)

## Description
Bitmask for advanced configuration of differential spoilers and crow flaps.

## Tuning & Behavior
*   **Default Value:** 3
*   **Bitmask:**
    *   Bit 0: Enable outer spoilers
    *   Bit 1: Enable inner spoilers
    *   Bit 2: Progressive crow (scales with airspeed)
    *   Bit 3: Use pitch trim for crow