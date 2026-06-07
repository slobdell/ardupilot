---
layout: parameter
title: PARAM2
name: Empty param2
group: PARAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_CustomControl/AC_CustomControl_Empty.cpp#L21
---

# PARAM2: Empty param2

## Description
Dummy parameter for empty custom controller backend.

## Values
- **Default:** 0.0

## Description
This parameter is a placeholder reserved for use by the **Empty Custom Controller** backend.

- **Purpose:** ArduPilot allows developers to implement custom attitude control logic in C++ or Lua. This parameter provides a configurable float value that can be read by that custom logic (e.g., as a gain or threshold) without needing to recompile the main code to add new parameters.
- **Normal Operation:** If you are not using a custom controller backend, this parameter has no effect.
