---
layout: parameter
name: RLL_RATE_FLTT
display_name: Roll Rate Target Filter
description: The cutoff frequency (in Hz) for the target roll rate filter. Smooths out "steps" in the command signal.
default_value: 0
range: 0 50
units: Hz
group: RLL
visual_asset_id: filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate Target Filter (RLL_RATE_FLTT)

## Description
`RLL_RATE_FLTT` smooths the pilot's stick inputs before they reach the PID controller.

*   **0:** Disabled.
*   **5 Hz:** Very smooth, "cinematic" feel.
*   **20 Hz:** Sharp, responsive feel.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Use **3 - 5 Hz** if you want to fly smooth lines.