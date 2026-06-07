---
layout: parameter
name: EK2_MAGE_P_NSE
display_name: Earth magnetic field process noise
description: Controls growth of earth magnetic field state error estimates.
default_value: 0.001
range: 0.00001 0.01
units: Gauss/s
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Earth magnetic field process noise (EK2_MAGE_P_NSE)

## Description
Specifies how quickly the EKF adapts its estimate of the local Earth magnetic field.