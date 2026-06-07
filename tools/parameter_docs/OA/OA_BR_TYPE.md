---
layout: parameter
name: OA_BR_TYPE
display_name: BendyRuler Type
description: Controls whether BendyRuler avoidance searches horizontally, vertically, or both.
default_value: 1
range: 0 2
units: 
group: OA
visual_asset_id: bendy_ruler_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OABendyRuler.cpp#L45
---

# BendyRuler Type (OA_BR_TYPE)

## Description
`OA_BR_TYPE` restricts which way the drone can dodge.

*   **1: Horizontal (Default).** The drone steers left or right to go around the obstacle. Standard behavior.
*   **2: Vertical.** The drone climbs over or dives under the obstacle. (Risky if you don't have good ceiling/floor sensors).

## Tuning & Behavior
*   **Default Value:** 1.
*   **Recommendation:** Stick to **1 (Horizontal)** for most multirotors unless you are flying in a narrow canyon where going up is the only option.