---
layout: parameter
name: EK2_RNG_USE_SPD
display_name: Range finder max ground speed
description: The range finder will not be used as the primary height source when the horizontal ground speed is greater than this value.
default_value: 2.0
range: 2.0 6.0
units: m/s
group: EK2
visual_asset_id: 
investigation_status: complete
---

# Range finder max ground speed (EK2_RNG_USE_SPD)

## Description
Safety limit that disables rangefinder-based altitude estimation at high speeds, where tilt and terrain variations can introduce significant errors.