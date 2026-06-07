---
layout: parameter
name: TMODE_RIGHT
display_name: "Tmode right action"
description: "Action for the Right/Return button in Toy Mode"
default_value: 2
range: 0 5
units: ""
group: TMODE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L111
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.h#L114
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Tmode right action (TMODE_RIGHT)

## Description
This parameter defines the function of the "Right" shoulder button (often labeled "Return") on Toy-grade controllers supported by ArduCopter's Toy Mode.

## The Mathematics
Enum Mapping.

## The Engineer's View
Defined in `ArduCopter/toy_mode.cpp`.
*   **0:** None
*   **1:** Safety (Toggle Motor Interlock)
*   **2:** Arm / Land / RTL (Context sensitive)
*   **3:** Mode Toggle
*   **4:** Stunt

## Tuning & Behavior
*   **Default Value:** 2 (Arm/Land/RTL)
*   **Behavior:** Press to Arm. Press in flight to RTL. Press near ground to Land.