---
layout: parameter
name: SURFACE_DEPTH
display_name: "Depth reading at surface"
description: "Pressure sensor reading offset at water surface"
default_value: -10
range: -100 0
units: "cm"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduSub/Parameters.cpp#L33
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Depth reading at surface (SURFACE_DEPTH)

## Description
This parameter calibrates the external pressure sensor for the ROV. It represents the depth reading (in cm) that the sensor outputs when the vehicle is actually at the surface. This accounts for atmospheric pressure variations and sensor offset drift.

## The Mathematics
$$ \text{Depth}_{\text{displayed}} = \text{Depth}_{\text{raw}} - \text{SURFACE_DEPTH} $$

## The Engineer's View
Defined in `ArduSub/Parameters.cpp`.
*   **Calibration:** Usually set automatically when you click "Calibrate Pressure" in QGroundControl while the ROV is on the surface.

## Tuning & Behavior
*   **Default Value:** -10 cm (Assumes sensor is slightly submerged or offset)