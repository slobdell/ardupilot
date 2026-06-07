---
layout: parameter
name: THR_SUPP_MAN
display_name: "Throttle suppress manual passthru"
description: "Allow manual throttle control when suppressed in auto modes"
default_value: 0
range: 0 1
units: ""
group: THR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L406
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Throttle suppress manual passthru (THR_SUPP_MAN)

## Description
This parameter changes the behavior of the "Throttle Suppression" feature in ArduPlane. Normally, when the autopilot suppresses the throttle (e.g., because the aircraft is on the ground or in a landing flare), the motor output is forced to 0 (Idle/Off). Enabling this parameter allows the pilot's manual throttle stick to override this suppression, keeping the engine running at the stick-commanded speed.

## The Mathematics
$$ \text{Throttle}_{\text{out}} = (\text{Suppressed}) ? \text{Throttle}_{\text{stick}} : \text{Throttle}_{\text{auto}} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`.
*   **Target Audience:** Gas/Nitro planes where 0 throttle might kill the engine, or for pilots who want manual idle control during auto-takeoff waits.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **1:** Enable manual pass-through during suppression.