---
layout: parameter
name: INS_HNTCH_BW
display_name: Harmonic Notch Bandwidth
description: The bandwidth (in Hz) of the harmonic notch filter, defining the width of the frequency attenuation.
default_value: 40
range: 5 250
units: Hz
group: INS
visual_asset_id: notch_filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Harmonic Notch Bandwidth (INS_HNTCH_BW)

## Description
`INS_HNTCH_BW` sets the "width" of the frequency gap that the notch filter removes. 

Imagine the Notch Filter as a "V" shape cut out of the vibration graph. 
*   **The Bottom of the V** is the Center Frequency (`INS_HNTCH_FREQ`).
*   **The Width of the V** is controlled by this Bandwidth parameter.

A wider bandwidth catches more noise (especially if your motors are changing speed rapidly), but it also introduces more **Latency (Delay)** into the flight controller. Too much delay will make the drone wobble or oscillate.

## The Mathematics
The quality factor ($Q$) of the filter is derived from the ratio of the center frequency ($f_c$) to the bandwidth ($BW$):

$$ Q = \frac{f_c}{BW} $$

A lower bandwidth results in a higher $Q$ (sharper notch, less delay).
A higher bandwidth results in a lower $Q$ (wider notch, more delay).

For dynamic harmonic notch filters, the bandwidth scales with the frequency to maintain a constant $Q$. This means if your motor frequency doubles, the notch becomes twice as wide to catch the noise.

## The Engineer's View
Defined in `AP_InertialSensor`. 
This parameter sets the -3dB cutoff points relative to the center frequency.
If `INS_HNTCH_BW` is set to 40Hz and `INS_HNTCH_FREQ` is 80Hz:
*   The filter will aggressively attenuate noise between approximately 60Hz and 100Hz.
*   The phase lag introduced by the filter is directly proportional to the depth and width of the notch.

## Tuning & Behavior
*   **Default Value:** 40 Hz.
*   **Golden Rule:** Set this to **half of your Center Frequency**.
    *   If `INS_HNTCH_FREQ` = 80Hz, set `INS_HNTCH_BW` = 40Hz.
    *   If `INS_HNTCH_FREQ` = 200Hz (small racing quad), set `INS_HNTCH_BW` = 100Hz.
*   **Warning:** Setting `INS_HNTCH_BW` larger than `INS_HNTCH_FREQ` is invalid and can cause filter instability.