---
layout: parameter
name: EK2_MAG_EF_LIM
display_name: EarthField error limit
description: Limits the difference between the learned earth magnetic field and the world magnetic model.
default_value: 50
range: 0 500
units: mGauss
group: EK2
visual_asset_id: 
investigation_status: complete
---

# EarthField error limit (EK2_MAG_EF_LIM)

## Description
Sanity check between the EKF's learned magnetic field and the mathematical World Magnetic Model (WMM).