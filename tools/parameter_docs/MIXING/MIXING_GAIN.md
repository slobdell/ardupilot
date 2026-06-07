---
layout: parameter
title: MIXING_GAIN
name: Mixing Gain
group: MIXING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L621
---

# MIXING_GAIN: Mixing Gain

## Description
The gain for the V-tail and elevon output mixers.

## Values
- **Range:** 0.5 to 1.2
- **Default:** 0.5

## Description
This parameter adjusts the servo travel limits when using software mixing (e.g., Flying Wings with Elevons or V-Tail planes).

- **Default (0.5):** Ensures that even if you apply full Pitch AND full Roll simultaneously, the servos will not hit their mechanical limits (saturate). `0.5 * Pitch + 0.5 * Roll = 1.0 (Full Throw)`.
- **Higher Values (e.g. 1.0):** Gives more authority to individual inputs but risks "clipping" if you apply both inputs at once. Useful if your control surfaces aren't moving enough to control the plane.

## Source Code
[ardupilot/ArduPlane/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L621)

