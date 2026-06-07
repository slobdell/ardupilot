---
layout: parameter
name: SCHED_DEBUG
display_name: Scheduler debug level
description: Set to non-zero to enable scheduler debug messages. When set to show "Slips" the scheduler will display a message whenever a scheduled task is delayed due to too much CPU load. When set to ShowOverruns the scheduled will display a message whenever a task takes longer than the limit promised in the task table.
default_value: 0
range: 0 3
units: 
group: SCHED
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scheduler/AP_Scheduler.cpp#L53
---

# SCHED_DEBUG: Scheduler debug level

## Description
Set to non-zero to enable scheduler debug messages.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 2 | Show Slips (Delayed tasks) |
| 3 | Show Overruns (Long-running tasks) |

- **Default:** 0

## Description
This parameter is a diagnostic tool for monitoring the real-time performance of the autopilot's operating system (the Scheduler).

- **Function:** If the CPU becomes overloaded, the scheduler may have to delay certain tasks ("Slips") or a specific task may take longer than its allocated time budget ("Overruns").
- **Usage:** Set to **2 or 3** during troubleshooting to see warning messages in the MAVLink console or Ground Control Station. These messages indicate that the flight controller is struggling to keep up with the workload.
- **Normal Operation:** Should be left at **0** to avoid flooding the communication link with debug data.
