# Frequency Configuration (FREQ)

## Overview
The **FREQ** parameter group (often appearing as `FFT_MAXHZ` or `MOT_PWM_FREQ`) manages various frequency-domain settings across the autopilot.

## Key Concepts

### 1. Vibration Tracking (`FFT_...HZ`)
Used by the in-flight FFT engine to bracket the expected motor noise.
*   **`MAXHZ`**: The upper limit of the frequency sweep.

### 2. Motor PWM Frequency (`MOT_PWM_FREQ`)
(Often grouped here in documentation) Sets the update rate for the ESC signal.
*   **490Hz:** Standard for most PWM ESCs.
*   **16kHz - 24kHz:** Used for brushed motors or ultra-high-speed ESCs to reduce audible whine.

## Parameter Breakdown

*   **`FFT_MAXHZ`**: Upper bound for vibration analysis.
*   **`MOT_PWM_FREQ`**: Output update rate.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor` (for FFT) or `libraries/AP_Motors` (for PWM).