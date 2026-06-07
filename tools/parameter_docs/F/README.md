# Frequency Analysis (F)

## Overview
The **F** parameter group (specifically `F_START_HZ` and `F_STOP_HZ`) configures the frequency range for the **In-Flight Fast Fourier Transform (FFT)** analysis engine.

The FFT engine scans the raw accelerometer data to find the loudest noise spikes (primarily caused by motor and propeller vibration). It then uses this data to automatically tune "Notch Filters" to erase that noise before it hits the PID controllers.

## Key Concepts

### 1. Analysis Window
*   **`F_START_HZ`**: The lowest frequency to look for noise (e.g., 80Hz).
*   **`F_STOP_HZ`**: The highest frequency to look for noise (e.g., 600Hz).
*   **Why Limit?** Excluding very low frequencies prevents the FFT from accidentally "erasing" the pilot's actual control inputs or the airframe's natural resonant handling.

## Parameter Breakdown

*   **`F_START_HZ`**: Minimum analysis frequency.
*   **`F_STOP_HZ`**: Maximum analysis frequency.

## Integration Guide
*   **Tuning:** Set these to bracket the expected RPM range of your motors. A 5-inch racer might use 100-800Hz. A large 15-inch lifter might use 40-200Hz.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor/AP_InertialSensor_HarmonicNotch.cpp`
*   **Relationship:** These are often aliased as `FFT_MINHZ` and `FFT_MAXHZ` in newer firmware versions.