---
layout: parameter
name: BRD_RADIO_BZOFS
display_name: Internal Radio Buzzer Offset
description: Adjusts the frequency (pitch) of the transmitter's buzzer.
default_value: 25
range: 0 40
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L122
---

# Internal Radio Buzzer Offset (BRD_RADIO_BZOFS)

## Description
`BRD_RADIO_BZOFS` allows for a fine-tuning adjustment of the pitch of the buzzer inside the handheld transmitter (when using integrated SPI radios like SkyViper). 

Due to manufacturing tolerances in the tiny piezo buzzers used in these controllers, some might sound higher or lower than intended. This parameter allows the user to shift the frequency up or down so that the status beeps and melodies sound correct.

## Tuning & Behavior
*   **Default:** 25.
*   **Adjustment:** Change this value if your transmitter's beeps sound "flat" or "off-key." Higher values increase the frequency (higher pitch).