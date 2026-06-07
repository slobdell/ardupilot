---
layout: parameter
name: LAND_DS_V_FWD
display_name: Deepstall Forward Velocity
description: The expected forward velocity (in m/s) of the aircraft while in a deepstall (fully stalled).
default_value: 1
range: 0 20
units: m/s
group: LAND
visual_asset_id: deepstall_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Landing/AP_Landing_Deepstall.cpp#L32
---

# Deepstall Forward Velocity (LAND_DS_V_FWD)

## Description
`LAND_DS_V_FWD` is a prediction parameter for Deepstall landings (where the plane purposefully stalls to drop vertically).

Because the aircraft has no lift and very little control, the autopilot needs to "guess" how much it will drift forward while falling. This allows it to calculate the exact point in the air to trigger the stall so that the drone lands on the target.

## The Mathematics
The predicted travel distance $D$ is calculated using the ratio of forward speed $V_{fwd}$ to sink rate $V_{dwn}$:

$$ D_{drift} = \frac{V_{fwd} \times \text{Height}}{V_{dwn}} + \text{Stall Entry Distance} $$

## Tuning & Behavior
*   **Default Value:** 1.0 m/s.
*   **Tuning:** If the plane consistently lands **Short** of the target, decrease this value. If it lands **Long**, increase it.