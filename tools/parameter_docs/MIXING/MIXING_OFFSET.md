---
layout: parameter
name: MIXING_OFFSET
display_name: "Mixing Offset"
description: "Mixer offset for V-Tail and Elevon setups"
default_value: 0
range: -100 100
units: "%"
group: MIXING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L636
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Mixing Offset (MIXING_OFFSET)

## Description
This parameter adds a fixed offset (bias) to the control surfaces when using V-Tail or Elevon mixing. It is primarily used to provide **Reflex** (upward elevator trim) on flying wings without reducing the available servo travel range, or to correct for minor build asymmetries.

## The Mathematics
$$ \text{Servo}_{\text{out}} = \text{Mixer}(\text{Pitch}, \text{Roll}) + \text{MIXING\_OFFSET} $$

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp`.
*   **Positive:** Typically adds up-elevator (reflex) on elevons.
*   **Negative:** Adds down-elevator.

## Tuning & Behavior
*   **Default Value:** 0%
*   **Flying Wings:** Often requires +5% to +10% reflex for stability.