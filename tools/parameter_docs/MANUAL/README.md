# Manual Mode Configuration (MANUAL)

## Overview
The **MANUAL** parameter group configures the behavior of the **Manual** flight/drive mode, primarily for **ArduRover**.

In Manual mode, the pilot's sticks are passed directly to the motor mixers with minimal autopilot intervention.

## Key Concepts

### 1. Steering Expo (`MANUAL_STR_EXPO`)
Similar to the `MAN` group in Plane, this adds an exponential curve to the Rover's steering stick. It makes the rover less twitchy when driving straight at high speeds.

### 2. Output Masking (`MANUAL_RCMASK`)
Allows the autopilot to ignore certain RC channels while in Manual mode, forcing those outputs to a fixed value.

## Parameter Breakdown

*   **`MANUAL_STR_EXPO`**: Steering exponential percentage.
*   **`MANUAL_OPTIONS`**: Bitmask for specific behaviors (e.g., handling throttle in manual).

## Developer Notes
*   **Library:** `Rover/mode_manual.cpp`.