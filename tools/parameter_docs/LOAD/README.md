# Motor Load Testing (LOAD)

## Overview
The **LOAD** parameter group is specific to the **Toy Mode** motor verification routines. It is used primarily in factory environments to perform automated burn-in or stress testing of the motors and ESCs.

## Key Concepts

### 1. Test Patterns
The autopilot can execute pre-defined throttle sequences to exercise the motors.
*   **`LOAD_TYPE`**: Selects between constant thrust, sequential motor blips, or synchronized pulses.

## Parameter Breakdown

*   **`LOAD_TYPE`**: Pattern selection.
*   **`LOAD_MUL`**: Multiplier to scale the intensity of the test.

## Developer Notes
*   **Library:** `ArduCopter/toy_mode.cpp`.
*   **Caution:** These parameters are not intended for use in normal flight and can cause the drone to behave unexpectedly if activated.