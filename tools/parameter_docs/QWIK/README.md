# QuickTune Configuration (QWIK)

## Overview
The **QWIK** parameter group configures the **QuickTune** Lua script (and integrated library in newer versions). QuickTune is a faster, more automated alternative to the standard AutoTune mode for multicopters.

While AutoTune requires the pilot to toggle a switch and wait for individual axis twitches, QuickTune can automatically find gains while the pilot is flying naturally or during a mission.

## Key Concepts

### 1. Oscillation Detection
QuickTune monitors the gyro data for high-frequency oscillations that indicate a PID gain is too high.
*   **`QWIK_ENABLE`**: Master switch.
*   **`QWIK_AUTO_FILTER`**: If enabled, the system also tries to set the optimal low-pass filter frequencies based on the noise profile.

### 2. Auto-Save (`QWIK_AUTO_SAVE`)
Determines if the new gains are applied permanently.
*   **0:** Trial only.
*   **1:** Save to EEPROM automatically once the tune converges.

## Parameter Breakdown

*   **`QWIK_AXES`**: Bitmask of axes to tune (Roll, Pitch, Yaw).
*   **`QWIK_GAIN_MARGIN`**: The safety margin applied once an oscillation is detected (e.g., set gain to 60% of the oscillation point).

## Integration Guide
1.  **Script:** Ensure the `quiktune.lua` script is in the `scripts` folder on the SD card.
2.  **Enable:** Set `QWIK_ENABLE = 1`.
3.  **Tuning:** Fly the vehicle in Loiter or AltHold. Perform some rapid stick movements.
4.  **Verify:** Check the GCS messages for "QuickTune: Roll P set to X."

## Developer Notes
*   **Library:** `libraries/AP_Scripting` (usually as a Lua implementation).