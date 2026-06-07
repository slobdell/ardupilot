# Scheduler Debug (DEBUG)

## Overview
The **DEBUG** parameter group (containing the single parameter `DEBUG`) controls the verbosity of the internal **Task Scheduler**.

ArduPilot runs a cooperative scheduler that manages hundreds of tasks (Attitude loop, GPS update, Logging, etc.). If a task takes too long, it can delay critical flight control loops. This parameter helps developers identify those bottlenecks.

## Key Concepts

### 1. Scheduler Slips
A "Slip" occurs when the scheduler cannot run a task at its intended frequency because the CPU is busy doing something else.

### 2. Task Overruns
An "Overrun" occurs when a specific task takes more time to execute than it was allocated budget for (e.g., a logging task taking 500us when it should only take 100us).

## Parameter Breakdown

*   **`DEBUG`**:
    *   **0:** Disabled.
    *   **1 (Show Slips):** Report when the main loop runs late.
    *   **2 (Show Overruns):** Report which task caused the delay.
    *   **3 (Show Load):** Report CPU utilization.

## Integration Guide
*   **Performance Tuning:** If you see "Scheduler Slips" in the message log during flight, enable `DEBUG = 2` to find the culprit task.
*   **Warning:** Enabling debug output consumes CPU itself. Turn off for normal flight.

## Developer Notes
*   **Library:** `libraries/AP_Scheduler`