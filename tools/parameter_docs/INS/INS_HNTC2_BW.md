---
alias_target: INS_HNTCH_BW
default_value: 40
description: Harmonic Notch Filter bandwidth in Hz. This is typically set to half
  the base frequency. The ratio of base frequency to bandwidth determines the notch
  quality factor and is fixed across harmonics.
display_name: Harmonic Notch Filter bandwidth
group: INS
investigation_status: alias
layout: parameter
name: INS_HNTC2_BW
range: 5 250
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L74
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.h#L127
units: Hz
visual_asset_id: null
---

# Harmonic Notch Filter bandwidth

**Note:** This parameter functions identically to [INS_HNTCH_BW](../INS/INS_HNTCH_BW.html) for a secondary notch instance.
