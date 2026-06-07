---
layout: parameter
name: DSHOT_RATE
display_name: Servo DShot output rate
description: DShot output rate for all outputs as a multiple of the loop rate.
default_value: 0
range: 0 4
units: 
group: DSHOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channels.cpp
---

# Servo DShot output rate (DSHOT_RATE)

## Description
Defines the communication frequency between the flight controller and DShot-capable ESCs. 

## Tuning & Behavior
*   **Default Value:** 0 (1Khz fixed for low loop rates)
*   **Values:** 1:loop-rate, 2:double loop-rate, 3:triple loop-rate, 4:quadruple loop rate
*   **Higher rates improve responsiveness but increase CPU load.**