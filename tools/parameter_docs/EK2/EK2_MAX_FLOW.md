---
layout: parameter
name: EK2_MAX_FLOW
display_name: Maximum valid optical flow rate
description: Magnitude maximum optical flow rate in rad/sec that will be accepted.
default_value: 2.5
range: 1.0 4.0
units: rad/s
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Maximum valid optical flow rate (EK2_MAX_FLOW)

## Description
Upper bound for valid optical flow readings. Readings above this rate are ignored as being potentially corrupted by motion blur or sensor limits.