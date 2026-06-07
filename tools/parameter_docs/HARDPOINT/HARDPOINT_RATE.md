---
layout: parameter
title: HARDPOINT_RATE
name: Hardpoint PWM rate
group: HARDPOINT
---

# HARDPOINT_RATE: Hardpoint PWM rate

## Description
This parameter sets the rate at which DroneCAN Hardpoint commands are broadcast when a PWM input is detected. This applies when the AP_Periph node is configured to read a PWM input (on a designated `PWM_HARDPOINT_PIN`) and forward it as a DroneCAN `uavcan.equipment.hardpoint.Command` message.

## Values
- **Range:** 10 to 100
- **Units:** Hz
- **Increment:** 1

## Description
If your AP_Periph device is wired to read a PWM signal (e.g., from an RC receiver) to trigger a Hardpoint, this parameter controls how frequently that trigger command is sent over the CAN bus while the PWM signal is active.

- **Higher Rate:** Updates the command status more frequently, potentially useful for rapid-response mechanisms, but consumes more CAN bus bandwidth.
- **Lower Rate:** Conserves bandwidth but increases latency for the command update.

## Source Code
[ardupilot/Tools/AP_Periph/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L392)

