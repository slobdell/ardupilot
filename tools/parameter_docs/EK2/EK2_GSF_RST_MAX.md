---
layout: parameter
name: EK2_GSF_RST_MAX
display_name: Maximum number of resets to the EKF-GSF yaw estimate allowed
description: Sets the maximum number of times the EKF2 will be allowed to reset its yaw to the GSF estimate.
default_value: 2
range: 1 10
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Maximum resets to the EKF-GSF yaw estimate allowed (EK2_GSF_RST_MAX)

## Description
Limits the number of times the EKF can "jump" its heading based on the GSF estimate to prevent repeated resets in difficult magnetic environments.