# Sailboat Configuration (SAIL)

## Overview
The **SAIL** parameter group configures the **Autonomous Sailing** logic for **ArduRover**.

This library allows rovers (Boats) to navigate using wind power. It manages complex sailing behaviors like tacking, jibing, and sail trim based on wind direction.

## Key Concepts

### 1. Sail Control Types (`SAIL_TYPE`)
Defines the hardware used for sail adjustment.
*   **0:** Manual (Servo direct).
*   **1:** Winch (Standard servo/winch).
*   **2:** Wing Sail (Rotating mast/wing).

### 2. Upwind Navigation (`SAIL_NO_GO_ANGLE`)
Boats cannot sail directly into the wind. If a waypoint is upwind, the autopilot will autonomously calculate a "tack" (zig-zag) path to reach it.
*   **`SAIL_NO_GO_ANGLE`**: The angle relative to the wind (typically 45°) where the boat cannot maintain speed.

### 3. Safety (`SAIL_HEEL_MAX`)
To prevent capsizing, the autopilot monitors the roll angle. If the boat heels past this limit, the sails are automatically eased to dump wind pressure.

## Parameter Breakdown

*   **`SAIL_ENABLE`**: Master switch.
*   **`SAIL_ANGLE_IDEAL`**: Optimal sail angle for maximum thrust.
*   **`SAIL_WNDSPD_MIN`**: Minimum wind speed required to attempt sailing.

## Integration Guide
1.  **Hardware:** Requires a **Wind Vane** sensor (`WNDVN_TYPE`) to see the wind direction.
2.  **Enable:** Set `SAIL_ENABLE = 1`.
3.  **Calibrate:** Ensure the wind vane is aligned with the boat's nose.
4.  **Mode:** Use `AUTO`, `GUIDED`, or `ACRO` to see the sailing logic in action.

## Developer Notes
*   **Library:** `Rover/sailboat.cpp`.
*   **Navigation:** Integrated with the L1 controller to handle tacking and crosstrack limits.