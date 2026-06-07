---
layout: parameter
name: STARTUP_DELAY
display_name: "Delay before first servo movement from trim"
description: "Startup delay in seconds before servos move"
default_value: 0
range: 0 10
units: "s"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L89
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Delay before first servo movement from trim (STARTUP_DELAY)

## Description
This parameter introduces a pause at system startup during which the Antenna Tracker servos are held at their trim (neutral) positions. This delay allows the system to stabilize, sensors to initialize, or the operator to stand clear before active tracking movement begins.

## The Mathematics
Timer wait loop.

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`.
*   **0:** No delay. Servos move immediately upon initialization.
*   **>0:** Wait time in seconds.

## Tuning & Behavior
*   **Default Value:** 0 s
*   **Usage:** Set to 2-5 seconds if your tracker tends to jerk violently on power-up.