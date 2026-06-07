---
layout: parameter
name: SID_MAGNITUDE
display_name: System identification Chirp Magnitude
description: Magnitude of sweep in deg, deg/s and 0-1 for mixer outputs.
default_value: 15
range: 1 50
units: 
group: SID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_systemid.cpp#L21
---

# SID_MAGNITUDE: System identification Chirp Magnitude

## Description
This parameter sets the "Strength" of the excitation signal (the chirp).

## Values
- **Units:** Degrees (for angle/rate loops) or 0.0-1.0 (for mixer loops).
- **Default:** 15

## Description
`SID_MAGNITUDE` determines how much the drone will oscillate during the System ID test.

- **Effect:** A larger magnitude provides a cleaner data signal (higher signal-to-noise ratio), which is better for analysis. However, a magnitude that is too large can cause the drone to hit its mechanical limits or become unstable.
- **Tuning Tip:** Start with a low value (e.g., **5**) to ensure the drone is safe, then gradually increase until the motion is clearly visible but the drone remains well within its flight envelope.

