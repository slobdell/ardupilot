---
alias_target: INS_HNTCH_REF
default_value: 0
description: A reference value of zero disables dynamic updates on the Harmonic Notch
  Filter and a positive value enables dynamic updates on the Harmonic Notch Filter.  For
  throttle-based scaling, this parameter is the reference value associated with the
  specified frequency to facilitate frequency scaling of the Harmonic Notch Filter.
  For RPM and ESC telemetry based tracking, this parameter is set to 1 to enable the
  Harmonic Notch Filter using the RPM sensor or ESC telemetry set to measure rotor
  speed.  The sensor data is converted to Hz automatically for use in the Harmonic
  Notch Filter.  This reference value may also be used to scale the sensor data, if
  required.  For example, rpm sensor data is required to measure heli motor RPM. Therefore
  the reference value can be used to scale the RPM sensor to the rotor RPM.
display_name: Harmonic Notch Filter reference value
group: INS
investigation_status: alias
layout: parameter
name: INS_HNTC3_REF
range: 0.0 1.0
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L113
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.h#L142
units: null
visual_asset_id: null
---

# Harmonic Notch Filter reference value

**Note:** This parameter functions identically to [INS_HNTCH_REF](../INS/INS_HNTCH_REF.html) for a secondary notch instance.
