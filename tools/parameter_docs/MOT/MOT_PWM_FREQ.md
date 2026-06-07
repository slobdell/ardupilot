---
layout: parameter
name: MOT_PWM_FREQ
display_name: Motor PWM Frequency (Brushed)
description: Sets the PWM frequency for brushed motor outputs.
default_value: 16
range: 1 20
units: kHz
group: MOT
visual_asset_id: mot_pwm_freq_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_Motors/AP_MotorsUGV.cpp#L46
---

# Motor PWM Frequency (MOT_PWM_FREQ)

## Description
`MOT_PWM_FREQ` defines the switching frequency of the H-Bridge or ESC when controlling **Brushed** motors. 

Brushed motors (common in smaller Rovers and Boats) require a high-frequency PWM signal to operate efficiently and quietly. If the frequency is too low, the motors will "sing" or "whine" audibly. If too high, the ESC may overheat due to switching losses.

*   **Default:** 16 kHz.
*   **Recommended:** **16 kHz** to **20 kHz** for silent operation.

## Tuning & Behavior
*   **Default:** 16.
*   **Note:** This parameter is only used if the vehicle is configured for Brushed motors. Standard brushless ESCs (using PWM/DShot) ignore this parameter.