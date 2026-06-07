---
layout: parameter
name: NAVL1_LIM_BANK
display_name: "Loiter Radius Bank Angle Limit"
description: "The sealevel bank angle limit for a continuous loiter"
default_value: 0.0f
range: 0 89
units: "deg"
group: NAVL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_L1_Control/AP_L1_Control.cpp#L39
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_L1_Control/AP_L1_Control.h#L125
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Loiter Radius Bank Angle Limit (NAVL1_LIM_BANK)

## Description
This parameter enforces a structural or aerodynamic limit on the bank angle during loiters, normalized to sea-level air density. As altitude increases, True Airspeed (TAS) increases for the same Indicated Airspeed (IAS), which naturally increases the turn radius. This parameter ensures that the bank angle required to maintain a specific loiter radius does not exceed the airframe's loading limits.

## The Mathematics
$$ R_{\text{turn}} = \frac{V_{TAS}^2}{g \cdot \tan(\phi)} $$

If `NAVL1_LIM_BANK` is set > 0, the navigation controller calculates the maximum allowable bank angle based on air density and scales the loiter radius `WP_LOITER_RAD` upwards if necessary to stay within this bank limit.

## The Engineer's View
Defined in `libraries/AP_L1_Control/AP_L1_Control.cpp`. It is a safety feature for high-altitude or high-speed operations.
*   **0:** Disabled. The standard roll limits apply, and the vehicle attempts to fly the requested `WP_LOITER_RAD`.
*   **>0:** The L1 controller dynamically increases the loiter radius to prevent banking more than this value (at equivalent sea-level loading).

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Typical:** 0 for most users. 45-60 degrees for high-performance aircraft to prevent stall or structural failure in tight turns at altitude.