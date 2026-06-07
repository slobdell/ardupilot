# Weather Vane Configuration (WVANE)

## Overview
The **WVANE** parameter group configures the **Weather Vane** (Wind Vane) subsystem for **multicopters** and **QuadPlanes**. This allows the vehicle to autonomously rotate its nose (Yaw) into the wind while hovering or during VTOL transition.

## Key Concepts

### 1. Into-The-Wind Navigation
Multicopters are most stable and efficient when pointing into the wind (reduced drag, better cooling, less motor imbalance).
*   **`WVANE_ENABLE`**: Master switch.
*   **`WVANE_GAIN`**: How aggressively the drone rotates into the wind.

### 2. Transition Assist
For QuadPlanes, pointing into the wind during a vertical-to-forward transition is critical to prevent the wind from getting under the wings and flipping the aircraft (stalling).

## Parameter Breakdown

*   **`WVANE_ENABLE`**:
    *   **0:** Disabled.
    *   **1:** Always rotate into the wind.
    *   **2:** Only in specific modes (e.g., Loiter).
*   **`WVANE_ANG_MIN`**: The minimum wind angle required to start a rotation.

## Developer Notes
*   **Library:** `libraries/AC_WeatherVane`.
*   **Estimation:** Can use a physical wind vane or estimate wind direction using the multicopter's lean angle (drag model).