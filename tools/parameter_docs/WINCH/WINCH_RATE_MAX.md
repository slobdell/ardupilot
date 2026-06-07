---
layout: parameter
name: WINCH_RATE_MAX
display_name: "Winch deploy or retract rate maximum"
description: "Maximum rate of line deployment or retraction with no load"
default_value: 1.0f
range: 0 10
units: "m/s"
group: WINCH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Winch/AP_Winch.cpp#L27
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Winch/AP_Winch.h#L63
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Winch deploy or retract rate maximum (WINCH_RATE_MAX)

## Description
This parameter sets the hard limit for the winch motor's speed when deploying or retracting the tether. It protects the winch mechanism from over-speeding, particularly in "slack line" conditions where the load is minimal.

## The Mathematics
$$ \omega_{\text{cmd}} = \min(\omega_{\text{req}}, \text{WINCH_RATE_MAX}) $$

## The Engineer's View
Defined in `libraries/AP_Winch/AP_Winch.cpp`. The winch library calculates the required rate based on the target length or velocity request, then clamps it to this value before sending the output to the ESC or servo.

## Tuning & Behavior
*   **Default Value:** 1.0 m/s
*   **Safety:** Ensure this value is within the safe operating limits of your physical winch hardware.