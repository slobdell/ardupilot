---
layout: parameter
name: EK3_HGT_I_GATE
display_name: EKF3 Height Innovation Gate
description: The number of standard deviations allowed before a height measurement is rejected by the EKF.
default_value: 500
range: 100 1000
units: '%'
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Height Innovation Gate (EK3_HGT_I_GATE)

## Description
`EK3_HGT_I_GATE` is the "Bouncer" for your altitude data.

The EKF predicts where the drone should be based on its motors and accelerometers. When the barometer (or GPS) provides a new height reading, the EKF calculates the difference (the "Innovation"). If the reading is too different from the prediction (e.g., a massive sudden jump), the "Gate" rejects it to prevent the drone from rocketing up or down due to a sensor glitch.

## The Mathematics
The innovation $y$ and its covariance $S$ are used to calculate the normalized innovation squared (NIS):

$$ 	ext{NIS} = y^T S^{-1} y $$

The measurement is rejected if:

$$ 	ext{NIS} > \left( \frac{\text{EK3\_HGT\_I\_GATE}}{100} \right)^2 $$

A value of 500 means 5 standard deviations.

## Tuning & Behavior
*   **Default Value:** 500 (5 Sigma).
*   **Glitchy Baro:** If you see "EKF primary changed: 0" frequently when flying near ground effect or in wind, you might need to **Increase** this value to 700 or 800.
*   **Safety:** Setting this too high makes the EKF more vulnerable to slow sensor drift.