---
layout: parameter
name: Q_FWD_MANTHR_MAX
display_name: Pilot Manual Forward Throttle
description: Maximum throttle percentage (0-100) allowed for manual control of the forward motor in VTOL modes using a dedicated RC channel.
default_value: 0
range: 0 100
units: '%'
group: Q
visual_asset_id: vtol_vfwd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Pilot Manual Forward Throttle (Q_FWD_MANTHR_MAX)

## Description
`Q_FWD_MANTHR_MAX` allows the pilot to "Gas it" while hovering.

If you have a dedicated slider or knob on your transmitter mapped to the forward motor, this parameter sets the maximum power that slider can command while the drone is in a VTOL mode.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set to **100%** if you want full manual authority over the pusher motor for repositioning the drone quickly in QHOVER.