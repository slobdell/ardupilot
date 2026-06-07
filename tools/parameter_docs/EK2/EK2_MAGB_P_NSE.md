---
layout: parameter
name: EK2_MAGB_P_NSE
display_name: Body magnetic field process noise
description: Controls growth of body magnetic field state error estimates (magnetometer bias).
default_value: 0.001
range: 0.00001 0.01
units: Gauss/s
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Body magnetic field process noise (EK2_MAGB_P_NSE)

## Description
Specifies how quickly the EKF adapts its estimate of the aircraft's internal magnetic interference (bias).