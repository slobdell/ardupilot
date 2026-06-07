# Real-Time Scheduler (SCHED)

## Overview
The **SCHED** parameter group configures the core **Task Scheduler** for ArduPilot. The scheduler is the heartbeat of the autopilot, responsible for prioritizing and running hundreds of distinct tasks (IMU sampling, PID loops, MAVLink, Logging) at precise intervals.

ArduPilot uses a cooperative multi-tasking model where each task is expected to run and return within a tiny time budget (e.g., 50 microseconds).

## Key Concepts

### 1. Loop Rate (`SCHED_LOOP_RATE`)
Defines the main frequency (Hz) of the attitude control loop.
*   **Multicopter:** Usually 400Hz (2.5ms loop) or 800Hz.
*   **Fixed Wing:** Usually 50Hz (20ms loop) or 100Hz.
*   **Importance:** Higher rates provide lower latency for control but require more CPU power.

### 2. Scheduler Options (`SCHED_OPTIONS`)
A bitmask for advanced scheduler features.
*   **Fast Loop:** Toggles the dedicated high-priority rate thread on H7 processors.

### 3. Debugging (`SCHED_DEBUG`)
Allows developers to monitor "Slips" (when the scheduler runs late) or "Overruns" (when a task takes too long).

## Parameter Breakdown

*   **`SCHED_LOOP_RATE`**: The primary control frequency.
*   **`SCHED_DEBUG`**: Verbosity of timing diagnostics.

## Integration Guide
*   **Warning:** **Do not change `SCHED_LOOP_RATE`** unless instructed by hardware documentation. Setting it too high can overload the CPU, causing "Main Loop Slow" errors and potentially a crash.

## Developer Notes
*   **Library:** `libraries/AP_Scheduler`.
*   **Priority:** The scheduler uses a fixed table of tasks with assigned priorities. `INS` (sensors) always run first.