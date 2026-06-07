---
layout: parameter
title: TUNE_PARAM
name: Transmitter tuning parameter or set of parameters
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/tuning.cpp#L17
---

# TUNE_PARAM: Transmitter tuning parameter or set of parameters

## Description
This sets which parameter or set of parameters will be tuned.

## Values
- **0:** None
- **1:** RLL_RATE_P
- **2:** RLL_RATE_I
- **3:** RLL_RATE_D
- **4:** PTCH_RATE_P
- **5:** PTCH_RATE_I
- **6:** PTCH_RATE_D
- **...**
- **101:** Roll P, I, and D simultaneously

## Description
This parameter works in conjunction with `TUNE_CHAN` (Channel 6) to allow real-time adjustment of control gains while flying.

- **Values < 50:** Select a single specific parameter (e.g., `RLL_RATE_P`).
- **Values > 100:** Select a "Set" of parameters (e.g., 101 adjusts all Roll PID terms together, scaling them up or down proportionally).
- **QuadPlane:** Parameters less than 50 generally apply to the QuadPlane vertical lift motors if `Q_ENABLE` is active.

