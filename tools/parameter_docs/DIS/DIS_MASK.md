---
layout: parameter
name: DIS_MASK
display_name: "Disable output mask"
description: "Mask for disabling one or more of the 4 output axis in mode Velocity or Loiter"
default_value: 0
range: 0 15
units: "Bitmask"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Blimp/Parameters.cpp#L265
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Disable output mask (DIS_MASK)

## Description
This parameter allows specific control axes (Surge, Sway, Heave, Yaw) to be completely disabled when the Blimp is in **Velocity** or **Loiter** modes. This is typically used for testing, tuning individual axes, or for airframe configurations that lack actuation in certain directions.

## The Mathematics
The parameter is a bitmask. If a bit is set (1), the corresponding axis control output is forced to zero (or disabled logic).

*   **Bit 0:** Disable Y-axis (Sway / Right)
*   **Bit 1:** Disable X-axis (Surge / Forward)
*   **Bit 2:** Disable Z-axis (Heave / Down)
*   **Bit 3:** Disable Yaw

## The Engineer's View
Defined in `Blimp/Parameters.cpp`. Checked in `Blimp/Loiter.cpp` (and likely `ModeVelocity.cpp`).
Note the unusual ordering found in the source code: Bit 0 is checked against `err_xyz.y` and Bit 1 against `err_xyz.x`.

## Tuning & Behavior
*   **Default Value:** 0 (All axes enabled)
*   **1 (2^0):** Disable Sway.
*   **2 (2^1):** Disable Surge.
*   **4 (2^2):** Disable Heave.
*   **8 (2^3):** Disable Yaw.
*   **Example:** Set to 15 (1+2+4+8) to disable all control in these modes.