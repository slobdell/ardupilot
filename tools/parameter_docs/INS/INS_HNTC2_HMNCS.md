---
alias_target: INS_HNTCH_HMNCS
default_value: 3
description: Bitmask of harmonic frequencies to apply Harmonic Notch Filter to. This
  option takes effect on the next reboot. A value of 0 disables this filter. The first
  harmonic refers to the base frequency.
display_name: Harmonic Notch Filter harmonics
group: INS
investigation_status: alias
layout: parameter
name: INS_HNTC2_HMNCS
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L105
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.h#L74
units: null
visual_asset_id: null
---

# Harmonic Notch Filter harmonics

**Note:** This parameter functions identically to [INS_HNTCH_HMNCS](../INS/INS_HNTCH_HMNCS.html) for a secondary notch instance.
