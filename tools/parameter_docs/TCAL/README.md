# Temperature Calibration (TCAL)

## Overview
The **TCAL** parameter group configures the **Sensor Temperature Calibration** system. All MEMS sensors (Accelerometers, Gyroscopes, Barometers) suffer from "Thermal Drift"—their zero-point and scale changes as the board heats up.

TCAL uses mathematical models to compensate for this drift in real-time, ensuring a stable horizon and altitude reference from a cold startup through to high-power flight.

## Key Concepts

### 1. Calibration Models
The autopilot records sensor behavior across a range of temperatures (defined by `TCAL_TEMP_MIN` and `MAX`) and fits a polynomial curve to the data.
*   **`TCAL_BARO_EXP`**: The learned exponent for barometer temperature correction.

### 2. Auto-Learning
Modern ArduPilot can "learn" these coefficients automatically during the warm-up period while the drone is disarmed.

## Parameter Breakdown

*   **`TCAL_ENABLED`**: Master switch.
*   **`TCAL_OPTIONS`**: Bitmask for learning behaviors.
*   **`TCAL_TEMP_MIN / MAX`**: The valid temperature range for the calibration model.

## Integration Guide
*   **Recommendation:** Leave `TCAL_ENABLED = 1` for most modern hardware. If you see a drifting horizon after takeoff, perform a factory temperature calibration (requires a freezer and a heat source—see Wiki).

## Developer Notes
*   **Library:** `libraries/AP_TempCalibration`.