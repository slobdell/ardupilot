---
layout: parameter
name: XY_CTRL_MUL
display_name: System identification XY control multiplier
description: A multiplier for the XY velocity and position controller when using systemID in VTOL modes that do horizontal position and velocity control.
default_value: 0.1
range: 0.05 1.0
units: 
group: XY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/systemid.cpp#L72
---

# XY_CTRL_MUL: System identification XY control multiplier

## Description
A multiplier for the XY velocity and position controller when using systemID in VTOL modes that do horizontal position and velocity control.

## Values
- **Range:** 0.05 to 1.0
- **Default:** 0.1

## Description
This parameter scales down the position and velocity controller gains during a System Identification flight test on a QuadPlane.

- **Function:** When System ID is active in a position-controlled mode (like QLoiter), the normal PID gains might be too aggressive combined with the injected chirp signal. `XY_CTRL_MUL` reduces the effectiveness of the outer loops (Position/Velocity) to allow the inner loops (Attitude/Rate) to be excited cleanly without the drone fighting the test inputs too hard.
- **Usage:** Only relevant when `SID_AXIS` is set to a position or velocity axis.
- **Safety:** Prevents the drone from over-reacting to the test signal and flying away.

