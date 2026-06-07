---
layout: parameter
name: FSTRATE_ENABLE
display_name: "Fast Rate Thread Enable"
description: "Enables a dedicated high-priority thread for fast-rate control loop execution."
default_value: 0
range: 0 1
units: "Option"
group: FSTRATE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Copter.cpp#L198
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Fast Rate Thread Enable (FSTRATE_ENABLE)

## Description
This parameter enables a dedicated, high-priority thread for the main attitude control loop. 

By offloading the critical "Fast Loop" (typically 400Hz or higher) to its own thread, ArduPilot can ensure that attitude stabilization is prioritized above all other tasks (like logging, telemetry, or mission logic). This reduces "jitter" in the control loop timing and allows the vehicle to fly smoother and more locked-in.

## The Mathematics
When enabled, the scheduler splits the workload:
*   **Main Thread:** Handles 10Hz to 50Hz tasks (Navigation, GPS, Logging).
*   **Fast Thread:** Handles 400Hz+ tasks (Gyro sampling, Rate PID loops, Motor output).

The update rate of this thread is controlled by `FSTRATE_DIV`, which divides the raw gyro sample rate.

## The Engineer's View
In `ArduCopter/Copter.cpp` (and the scheduler logic), this flag triggers the creation of the `FastLoop` thread.
*   **0: Disabled.** All code runs in a single main loop. This is safer for very low-end boards but less performant.
*   **1: Enabled.** The rate controller runs in parallel with the rest of the code.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled) on older firmware/boards. Often 1 on modern H7 boards.
*   **Recommendation:** Enable this on any modern flight controller (STM32F7/H7). It significantly improves flight performance.
*   **Note:** If you see "Scheduler Overrun" errors after enabling this, your loop rate might be set too high for the processor.
