---
layout: parameter
name: CRASH_ACC_THRESH
display_name: "Crash Deceleration Threshold"
description: "X-Axis deceleration threshold to trigger crash detection"
default_value: 0
range: 0 127
units: "m/s/s"
group: CRASH
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L751
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Crash Deceleration Threshold (CRASH_ACC_THRESH)

## Description
This parameter sets the sensitivity of the crash detection logic in ArduPlane. If the aircraft experiences a sudden deceleration (impact) along its longitudinal axis (X-axis) exceeding this value, the autopilot assumes a crash has occurred and instantly disarms the motor to prevent fire, injury, or further damage.

## The Mathematics
$$ \text{Crash Triggered} \iff a_x < -\text{CRASH_ACC_THRESH} $$
*(Where negative $a_x$ represents sudden braking/impact).*

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`. Checked in the main loop or inertial nav task.
*   **0:** Crash detection disabled.
*   **Note:** False positives can occur during rough landings or bungee launches if set too low.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Typical:** 25 m/s/s (~2.5G) for foamies.
*   **Adjustment:** Increase if you get disarmed during hard landings. Decrease if it fails to disarm on impact.