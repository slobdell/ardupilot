---
alias_target: INS_HNTCH_ATT
default_value: 40
description: Harmonic Notch Filter attenuation in dB. Values greater than 40dB will
  typically produce a hard notch rather than a modest attenuation of motor noise.
display_name: Harmonic Notch Filter attenuation
group: INS
investigation_status: alias
layout: parameter
name: INS_HNTC2_ATT
range: 5 50
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L82
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.h#L130
units: dB
visual_asset_id: null
---

# Harmonic Notch Filter attenuation

**Note:** This parameter functions identically to [INS_HNTCH_ATT](../INS/INS_HNTCH_ATT.html) for a secondary notch instance.
