---
layout: parameter
name: SURFTRAK_DEPTH
display_name: "SURFTRAK minimum depth"
description: "Target depth below surface for Surface Tracking mode"
default_value: 50
range: 0 1000
units: "cm"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduSub/Parameters.cpp#L656
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# SURFTRAK minimum depth (SURFTRAK_DEPTH)

## Description
This parameter sets the target depth for the ROV when in **Surface Tracking** mode. Unlike standard Depth Hold which locks the absolute pressure/depth, Surface Tracking tries to maintain a constant distance *below the water's surface* (often using a rangefinder or inverted logic).

## The Mathematics
$$ Z_{\text{target}} = Z_{\text{surface}} + \text{SURFTRAK_DEPTH} $$

## The Engineer's View
Defined in `ArduSub/Parameters.cpp`.

## Tuning & Behavior
*   **Default Value:** 50 cm
*   **Range:** Ensure this is deep enough to prevent the thrusters from breaching the surface and cavitating.