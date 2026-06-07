# Lua Scripting Configuration (SCR)

## Overview
The **SCR** parameter group configures the **On-Board Lua Scripting** engine. This is a powerful feature that allows users to add custom behaviors, flight modes, or hardware drivers to ArduPilot without needing to recompile the C++ source code.

Lua scripts run in a sandboxed environment on the autopilot's SD card, interacting with the system via a controlled API.

## Key Concepts

### 1. The Sandbox (`SCR_HEAP_SIZE`)
Lua scripts require dedicated RAM.
*   **`SCR_HEAP_SIZE`**: The total amount of memory (in bytes) allocated for the Lua engine.
    *   **Pixhawk 1:** Not supported (Insufficient RAM).
    *   **F7/H7 Boards:** Typically 40kB to 200kB.
    *   **Requirement:** If you load many or complex scripts, you must increase this value.

### 2. User Parameters (`SCR_USERx`)
Allows scripts to have their own tunable parameters.
*   **`SCR_USER1`..`6`**: Integer values.
*   **`SCR_USER_FLOAT`**: Floating point values.
*   **Usage:** A script can read `SCR_USER1` and use it as a gain or a threshold.

### 3. Scripting Devices (`SCR_SDEV_...`)
Enables scripts to access specialized serial or I2C protocols.

## Parameter Breakdown

*   **`SCR_ENABLE`**: Master switch.
*   **`SCR_DEBUG_OPTS`**: Toggles error reporting and memory usage logs.

## Integration Guide
1.  **Preparation:** Use an H7 flight controller (e.g., Orange Cube).
2.  **Enable:** Set `SCR_ENABLE = 1`.
3.  **Allocate:** Ensure `SCR_HEAP_SIZE` is sufficient (default 40,960 is usually okay for 1-2 scripts).
4.  **Install:** Copy your `.lua` files to the `scripts/` folder on the SD card.
5.  **Reboot.**

## Developer Notes
*   **Library:** `libraries/AP_Scripting`.
*   **Safety:** Lua is run in a separate low-priority thread to ensure it can't interfere with the flight control PIDs.