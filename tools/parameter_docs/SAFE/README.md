# Safety Configuration (SAFE)

## Overview
The **SAFE** parameter group (specifically `SAFE_DISARM_PWM`) configures the output safety state for the **Antenna Tracker**.

## Key Concepts

### 1. Disarmed Safety
When the tracker is disarmed or in "Stop" mode, it is important to define what the servos do.
*   **`SAFE_DISARM_PWM`**:
    *   **0:** Zero PWM. Servos are unpowered/limp.
    *   **1:** Trim PWM. Servos hold their center (neutral) position.

## Developer Notes
*   **Library:** `AntennaTracker/Parameters.cpp`.