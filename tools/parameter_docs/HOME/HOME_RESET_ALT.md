---
layout: parameter
title: HOME_RESET_ALT
name: Home reset altitude threshold
group: HOME
---

# HOME_RESET_ALT: Home reset altitude threshold

## Description
When the aircraft is within this altitude of the home waypoint while disarmed, it will automatically update the home position. Set to 0 to continuously reset it.

## Values
- **Range:** -1 to 127
- **Units:** m
- **Default:** 0

## Description
This parameter controls whether and when the autopilot updates its "Home" position while the aircraft is on the ground (disarmed).

- **0 (Default):** Continuously update Home to the current GPS position while disarmed. The altitude is also continuously re-zeroed.
- **-1:** Never automatically update Home. Home is set once when GPS lock is first acquired.
- **> 0:** Update Home only if the aircraft's altitude is within this many meters of the initial startup altitude. If you move the aircraft significantly up or down (e.g., carrying it up a hill), home updating stops to prevent the barometer from being re-zeroed at the new height.

## Source Code
[ardupilot/ArduPlane/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1106)

