---
layout: parameter
name: FFT_ATT_REF
display_name: FFT attenuation for bandwidth calculation
description: Attenuation level in dB used to determine the width (bandwidth) of a noise peak.
default_value: 15
range: 0 100
units: dB
group: FFT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GyroFFT/AP_GyroFFT.cpp
---

# FFT attenuation for bandwidth calculation (FFT_ATT_REF)

## Description
Specifies the power drop (in dB) from the center frequency used to define the boundaries of a noise peak, determining its bandwidth.