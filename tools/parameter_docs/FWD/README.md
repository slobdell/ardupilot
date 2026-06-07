# Forward Thrust Configuration (FWD)

## Overview
The **FWD** parameter group configures voltage compensation for the **Forward Propulsion** motor on **QuadPlane** vehicles.

QuadPlanes often use two separate electrical systems: one for the vertical lift motors (VTOL) and a dedicated high-capacity pack for the forward motor (Fixed-Wing). To ensure consistent thrust as the cruising battery drains, the autopilot needs to know which battery to monitor for the forward motor.

## Key Concepts

### 1. Dual-Battery Voltage Compensation
The autopilot scales the throttle output based on the battery voltage. If the forward motor is on a separate battery, it must be told which monitor instance (`BATT1` vs `BATT2`) to look at.
*   **`FWD_BAT_IDX`**: Selects the monitor index.

## Parameter Breakdown

*   **`FWD_BAT_IDX`**: Battery monitor index for forward thrust.
*   **`FWD_BAT_VOLT_MIN` / `MAX`**: The voltage range used to calculate the compensation scaling factor.

## Integration Guide
*   **Setup:** If you have a single battery for everything, leave these at default.
*   **Setup (Dual Pack):** If your forward motor has its own battery monitor, set `FWD_BAT_IDX` to that monitor's ID.

## Developer Notes
*   **Library:** `ArduPlane/QuadPlane`.
*   **Context:** Only relevant for **VTOL / QuadPlane** configurations.