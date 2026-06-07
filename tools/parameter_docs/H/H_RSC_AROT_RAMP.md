---
layout: parameter
name: H_RSC_AROT_RAMP
display_name: Autorotation Bailout Ramp Time
description: The time (in seconds) to ramp the motor from idle to full flight power when exiting an autorotation.
default_value: 2.0
range: 0.1 10.0
units: s
group: H
visual_asset_id: heli_rsc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Autorotation/RSC_Autorotation.cpp#L29
---

# Autorotation Bailout Ramp Time (H_RSC_AROT_RAMP)

## Description
`H_RSC_AROT_RAMP` controls the "Power-Up Speed" after an autorotation.

If you abort an autorotation (Bailout), you want power back quickly, but not so fast that it snaps the main gears or causes a tail kick.

*   **ESC with Bailout Mode:** Set this to **0.1s**. The ESC will handle its own fast-ramp.
*   **Standard ESC:** Set to **2.0s - 4.0s**.
