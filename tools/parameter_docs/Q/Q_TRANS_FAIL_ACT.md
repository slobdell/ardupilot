---
layout: parameter
name: Q_TRANS_FAIL_ACT
display_name: QuadPlane Transition Failure Action
description: The action to take if the transition fails (0=Warning, 1=QLand).
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_transition_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Transition Failure Action (Q_TRANS_FAIL_ACT)

## Description
`Q_TRANS_FAIL_ACT` decides what to do if `Q_TRANS_FAIL` triggers.

*   **0:** Warn only (Text message on GCS).
*   **1:** QLAND (Immediately land vertically).

## Tuning & Behavior
*   **Default Value:** 0.