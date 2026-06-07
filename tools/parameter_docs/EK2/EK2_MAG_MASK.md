---
layout: parameter
name: EK2_MAG_MASK
display_name: Bitmask of cores using heading fusion
description: Bitmap of EKF cores that will disable 3-axis fusion and use simple heading fusion at all times.
default_value: 0
range: 
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Bitmask of cores using heading fusion (EK2_MAG_MASK)

## Description
Allows specific EKF cores to be forced into a simpler (and sometimes more robust) magnetic heading fusion mode.