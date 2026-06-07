# In-Flight FFT Configuration (FFT)

## Overview
The **FFT** parameter group configures the **In-Flight Fast Fourier Transform** analysis engine. This is an advanced feature that allows the autopilot to listen to the vibration of the motors in real-time to identify precise noise frequencies.

This data is used to drive the **Harmonic Notch Filter** (`INS_HNTCH_`), which dynamically "tunes" its suppression center to match the motor RPM, effectively erasing vibration before it can destabilize the PID controllers.

## Key Concepts

### 1. Dynamic Noise Tracking
Unlike a static low-pass filter (which creates delay), the FFT engine tracks the peak noise frequency as the pilot changes throttle. This allows for very high-performance tunes even on noisy airframes.

### 2. Frequency Range (`FFT_MINHZ` / `FFT_MAXHZ`)
Tells the engine where to look for noise.
*   **Default:** Usually 80-600Hz.
*   **Large Drones:** Look lower (40-150Hz).
*   **Racer Drones:** Look higher (150-1000Hz).

### 3. Sampling Mode (`FFT_SAMPLE_MODE`)
Controls how the data is pulled from the IMUs.
*   **0:** Process all IMU data (CPU intensive).
*   **1:** Process a subset of data (recommended for F4/F7).

## Parameter Breakdown

*   **`FFT_ENABLE`**: Master switch.
*   **`FFT_WINDOW_SIZE`**: Analysis buffer size (larger = more accurate but more delay).
*   **`FFT_NUM_FRAMES`**: How many windows to average (reduces jitter).
*   **`FFT_SNR_REF`**: Signal-to-Noise ratio threshold to consider a peak valid.

## Integration Guide

### Setting up Dynamic Filtering
1.  **Requirement:** A fast processor (F7 or H7) is highly recommended.
2.  **Enable:** Set `FFT_ENABLE = 1`.
3.  **Monitor:** Perform a test flight. Check the `FTN1` and `FTN2` log messages.
4.  **Filter:** Once the FFT is tracking motor noise accurately, set `INS_HNTCH_MODE = 4` (FFT) to use this data for the notch filter.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor/AP_InertialSensor_HarmonicNotch.cpp`.
*   **Backend:** Uses the KISS FFT library or CMSIS-DSP on ARM processors.