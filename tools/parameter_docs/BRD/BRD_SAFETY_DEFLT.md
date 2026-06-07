---
layout: parameter
name: BRD_SAFETY_DEFLT
display_name: Sets default state of the safety switch
description: Controls the default state of the safety switch at startup.
default_value: 1
range: 0 1
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Sets default state of the safety switch (BRD_SAFETY_DEFLT)

## Description
Determines if the hardware safety switch starts in the "Safe" (blashing) or "Armed" (solid) state upon boot.

## Tuning & Behavior
*   **Default Value:** 1 (Starts in Safe state)
*   **Values:** 0:Disabled (Unsafe at boot), 1:Enabled (Safe at boot)
*   **Safety switch behavior can still be toggled manually after boot.**
