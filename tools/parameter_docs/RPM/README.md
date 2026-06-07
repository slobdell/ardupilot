# RPM Sensor Configuration (RPM)

## Overview
The **RPM** parameter group configures the **Rotations Per Minute** (RPM) sensors. This system monitors the speed of motors or engines.

RPM data is critical for:
1.  **Heli Governor:** Maintaining main rotor speed.
2.  **Harmonic Notch Filter:** Tracking motor vibration frequency.
3.  **Engine Health:** Monitoring ICE (Gas) engine state.

## Key Concepts

### 1. Sensor Types (`RPMn_TYPE`)
*   **1 (PWM Pin):** Connects to a Hall Effect sensor or Optical tachometer that sends a pulse for every rotation.
*   **2 (ESC Telemetry):** Pulls RPM data from a BLHeli_32 or DShot ESC.
*   **4 (DroneCAN):** For CAN-based RPM sensors.

### 2. Scaling (`RPMn_SCALING`)
Converts pulses per second into actual RPM.
*   **For Hall Effect:** Set to the number of magnets on the shaft.
*   **For BLHeli ESC:** Set to the number of motor poles divided by 2.

## Parameter Breakdown

*   **`RPM1_PIN`**: The GPIO pin assigned to the sensor.
*   **`RPM1_MAX`**: Maximum expected RPM (sanity check).

## Integration Guide
1.  **ESC Setup:** If using DShot telemetry, set `RPM1_TYPE = 2` and ensure `SERVO_BLH_BDMASK` includes the motor you want to track.
2.  **Verification:** Check the `RPM1` value in the GCS Status tab while the motor is spinning.

## Developer Notes
*   **Library:** `libraries/AP_RPM`.
*   **Usage:** Often fed into `AP_ICEngine` or `AP_InertialSensor_HarmonicNotch`.