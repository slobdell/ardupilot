---
layout: parameter
name: SIM_ACC1_RND
display_name: Simulated Accelerometer 1 Noise
description: The amount of Gaussian noise (in m/s^2) added to the first simulated accelerometer.
default_value: 0
range: 0 10.0
units: m/s^2
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L160
---

# Simulated Accelerometer 1 Noise (SIM_ACC1_RND)

## Description
`SIM_ACC1_RND` allows you to test the robustness of the autopilot's navigation filters (EKF) by injecting artificial noise into the first simulated accelerometer.

In a real drone, motors and propellers create significant vibration. By increasing this parameter in SITL, you can see how much "shaking" your drone can tolerate before it loses its position estimate or becomes unstable.

## The Engineer's View
Defined in `SITL.cpp`.
The simulation physics engine calculates the "True" acceleration of the vehicle. This parameter sets the standard deviation ($\sigma$) of a Gaussian distribution that is added to each sample:
$$ Accel_{read} = Accel_{true} + \mathcal{N}(0, \text{SIM\_ACC1\_RND}) $$

## Tuning & Behavior
*   **Default Value:** 0 (Perfect, noise-free sensor).
*   **Recommendation:** Set to **0.5 or 1.0** to simulate a typical frame with some vibration. Set to **5.0+** to simulate a "Worst-case" high-vibration scenario.