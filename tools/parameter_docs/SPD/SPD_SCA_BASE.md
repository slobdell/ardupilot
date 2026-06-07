---
default_value: 1.0
description: Speed above which steering is scaled down when using regular steering/throttle vehicles.
display_name: Motor speed scaling base speed
group: SPD
investigation_status: complete
layout: parameter
name: SPD_SCA_BASE
range: 0 10
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AR_Motors/AP_MotorsUGV.cpp#L97
units: m/s
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Motor speed scaling base speed (SPD_SCA_BASE)

## Description
This parameter is used on Ground Vehicles (Rovers/Boats) with "Regular" steering (e.g., a front-wheel steering car). It defines the "Safe Speed" threshold for full steering authority.

As a rover drives faster, small steering inputs cause much more aggressive cornering, which can lead to rollovers or loss of traction. To prevent this, ArduPilot automatically scales down the steering output as the vehicle's speed increases. `SPD_SCA_BASE` is the speed at which this reduction begins.

## The Mathematics
The steering command is scaled linearly based on the ratio of the base speed to the current ground speed ($V_{ground}$):

$$ \text{IF } |V_{ground}| > SPD\_SCA\_BASE: $$
$$ \text{Steering}_{eff} = \text{Steering}_{cmd} \times \left( \frac{SPD\_SCA\_BASE}{|V_{ground}|} \right) $$

If the vehicle is moving slower than the base speed, the multiplier is **1.0** (no reduction).

## The Engineer's View
In `AP_MotorsUGV::output_regular()` (`libraries/AR_Motors/AP_MotorsUGV.cpp`):
1.  The code checks if `_speed_scale_base` is positive.
2.  It compares the current ground speed to this base.
3.  The inverse scaling is applied to the steering term.
4.  This implementation is essentially an "Electronic Steering Rack" that becomes slower and more stable at high speeds, mirroring the behavior of modern high-performance automobiles.

## Tuning & Behavior
*   **Default Value:** 1.0 m/s.
*   **Effect of Increasing:** The vehicle maintains full steering sensitivity at higher speeds. Useful for slow, high-torque crawlers.
*   **Effect of Decreasing:** The steering becomes "stiffer" (less sensitive) sooner as you accelerate. Recommended for fast on-road rovers to prevent high-speed flipping.
*   **0:** Disables speed scaling entirely. Use with caution on fast vehicles.
