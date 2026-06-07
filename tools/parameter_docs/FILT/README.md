# Sensor Filtering (FILT)

## Overview
The **FILT** parameter group configures frequency-domain filters used to clean raw sensor data (IMU, Baro, Airspeed) before it is used by the control loops.

All digital sensors contain noise. Filtering removes high-frequency vibrations and "jitter," but introduces a small amount of "phase lag" (delay). Finding the right balance is the key to a stable vehicle.

## Key Concepts

### 1. Low-Pass Filters (`FILT_HZ`)
A low-pass filter allows slow movements (pilot commands) to pass while blocking fast movements (motor vibrations).
*   **`FILT_HZ`**: The cutoff frequency.
    *   **Higher Hz:** Less delay, but more noise.
    *   **Lower Hz:** Cleaner signal, but the vehicle might feel "mushy" or oscillate due to the delay in control response.

### 2. Notch Filters (`FILT1_NOTCH_...`)
A notch filter targets a **specific** narrow frequency range (e.g., exactly 120Hz) to erase a known vibration without affecting other frequencies.

## Parameter Breakdown

*   **`FILT_HZ`**: General filter cutoff frequency.
*   **`FILT1_NOTCH_FREQ`**: Center frequency of the notch.
*   **`FILT1_NOTCH_Q`**: Sharpness (width) of the notch.

## Integration Guide
*   **Default:** Start with default values.
*   **Vibrations:** If your drone has high vibrations (check logs), you may need to lower the `FILT_HZ` for the D-term or enable a Harmonic Notch.

## Developer Notes
*   **Library:** `libraries/AP_Filter`.
*   **Context:** These are often used as low-level helpers within `AP_InertialSensor` and `AC_AttitudeControl`.