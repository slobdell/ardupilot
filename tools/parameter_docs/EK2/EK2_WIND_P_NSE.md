---
layout: parameter
name: EK2_WIND_P_NSE
display_name: Wind velocity process noise
description: Controls the growth of wind state error estimates.
default_value: 0.1
range: 0.01 1.0
units: m/s/s
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Wind velocity process noise (EK2_WIND_P_NSE)

## Description
Controls how quickly the EKF adapts to changing wind conditions.