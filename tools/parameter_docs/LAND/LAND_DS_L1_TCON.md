---
layout: parameter
name: LAND_DS_L1_TCON
display_name: Deepstall L1 Time Constant
description: Controls the responsiveness of navigation (L1) during a Deep Stall landing approach.
default_value: 0.4
range: 0.1 1.0
units: s
group: LAND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L133
---

# Deepstall L1 Time Constant (LAND_DS_L1_TCON)

## Description
`LAND_DS_L1_TCON` defines how aggressively a fixed-wing aircraft should correct its course during a **Deep Stall** landing.

In a deep stall landing, the plane intentionally stalls its wings to drop vertically onto a target. Because the wings have very little lift and airflow is turbulent, standard steering is less effective. This parameter tunes the "L1" navigation controller's responsiveness in this specific state.

*   **Lower Values (0.1 - 0.4):** More aggressive corrections. The plane will try very hard to stay on the line, but might wobble.
*   **Higher Values (0.5 - 1.0):** Smoother, lazier corrections. The plane will wander more but flight will be more stable.

## Tuning & Behavior
*   **Default:** 0.4.
*   **Usage:** Only relevant for planes configured for Deep Stall landings (e.g. some foam hobby planes and specialized UAVs).