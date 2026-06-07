---
layout: parameter
name: SCR_THD_PRIORITY
display_name: "Scripting thread priority"
description: "Sets the CPU scheduling priority for the Lua scripting thread."
default_value: 0
range: 0 8
units: "Priority Level"
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L163
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Scripting thread priority (SCR_THD_PRIORITY)

## Description
This parameter determines how much "CPU Importance" is given to the Lua scripting engine relative to other autopilot tasks (like reading sensors, calculating motors, or handling radio telemetry). 

By default, scripting runs at a low priority to ensure that even if a script is poorly written or very complex, it cannot "choke" the critical flight control logic. However, for specialized applications where a script needs to handle high-speed data or tight control loops, this priority can be raised.

**WARNING:** Raising this priority unnecessarily can lead to system instability, watchdog resets, or loss of control if your scripts consume too much CPU time.

## The Mathematics
The priority levels are mapped to the underlying RTOS (Real-Time Operating System) thread scheduler:

*   **0: Normal.** Standard background priority.
*   **1: IO.** Matches Input/Output tasks.
*   **3: UART.** Matches Serial communication priority.
*   **7: Main.** Matches the main flight control loop. **(Extremely Dangerous)**.
*   **8: Boost.** Highest possible priority.

## The Engineer's View
In `AP_Scripting::init()` (`libraries/AP_Scripting/AP_Scripting.cpp`), the value of `_thd_priority` is translated into a `hal_priority` via an internal `priority_map`. 
This priority is then passed to the `hal.scheduler->thread_create()` call. 

Note that all Lua scripts run within the **same single thread**. If you raise the priority, you are raising it for every script on your SD card simultaneously. You must audit your scripts for "busy-waits" or long execution times before increasing this setting.

## Tuning & Behavior
*   **Default Value:** 0 (Normal).
*   **When to Increase:** Only if your script is failing to meet timing requirements (e.g., missing high-speed serial data or failing to update a custom LED driver at the desired rate).
*   **When to Decrease:** Never; 0 is already the safest background level.
*   **Reboot Required:** Yes. Thread creation happens only during the boot sequence.

