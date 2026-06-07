---
layout: parameter
name: EK3_SRC_OPTIONS
display_name: EKF Source Options
description: Bitmask for configuring how multiple sensor sources are fused.
default_value: 1
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF/AP_NavEKF_Source.cpp
---

# EKF Source Options (EK3_SRC_OPTIONS)

## Description
Advanced configuration bitmask for blending or switching between multiple sensor sources (e.g., GPS and Optical Flow).

## Tuning & Behavior
*   **Default Value:** 1 (FuseAllVelocities)
*   **Bitmask:**
    *   Bit 0: FuseAllVelocities (Allows simultaneous use of multiple velocity sources)
    *   Bit 1: AlignExtNavPos (Aligns external nav position when using optical flow)