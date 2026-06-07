---
layout: parameter
name: PSC_JERK_D
display_name: Position Control Jerk (Down/Vertical)
description: This is a legacy/alias name for PSC_JERK_Z. Limits the rate of change of vertical acceleration.
default_value: 5.0
range: 5.0 50.0
units: m/s/s/s
group: PSC
visual_asset_id: psc_jerk_z_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L324
---

# Position Control Jerk (Down/Vertical) (PSC_JERK_D)

## Description
`PSC_JERK_D` is a common alias (often used in documentation and older Ground Control Stations) for the **PSC_JERK_Z** parameter. It controls the "smoothness" of vertical transitions (takeoff, landing, and climb/descent starts).

For full details on how this parameter affects flight dynamics and for tuning advice, please refer to the primary documentation page:

**[Click here for PSC_JERK_Z Documentation](../PSC_JERK_Z)**

## The Mathematics
Identical to `PSC_JERK_Z`. It defines the third derivative of vertical position:
$$ j_z = \frac{d^3z}{dt^3} $$

## The Engineer's View
In modern ArduPilot C++ source code, this maps to `_shaping_jerk_z` within the `AC_PosControl` class. While older parameter systems may have used the "D" (Down) suffix for the NEU (North East Up) coordinate frame's vertical axis, modern versions standardize on "Z".