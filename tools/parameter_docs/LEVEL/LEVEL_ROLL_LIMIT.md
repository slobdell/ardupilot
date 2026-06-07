---
layout: parameter
name: LEVEL_ROLL_LIMIT
display_name: "Level flight roll limit"
description: "This controls the maximum bank angle in degrees during flight modes where level flight is desired"
default_value: 5
range: 0 45
units: "deg"
group: LEVEL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L229
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Level flight roll limit (LEVEL_ROLL_LIMIT)

## Description
This safety parameter defines the maximum allowable roll (bank) angle during critical near-ground flight phases, specifically Auto-Takeoff and Landing (during the flare). By limiting the bank angle, it prevents the wingtips from striking the ground/runway, which could cause a crash.

## The Mathematics
During takeoff (below a certain altitude) and landing flare:

$$ |\phi_{demand}| \le \text{LEVEL_ROLL_LIMIT} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`.
*   **Takeoff:** Used when altitude is < 5m or during the initial climb.
*   **Landing:** Used during the `FLARE` stage of an auto-landing.
*   **Zero Logic:** If set to 0, it completely disables the heading hold controller during these phases, which effectively means the roll is not actively controlled to level (dangerous).

## Tuning & Behavior
*   **Default Value:** 5 deg
*   **Range:** 0 - 45
*   **Recommended:** Keep small (5-10 deg) to ensure wing clearance.
*   **Warning:** Do not set to 0 unless you understand the implications of disabling heading hold during takeoff/landing.