---
layout: parameter
name: SCHED_LOOP_RATE
display_name: Scheduling main loop rate
description: Controls the update frequency (in Hz) of the main autopilot control loop.
default_value: 400
range: 50 400
units: Hz
group: SCHED
visual_asset_id: sched_loop_rate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scheduler/AP_Scheduler.cpp#L61
---

# Scheduling main loop rate (SCHED_LOOP_RATE)

## Description
`SCHED_LOOP_RATE` defines the "Heartbeat" speed of the flight controller. It determines how many times per second the autopilot reads the sensors, runs the PID math, and updates the motor outputs.

*   **400Hz (Default for Copter):** The drone updates its state every 2.5 milliseconds. This is required for stable, responsive multicopter flight.
*   **50Hz (Default for Plane/Rover):** The vehicle updates its state every 20 milliseconds. Sufficient for slower-moving vehicles like cars or fixed-wing aircraft.

## The Engineer's View
Defined in `AP_Scheduler.cpp`.
This parameter sets the base tick interval for the `AP_Scheduler` system. All other tasks (GPS reading, Battery monitoring, Logging) are scheduled as multiples of this rate. 

**Warning:** Increasing this above 400Hz is considered experimental. It significantly increases CPU load and may cause "Scheduler Slips," where the drone becomes unstable because it cannot finish the math in time for the next loop.

## Tuning & Behavior
*   **Default Value:** 400 (Copter), 50 (Plane/Rover).
*   **Recommendation:** Leave at **400** for all modern multicopters. Only reduce it if you are using extremely old hardware (like a Pixhawk 1) and experiencing high `LOAD` values (>80%).
*   **Reboot Required:** Yes. This changes the fundamental timing of the processor.