---
layout: parameter
name: Q_OPTIONS
display_name: QuadPlane Options
description: A bitmask of options to modify QuadPlane behavior.
default_value: 0
range: 0 4294967295
units: 
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Options (Q_OPTIONS)

## Description
`Q_OPTIONS` enables specialized behaviors for VTOL flight.

*   **Bit 0 (1):** Level Transitions. Keep wings level during transition (default is to bank).
*   **Bit 1 (2):** Allow taking off in fixed-wing modes (auto-transition).
*   **Bit 3 (8):** Disarm motors in QuadPlane modes on crash detection.
*   **Bit 5 (32):** Thrusters always active in Q modes (for tailsitters).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set **Bit 16 (65536)** to suppress "QuadPlane warnings" if you know what you are doing.