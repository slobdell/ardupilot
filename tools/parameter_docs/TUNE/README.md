# In-Flight Tuning Configuration (TUNE)

## Overview
The **TUNE** parameter group configures the **Transmitter Tuning** feature. This allows the pilot to map a PID gain or other parameter (like `ATC_RAT_RLL_P`) to a knob or slider on their RC transmitter.

This is a powerful tool for finding the "Sweet Spot" of a gain while the vehicle is in the air.

## Key Concepts

### 1. Parameter Selection (`TUNE_PARAM`)
Defines which parameter is currently mapped to the transmitter knob.
*   **0:** Disabled.
*   **1:** Roll Rate P.
*   **2:** Roll Rate I.
*   **...** (See Wiki for full list).

### 2. Scaling (`TUNE_MIN` / `MAX`)
Defines the range of the knob.
*   **`TUNE_MIN`**: The value of the parameter when the knob is at its minimum position.
*   **`TUNE_MAX`**: The value at maximum position.

## Parameter Breakdown

*   **`TUNE_CHAN`**: The RC input channel assigned to the tuning knob.
*   **`TUNE_SELECTOR`**: Allows assigning a 3-position switch to toggle *what* parameter is being tuned (e.g., Switch Low = P, Mid = I, High = D).

## Integration Guide
1.  **Map Channel:** Set `TUNE_CHAN` to your slider channel.
2.  **Select Param:** Set `TUNE_PARAM = 1` (Roll P).
3.  **Set Range:** If your current P is 0.1, set `MIN = 0.05` and `MAX = 0.2`.
4.  **Fly:** Move the slider until the drone feels stable but crisp. Land and check the value.

## Developer Notes
*   **Library:** `libraries/AP_Tuning`.