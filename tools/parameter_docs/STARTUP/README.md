# Startup Delay Configuration (STARTUP)

## Overview
The **STARTUP** parameter group (specifically `STARTUP_DELAY`) manages the initialization timing for the **Antenna Tracker**.

## Key Concepts

### 1. Servo Warm-up
Some high-power servos or mechanical systems can draw massive current spikes or jitter violently if commanded immediately upon power-on.
*   **`STARTUP_DELAY`**: Introduces a wait time (in seconds) during which the servos are held at their neutral trim position before active tracking begins.

## Developer Notes
*   **Library:** `AntennaTracker/Parameters.cpp`.