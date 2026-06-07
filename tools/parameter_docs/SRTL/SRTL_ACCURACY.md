---
layout: parameter
name: SRTL_ACCURACY
display_name: SmartRTL Accuracy
description: The minimum distance (in meters) between breadcrumb points in the SmartRTL trail.
default_value: 2.0
range: 0 10.0
units: m
group: SRTL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SmartRTL/AP_SmartRTL.cpp#L29
---

# SmartRTL Accuracy (SRTL_ACCURACY)

## Description
`SRTL_ACCURACY` defines the resolution of your "Breadcrumb" trail when using **Smart RTL**.

Unlike a standard RTL (which flies a straight line home), Smart RTL records your exact flight path and "rewinds" it to fly you back the same way you came. This is critical for avoiding obstacles like trees or buildings in complex environments. This parameter sets how far you must travel before the autopilot drops a new breadcrumb.

## Tuning & Behavior
*   **Default:** 2.0 meters.
*   **Effect of Decreasing:** Dropping points more often (e.g., every 0.5m) creates a very smooth, exact path, but it fills up the drone's memory much faster.
*   **Effect of Increasing:** (e.g. 5m) saves memory, but the return path will be "choppier" and might cut corners.
*   **Safety:** If the breadcrumb memory fills up, the drone will revert to standard (straight-line) RTL.