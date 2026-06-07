---
layout: parameter
name: CC_PARAM1
display_name: "Custom Controller Param 1"
description: "Generic parameter for Custom Controller backend"
default_value: 0.0f
range: 
units: ""
group: CC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_CustomControl/AC_CustomControl_Empty.cpp#L15
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_CustomControl/AC_CustomControl_Empty.h#L22
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Custom Controller Param 1 (CC_PARAM1)

## Description
This is a generic placeholder parameter provided by the **Custom Control** library. It allows developers to pass tunable values to their custom C++ controller algorithms without needing to modify the main parameter table or recompile the entire parameter definitions.

## The Mathematics
User-defined by the custom controller implementation.

## The Engineer's View
Defined in `libraries/AC_CustomControl/AC_CustomControl_Empty.cpp`.
*   **Usage:** If you are running standard firmware, this parameter does nothing. If you have loaded a custom build with a specific `AC_CustomControl` backend, refer to that backend's documentation for the meaning of this value (e.g., gain, limit, or coefficient).

## Tuning & Behavior
*   **Default Value:** 0.0
*   **Note:** Only useful for developers or users of custom control branches.