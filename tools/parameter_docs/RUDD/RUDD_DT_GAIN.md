---
layout: parameter
title: RUDD_DT_GAIN
name: rudder differential thrust gain
group: RUDD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1090
---

# RUDD_DT_GAIN: rudder differential thrust gain

## Description
Gain control from rudder to differential thrust.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Increment:** 1
- **Default:** 10

## Description
This parameter is used on twin-engine aircraft to assist with ground steering and yaw control using **Differential Thrust**.

- **How it works:** When you move the rudder stick, the autopilot increases the RPM of one motor and decreases the other.
- **Usage:** Set this to a non-zero value if you have motors assigned to `ThrottleLeft` and `ThrottleRight`. 
- **Recommendation:** Start with **10%** and increase if the aircraft is sluggish to turn on the ground. Be careful with high values (>40%) as they can cause high-speed instability if one motor fails or responds differently.

