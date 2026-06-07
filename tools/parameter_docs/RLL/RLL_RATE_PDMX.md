---
layout: parameter
name: RLL_RATE_PDMX
display_name: Roll Rate PD Max
description: The maximum allowed output for the sum of the P and D terms in the roll rate controller.
default_value: 0
range: 0 1.0
units: 
group: RLL
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate PD Max (RLL_RATE_PDMX)

## Description
`RLL_RATE_PDMX` limits the total effort of the P and D terms.

It ensures that the high-speed portion of the PID loop (which reacts to quick movement) doesn't over-saturate the servos, leaving room for the slower, long-term I-term to do its job of keeping the plane level.

*   **0 (Default):** Disabled (No limit).
*   **0.5:** Limits the PD sum to 50% of the total servo travel.