# Disable Axis Mask (DIS)

## Overview
The **DIS** parameter group (specifically `DIS_MASK`) is a utility feature primarily found in **ArduBlimp** (and sometimes Sub/Rover) to selectively disable control axes.

## Key Concepts

### 1. Axis Isolation
When tuning or testing a complex vehicle like a Blimp, it is often useful to disable certain axes (e.g., disable Yaw control to focus on Pitch tuning). This mask allows enabling/disabling axes without unplugging motors.

## Parameter Breakdown

*   **`DIS_MASK`**: Bitmask of axes to disable.
    *   **Bit 0:** Disable Sway (Y).
    *   **Bit 1:** Disable Surge (X).
    *   **Bit 2:** Disable Heave (Z).
    *   **Bit 3:** Disable Yaw.

## Integration Guide
*   **Default:** 0 (All enabled).
*   **Usage:** Set to 15 (1+2+4+8) to disable all output for safe bench testing of other systems.

## Developer Notes
*   **Library:** `ArduBlimp` (Vehicle specific).