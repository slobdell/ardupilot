# Throw Mode Configuration (THROW)

## Overview
The **THROW** parameter group configures the **Throw Mode** for multicopters. This specialized mode allows the pilot to literally throw the drone into the air; the autopilot detects the freefall and autonomously stabilizes the vehicle and powers up the motors.

## Key Concepts

### 1. Detection Type (`THROW_TYPE`)
Determines how the "throw" is identified.
*   **Upward Throw:** Drone is tossed up.
*   **Drop:** Drone is released from height.

### 2. Startup Sequence
*   **`THROW_MOT_START`**: Defines when the motors should start spinning (e.g., at the peak of the arc or after a delay).

## Parameter Breakdown

*   **`THROW_NEXTMODE`**: The flight mode the vehicle automatically switches to after a successful throw stabilization (usually `LOITER`).
*   **`THROW_ALT_MIN`**: Safety altitude floor for activation.

## Integration Guide
1.  **Arm:** Arm the vehicle while holding it.
2.  **Switch:** Change mode to `THROW`.
3.  **Toss:** Throw the drone clear of your body.
4.  **Auto-Start:** The autopilot will detect the freefall, stabilize level, and then switch to the mode defined in `THROW_NEXTMODE`.

## Developer Notes
*   **Library:** `ArduCopter/mode_throw.cpp`.
*   **Safety:** **EXTREMELY DANGEROUS.** Only use with small drones and ensure you have a clear area.