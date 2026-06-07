---
layout: parameter
name: EK2_GSF_RUN_MASK
display_name: Bitmask of which EKF-GSF yaw estimators run
description: Bitmask of which EKF2 instances run an independent EKF-GSF yaw estimator.
default_value: 3
range: 
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Bitmask of which EKF-GSF yaw estimators run (EK2_GSF_RUN_MASK)

## Description
Enables the Gaussian Sum Filter (GSF) yaw estimator for specific EKF cores. GSF provides a yaw estimate that doesn't rely on the magnetometer.