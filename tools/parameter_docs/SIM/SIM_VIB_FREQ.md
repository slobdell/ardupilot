---
layout: parameter
name: SIM_VIB_FREQ
display_name: Simulation Vibration Frequency
description: The primary frequency (in Hz) of the simulated vibration noise added to the accelerometers.
default_value: 0
range: 0 300
units: Hz
group: SIM
visual_asset_id: vibe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L160
---

# Simulation Vibration Frequency (SIM_VIB_FREQ)

## Description
`SIM_VIB_FREQ` adds realistic motor noise to the IMU.

*   **0:** No vibration.
*   **50-200:** Typical motor/propeller frequencies.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Essential for testing **Harmonic Notch Filters**. Set `SIM_VIB_FREQ` to 80Hz, enable `INS_HNTCH_ENABLE`, and see if the FFT or Notch filters successfully remove it from the logs.