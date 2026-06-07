---
default_value: 5
description: Filter frequency for flow data. Smoothes out noise from the optical flow sensor before it enters the position controller.
display_name: FlowHold Filter Frequency
group: FILT
investigation_status: complete
layout: parameter
name: FILT_HZ
range: 1 100
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PI_2D.cpp#L23
units: Hz
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# FlowHold Filter Frequency (FILT_HZ)

## Description
This parameter sets the cutoff frequency for the low-pass filter applied to Optical Flow sensor data when using **FlowHold** mode. Optical flow sensors (which measure the "movement" of the ground beneath the drone) can be noisy due to surface texture, lighting, or vibration.

A lower frequency makes the drone's position hold feel "softer" and more resistant to noise, but it adds latency (delay) to the control loop. A higher frequency makes the drone react more instantly to movement but can cause "jitter" if the sensor data is noisy.

## The Mathematics
The filter is a standard first-order Low Pass Filter (LPF). The relationship between the cutoff frequency ($f_c$) and the filter's time constant ($\tau$) is:

$$ \tau = \frac{1}{2 \pi f_c} $$

The smoothing coefficient ($\alpha$) used in each update step is:

$$ \alpha = \frac{dt}{dt + \tau} $$

Where $dt$ is the loop time (typically 0.0025s for a 400Hz control loop). At the default of **5Hz**, the time constant is approximately **0.031s**, providing significant smoothing for raw flow data.

## The Engineer's View
In `AC_PI_2D.cpp`, the parameter `_filt_hz` is used to calculate the filter coefficient.
1.  The code enforces a minimum frequency of `0.01Hz` to prevent division-by-zero errors.
2.  In the `update()` loop, the raw flow error is passed through this filter before the Proportional (P) and Integral (I) gains are applied.
3.  This ensures that high-frequency noise from the sensor does not "kick" the motors, which would cause audible chirping and wasted battery energy.

## Tuning & Behavior
*   **Default Value:** 5 Hz.
*   **Range:** 1 to 100 Hz.
*   **Effect of Increasing:** The vehicle will respond more aggressively to small drifts. Use this if the drone feels "lazy" in FlowHold but you have a very clean, high-quality sensor (e.g., HereFlow).
*   **Effect of Decreasing:** The vehicle will feel more stable but may drift further before correcting. Use this if you see the drone "shaking" or "twitching" in a hover.
*   **Dependencies:** Primarily used when `FLT_MODE` is set to **FlowHold**.
