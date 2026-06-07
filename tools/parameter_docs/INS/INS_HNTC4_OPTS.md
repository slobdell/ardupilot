---
alias_target: INS_HNTCH_OPTS
default_value: 0
description: Harmonic Notch Filter options. Triple and double-notches can provide
  deeper attenuation across a wider bandwidth with reduced latency than single notches
  and are suitable for larger aircraft. Multi-Source attaches a harmonic notch to
  each detected noise frequency instead of simply being multiples of the base frequency,
  in the case of FFT it will attach notches to each of three detected noise peaks,
  in the case of ESC it will attach notches to each of four motor RPM values. Loop
  rate update changes the notch center frequency at the scheduler loop rate rather
  than at the default of 200Hz. If both double and triple notches are specified only
  double notches will take effect.
display_name: Harmonic Notch Filter options
group: INS
investigation_status: alias
layout: parameter
name: INS_HNTC4_OPTS
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L129
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.h#L146
units: null
visual_asset_id: null
---

# Harmonic Notch Filter options

**Note:** This parameter functions identically to [INS_HNTCH_OPTS](../INS/INS_HNTCH_OPTS.html).
