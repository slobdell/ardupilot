# Horizontal Controller Scaling (XY)

## Overview
The **XY** parameter group (specifically `XY_CTRL_MUL`) configures the gain scaling for horizontal movement.

## Key Concepts

### 1. Gain Multiplier (`XY_CTRL_MUL`)
(ArduPlane/SysID) This is a safety parameter used during automated tuning or experimental modes. It scales the horizontal position and velocity controller gains.
*   **Purpose:** Allows for "detuning" the position hold to prevent it from interfering with a test signal (e.g., during System Identification).

## Developer Notes
*   **Library:** `ArduPlane/systemid.cpp`.