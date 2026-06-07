---
layout: parameter
name: DEBUG
display_name: "Scheduler debug level"
description: "Set to non-zero to enable scheduler debug messages"
default_value: 0
range: 0 3
units: ""
group: DEBUG
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scheduler/AP_Scheduler.cpp#L59
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scheduler/AP_Scheduler.h#L135
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Scheduler debug level (DEBUG)

## Description
This parameter controls the debug output of the real-time task scheduler. It is used by developers and advanced integrators to diagnose performance issues, such as CPU overload, loop rate instability, or specific tasks taking too long to execute.

## The Mathematics
N/A. Enum configuration.

## The Engineer's View
Defined in `libraries/AP_Scheduler/AP_Scheduler.cpp`.
*   **0 (Disabled):** Normal operation.
*   **1 (Show Slips):** Logs a message if a task runs later than scheduled (Scheduler Slip).
*   **2 (Show Overruns):** Logs a message if a task exceeds its allocated time budget.
*   **3 (Show Load):** Displays CPU load statistics.

## Tuning & Behavior
*   **Default Value:** 0
*   **Use Case:** Enable temporarily if you suspect the flight controller is overloaded or if you are developing new code and want to verify timing compliance.