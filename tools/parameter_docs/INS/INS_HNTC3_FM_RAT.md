---
alias_target: INS_HNTCH_FM_RAT
default_value: 1.0
description: The minimum ratio below the configured frequency to take throttle based
  notch filters when flying at a throttle level below the reference throttle. Note
  that lower frequency notch filters will have more phase lag. If you want throttle
  based notch filtering to be effective at a throttle up to 30% below the configured
  notch frequency then set this parameter to 0.7. The default of 1.0 means the notch
  will not go below the frequency in the FREQ parameter.
display_name: Throttle notch min freqency ratio
group: INS
investigation_status: alias
layout: parameter
name: INS_HNTC3_FM_RAT
range: 0.1 1.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L136
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.h#L153
units: null
visual_asset_id: null
---

# Throttle notch min freqency ratio

**Note:** This parameter functions identically to [INS_HNTCH_FM_RAT](../INS/INS_HNTCH_FM_RAT.html) for a secondary notch instance.
