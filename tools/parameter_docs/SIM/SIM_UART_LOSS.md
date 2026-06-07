---
layout: parameter
name: SIM_UART_LOSS
display_name: Simulated UART Data Loss
description: The percentage of serial data packets to randomly drop in the simulator.
default_value: 0
range: 0 100
units: '%'
group: SIM
visual_asset_id: sim_lag_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated UART Data Loss (SIM_UART_LOSS)

## Description
`SIM_UART_LOSS` simulates a "Bad Connection" or noisy telemetry link.

It randomly drops the specified percentage of serial bytes. This is perfect for testing how well your GCS handles packet loss or how resilient your Serial GPS driver is to data corruption.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **5% or 10%** and observe if your MAVLink connection remains stable.