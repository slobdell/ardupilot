# Input Management (IM)

## Overview
The **IM** parameter group configures the **Input Mapping** and collective curves for **Traditional Helicopters**.

Helicopters require complex nonlinear mapping between the pilot's collective stick and the physical pitch of the main rotor blades. This group manages the "Feel" of the collective in different flight modes.

## Key Concepts

### 1. Collective Curves (`IM_STB_COL_x`)
In Stabilize and Acro modes, the collective stick doesn't command altitude; it commands blade pitch directly.
*   **4-Point Curve:** The curve is defined by four points corresponding to Stick positions (0%, 40%, 60%, 100%).
*   **`IM_STB_COL_1`**: Pitch at minimum stick.
*   **`IM_STB_COL_4`**: Pitch at maximum stick.

### 2. Acro Expo (`IM_ACRO_COL_EXP`)
Adds exponential "feel" to the collective stick in Acro mode, allowing for more precise hover control around the center stick.

## Parameter Breakdown

*   **`IM_STB_COL_1`..`4`**: Curve points (normalized 0-1000).
*   **`IM_ACRO_COL_EXP`**: Exponential factor.

## Integration Guide
*   **Tuning:** Adjust these curves to achieve a linear climb/descent feel that matches your motor power and blade efficiency.

## Developer Notes
*   **Library:** `libraries/AC_AttitudeControl/AC_AttitudeControl_Heli.cpp`.
*   **Context:** Only relevant for **Helicopters**.