# Custom Controller (CC)

## Overview
The **CC** parameter group configures the **Custom Controller** library. This feature provides a sandbox for developers and researchers to implement custom attitude control algorithms (e.g., INDI, L1 adaptive, or novel PID variants) without replacing the core `AC_AttitudeControl` library.

The custom controller runs in parallel with the standard controller, and its output is mixed or swapped in based on the configuration.

## Key Concepts

### 1. Axis Masking (`CC_AXIS_MASK`)
You don't have to replace the entire controller. You can take over just one axis.
*   **Bit 0:** Roll.
*   **Bit 1:** Pitch.
*   **Bit 2:** Yaw.
*   **Example:** Set to 4 to use the custom controller for Yaw only, while keeping standard PID for Roll/Pitch.

### 2. Backend Selection (`CC_TYPE`)
Selects which custom backend logic to execute.
*   **0:** Disabled.
*   **1:** Empty (Pass-through/Template).
*   **2:** PID (Example implementation).
*   **3:** INDI (Incremental Nonlinear Dynamic Inversion).

### 3. Generic Parameters (`CC_PARAMx`)
To avoid hardcoding gains, the library exposes generic floating-point parameters (`CC_PARAM1`...`CC_PARAM3`) that are readable by the custom backend code.

## Parameter Breakdown

*   **`CC_TYPE`**: Active backend.
*   **`CC_AXIS_MASK`**: Active axes.
*   **`CC_PARAM1`**: User-defined tuning variable 1.

## Integration Guide
*   **For Users:** Unless you are running a specific firmware build that documents what `CC_PARAM1` does, leave this disabled (`CC_TYPE = 0`).
*   **For Developers:** Use `libraries/AC_CustomControl` as a template. The `update()` method is called at the main loop rate (400Hz+).

## Developer Notes
*   **Library:** `libraries/AC_CustomControl`
*   **Safety:** If your custom controller outputs `NaN` or crashes, the vehicle will likely crash. Test in SITL first.