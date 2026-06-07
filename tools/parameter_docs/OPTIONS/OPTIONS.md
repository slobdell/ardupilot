---
layout: parameter
name: OPTIONS
display_name: "Winch options"
description: "Bitmask of winch behavior options"
default_value: 0
range: 0 3
units: "Bitmask"
group: OPTIONS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Winch/AP_Winch.cpp#L41
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Winch options (OPTIONS)

## Description
This parameter configures advanced behaviors for the Winch library.

## The Mathematics
Bitmask.

## The Engineer's View
Defined in `libraries/AP_Winch/AP_Winch.cpp`.
*   **Bit 0:** Spin Free on Release. If set, the motor is disabled (coasts) when the winch is released, rather than actively driving out.
*   **Bit 1:** Retry on Jam. If set, the winch will briefly reverse and try again if it detects a jam (current spike or stall).

## Tuning & Behavior
*   **Default Value:** 0
*   **Tuning:** Enable Bit 1 if your winch mechanism is prone to sticking.