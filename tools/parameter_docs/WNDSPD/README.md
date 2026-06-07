# Wind Speed Thresholds (WNDSPD)

## Overview
The **WNDSPD** parameter group (specifically `WNDSPD_MIN`) configures the environmental thresholds for specialized vehicle behaviors.

## Key Concepts

### 1. Sailing Threshold (`WNDSPD_MIN`)
(ArduRover Sailboat) Defines the minimum wind speed required to engage the sailing logic.
*   **Behavior:** If the wind is below this threshold, the boat may rely on its motor (if equipped) rather than attempting to tack inefficiently.

## Developer Notes
*   **Library:** `Rover/sailboat.cpp`.