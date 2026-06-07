---
layout: parameter
name: EK2_GSF_USE_MASK
display_name: Bitmask of which EKF-GSF yaw estimators are used
description: Bitmask of which EKF2 instances will use the output from the EKF-GSF yaw estimator.
default_value: 3
range: 
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Bitmask of which EKF-GSF yaw estimators are used (EK2_GSF_USE_MASK)

## Description
Determines which EKF cores are permitted to use the GSF yaw estimate for emergency recovery or as a primary source.