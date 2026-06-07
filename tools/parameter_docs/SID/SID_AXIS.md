---
layout: parameter
name: SID_AXIS
display_name: System identification axis
description: Controls which axis are being excited. Set to non-zero to see more parameters.
default_value: 0
range: 0 19
units: 
group: SID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_systemid.cpp#L15
---

# SID_AXIS: System identification axis

## Description
This parameter selects the specific control loop axis to be "excited" during a System Identification flight test.

## Values
- **0:** None (Disabled)
- **1:** Input Roll Angle
- **2:** Input Pitch Angle
- **3:** Input Yaw Angle
- **4:** Recovery Roll Angle
- **5:** Recovery Pitch Angle
- **6:** Recovery Yaw Angle
- **7:** Rate Roll
- **8:** Rate Pitch
- **9:** Rate Yaw
- **10:** Mixer Roll
- **11:** Mixer Pitch
- **12:** Mixer Yaw
- **13:** Mixer Thrust
- **14:** Measured Lateral Position
- **15:** Measured Longitudinal Position
- **16:** Measured Lateral Velocity
- **17:** Measured Longitudinal Velocity
- **18:** Input Lateral Velocity
- **19:** Input Longitudinal Velocity

## Description
**System ID Mode** is an advanced diagnostic tool used to measure the actual physical response of the aircraft to control inputs. 

- **How it works:** When you switch into System ID mode, the autopilot injects a "chirp" (a sine wave of increasing frequency) into the control loop selected by `SID_AXIS`. 
- **Purpose:** By logging the input chirp and the resulting motion, engineers can calculate the precise "Transfer Function" of the aircraft, which is used to create a perfect PID tune or a digital twin model.
- **Safety:** Always start with small magnitudes (`SID_MAGNITUDE`) and rates (`SID_AXIS = 7, 8, or 9`) before trying angle or position loops.

