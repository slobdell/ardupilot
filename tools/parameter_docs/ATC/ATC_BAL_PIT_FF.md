---
layout: parameter
name: ATC_BAL_PIT_FF
display_name: Balance Bot Pitch Feed-Forward
description: The feed-forward gain for pitch-to-throttle control on self-balancing robots.
default_value: 0
range: 0 1
units: 
group: ATC
visual_asset_id: atc_bal_pit_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L371
---

# Balance Bot Pitch Feed-Forward (ATC_BAL_PIT_FF)

## Description
`ATC_BAL_PIT_FF` helps a Balance Bot (Segway-style) stay upright.

It adds throttle based on the current pitch angle. If the bot leans forward, it needs to accelerate forward to catch itself. This term provides the immediate response.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Fundamental tuning parameter for Balance Bots. Increase until the bot resists falling over.