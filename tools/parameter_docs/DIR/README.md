# Wind Direction Sensor (DIR)

## Overview
The **DIR** parameter group contains legacy or driver-specific settings for **Analog Wind Vanes**.

**Note:** In modern ArduPilot versions, these are often aliased to or superseded by the **WNDVN** (Wind Vane) parameter group. However, the `DIR_` prefix persists for specific analog direction drivers (like the Modern Devices Wind Sensor).

## Key Concepts

### 1. Analog Direction Sensing
Many simple wind vanes output a voltage (0-3.3V or 0-5V) proportional to the wind angle (0-360 degrees).
*   **`DIR_PIN`**: The ADC pin reading this voltage.
*   **`DIR_V_MIN` / `DIR_V_MAX`**: The voltage range corresponding to 0-360 degrees.

### 2. Offset (`DIR_OFS`)
Mechanical installation error correction. If the vane points North but the autopilot thinks it points East, use this offset to correct it.

## Parameter Breakdown

*   **`DIR_PIN`**: ADC input pin.
*   **`DIR_FILT`**: Filter frequency (Hz) to smooth the noisy analog signal.
*   **`DIR_DZ`**: Deadzone (degrees) around North crossover (0/360 transition).

## Integration Guide
*   **See:** [WNDVN](../WNDVN/README.md) for main Wind Vane configuration. Use `DIR_` parameters only if your selected `WNDVN_TYPE` requires them.

## Developer Notes
*   **Library:** `libraries/AP_WindVane`