---
layout: parameter
name: RLL_RATE_P
display_name: Roll Rate P Gain
description: The proportional gain for the roll rate controller. Corrects for errors between the desired roll rate and the actual roll rate.
default_value: 0.15
range: 0.08 0.35
units: 
group: RLL
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate P Gain (RLL_RATE_P)

## Description
`RLL_P` is the "Instant Reaction" gain for your plane's roll axis.

When you move the aileron stick, you are commanding a roll rate (degrees per second). If the plane isn't rolling fast enough, `P` adds more aileron deflection immediately.

*   **Too Low:** The plane feels sluggish and disconnected. It takes a moment to start rolling.
*   **Too High:** The plane oscillates (wobbles) quickly in roll.

## The Mathematics
$$ \text{Output} = k_P \cdot (\text{Rate}_{target} - \text{Rate}_{actual}) $$

## Tuning & Behavior
*   **Default Value:** 0.15.
*   **Recommendation:** Use **Autotune** to find the perfect value for your airframe.
*   **Manual Tuning:** Increase P until you see oscillations, then reduce by 30%.