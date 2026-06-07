---
layout: parameter
name: SCHED_OPTIONS
display_name: Scheduling options
description: Bitmask for advanced scheduler diagnostic features.
default_value: 0
range: 0 1
units: 
group: SCHED
visual_asset_id: sched_options_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scheduler/AP_Scheduler.cpp#L66
---

# Scheduling options (SCHED_OPTIONS)

## Description
`SCHED_OPTIONS` enables specialized performance tracking within the autopilot's operating system.

*   **Bit 0 (1): Enable per-task perf info.** If enabled, ArduPilot will track exactly how many microseconds every individual task (like "Baro Update" or "Compass Read") takes to complete. This is vital for developers or users experiencing unexplained twitches or CPU spikes.

## The Engineer's View
When Bit 0 is set, the `AP::PerfInfo` module allocates extra memory to store timing statistics for every item in the scheduler task table. These statistics can be viewed in real-time by downloading the `@SYS/tasks.txt` file via MAVLink FTP.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled to save memory and CPU).
*   **Recommendation:** Leave at **0** for normal flight. Enable only if you are diagnosing "Internal Error 0x1000" or high system load.