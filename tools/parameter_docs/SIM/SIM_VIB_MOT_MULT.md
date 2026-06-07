---
layout: parameter
name: SIM_VIB_MOT_MULT
display_name: Simulation Vibration Motor Scale
description: Amplitude scaling factor for motor-induced vibration noise in the simulation.
default_value: 1.0
range: 0 10
units: 
group: SIM
visual_asset_id: vibe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L507
---

# Simulation Vibration Motor Scale (SIM_VIB_MOT_MULT)

## Description
`SIM_VIB_MOT_MULT` controls the "Volume" of the simulated motor vibration.

While `SIM_VIB_FREQ` sets the frequency of the noise, this parameter determines how strong those vibrations are. This is used to test the resilience of the EKF and the effectiveness of internal dampening filters.

*   **1.0 (Default):** Standard vibration level.
*   **5.0:** Extreme vibration. Good for testing "Vibe Failsafe" logic.

## Tuning & Behavior
*   **Testing:** Set to **5.0** and watch the `VIBE` message in your Ground Control Station. You can verify if the drone can still maintain its position under high-stress vibration conditions.
