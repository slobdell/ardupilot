---
layout: parameter
name: Q_LOIT_OPTIONS
display_name: QLoiter mode options
description: Bitmask of options to change QLoiter behavior.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: q_loiter_options_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L291
---

# QLoiter mode options (Q_LOIT_OPTIONS)

## Description
`Q_LOIT_OPTIONS` modifies the behavior of the QuadPlane **QLOITER** (VTOL Loiter) flight mode.

*   **Bit 0 (1):** Allow QLoiter to hold position without GPS (using Optical Flow or other non-GPS sources).

## The Mathematics
$$ \text{Behavior} = \sum 2^i \cdot b_i $$

## The Engineer's View
Used in `QuadPlane::mode_qloiter` logic.
If Bit 0 is set, the strict check for a 3D GPS lock is relaxed, allowing the vehicle to enter and maintain QLOITER using alternative position sources like Optical Flow or Visual Odometry.

## Tuning & Behavior
*   **Default Value:** 0 (Require GPS)
*   **Recommendation:**
    *   **GPS Flight:** Leave at 0.
    *   **Indoor/Non-GPS Flight:** Set to **1** if you have a valid Optical Flow or VIO setup and want to loiter.