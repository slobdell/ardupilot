---
layout: parameter
name: SIM_RC_FAIL
display_name: Simulated RC Failure
description: Enables simulation of an RC receiver signal failure.
default_value: 0
range: 0 2
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated RC Failure (SIM_RC_FAIL)

## Description
`SIM_RC_FAIL` simulates your radio receiver losing power or signal.

*   **0: Normal.** RC signal is healthy.
*   **1: No Pulses.** The simulator stops sending any RC data to the autopilot. Mimics a disconnected SBus cable.
*   **2: Failsafe Values.** Channels stay at neutral, except throttle which drops to 950µs.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use this in flight to verify that your `FS_THR_ENABLE` or `RC_FS_ACTION` is working correctly.