---
layout: parameter
name: BRD_PWM_VOLT_SEL
display_name: Set PWM Out Voltage
description: Sets the voltage max for PWM output pulses. 0 for 3.3V and 1 for 5V output.
default_value: 0
range: 0 1
units: V
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Set PWM Out Voltage (BRD_PWM_VOLT_SEL)

## Description
Selects the logic voltage level (3.3V or 5V) for the PWM output pins. Using 5V can improve signal integrity and reduce the impact of electrical noise on long servo wires.