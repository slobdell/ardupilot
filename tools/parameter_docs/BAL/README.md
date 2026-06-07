# Balance Bot Configuration (BAL)

## Overview
The **BAL** parameter group contains specific tuning parameters for **Balance Bots** (two-wheeled self-balancing robots) running **ArduRover**.

Unlike standard Rovers, a Balance Bot uses a pitch controller to stay upright. This controller drives the wheels forward/backward to correct pitch errors.

## Key Concepts

### 1. Pitch Control
The robot must constantly adjust its wheel speed to maintain a target pitch angle (usually 0, or leaned forward for acceleration).
*   **`BAL_PITCH_MAX`**: Limits how far the robot is allowed to lean. If it leans past this, it may fall over or be unable to recover.
*   **`BAL_PIT_FF`**: Pitch FeedForward. This is critical. It provides the immediate throttle response needed to counter gravity when the robot starts falling.

## Parameter Breakdown

*   **`BAL_PITCH_MAX`**: Maximum pitch angle (deg).
*   **`BAL_PITCH_TRIM`**: Pitch angle offset for "Level" (balance point).
*   **`BAL_PIT_FF`**: Feed-forward gain.

## Integration Guide

### Tuning a Balance Bot
1.  **Level:** Calibrate the accelerometer with the robot perfectly balanced.
2.  **Trim:** Use `BAL_PITCH_TRIM` to find the exact balance point where the motors are quiet.
3.  **PID:** Tune the `ATC_` or `PSC_` pitch controllers (depending on firmware version) alongside `BAL_PIT_FF`.