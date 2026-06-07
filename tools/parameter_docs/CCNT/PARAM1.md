---
layout: parameter
name: PARAM1
display_name: Custom Control Parameter 1
description: Placeholder parameter for custom flight control algorithms.
default_value: 0.0
range: -1000 1000
units: 
group: CCNT
visual_asset_id: custom_control_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_CustomControl/AC_CustomControl_Empty.cpp#L15
---

# Custom Control Parameter 1 (PARAM1)

## Description
`PARAM1` is a generic "Hook" for developers using the `AC_CustomControl` library.

If you are writing your own flight control laws (e.g., for a university research project or a specialized vehicle), this parameter provides a convenient way to pass values from the GCS into your C++ code without having to modify the global parameter table.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Usage:** Only active if `CCNT_TYPE` is set to a custom backend.
