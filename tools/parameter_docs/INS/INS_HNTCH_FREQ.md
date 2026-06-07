---
layout: parameter
name: INS_HNTCH_FREQ
display_name: Harmonic Notch Center Frequency
description: The center frequency (in Hz) that the notch filter will target for attenuation.
default_value: 80
range: 10 500
units: Hz
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Harmonic Notch Center Frequency (INS_HNTCH_FREQ)

## Description
`INS_HNTCH_FREQ` defines the primary frequency of the noise you want to remove. 

For most drones, this corresponds to the rotation speed of the motors (in rotations per second) during a steady hover. By targeting this specific frequency, the filter removes the vibration caused by the spinning props before it reaches the flight controller.

## The Mathematics
$$ \text{Frequency (Hz)} = \frac{\text{RPM}}{60} $$

If your motors hover at 6000 RPM:
$$ \text{INS\_HNTCH\_FREQ} = \frac{6000}{60} = 100 \text{ Hz} $$

If you use Dynamic Harmonic Notch (e.g. Throttle or ESC based), this parameter acts as the **minimum lower bound** or the reference frequency for the configuration.

## The Engineer's View
This parameter sets the $f_c$ (center cutoff) for the digital filter. 
In "Static Mode" (`INS_HNTCH_MODE` = 0), the filter stays fixed at this frequency.
In "Dynamic Mode", the filter moves. However, `INS_HNTCH_FREQ` is still used to calculate the initial Quality Factor ($Q$) in conjunction with `INS_HNTCH_BW`.

## Tuning & Behavior
*   **Default Value:** 80 Hz.
*   **How to find it:
    1.  Set `INS_LOG_BAT_MASK` = 1 (IMU Pre-Filter).
    2.  Do a hover flight.
    3.  Download the DataFlash log.
    4.  Run an FFT (Fast Fourier Transform) on the `GYRO[0].GyrX` data.
    5.  Look for the biggest spike in the graph. That X-axis value is your Frequency.