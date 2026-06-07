# PID Deadzone Configuration (PID)

## Overview
The **PID** parameter group (specifically `PID_DZ`) configures the **Controller Deadzone**.

## Key Concepts

### 1. Deadzone (`PID_DZ`)
In highly sensitive systems (like an indoor Blimp), the PID controllers might constantly "hunt" or jitter around the target even if the error is extremely small.
*   **`PID_DZ`**: Defines the minimum error threshold (e.g., in meters for position) below which the controller will output zero command.
*   **Purpose:** Saves battery and reduces motor wear by ignoring negligible errors.

## Developer Notes
*   **Vehicle:** Primarily used in **ArduBlimp**.