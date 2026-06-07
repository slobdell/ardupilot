---
layout: parameter
name: ZIGZ_DIRECTION
display_name: ZigZag Mode Step Direction
description: Selects the lateral direction the vehicle moves when a "Step" is commanded.
default_value: 0
range: 0 1
units: 
group: ZIGZ
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_zigzag.cpp#L50
---

# ZigZag Mode Step Direction (ZIGZ_DIRECTION)

## Description
`ZIGZ_DIRECTION` determines which way the drone "marches" across the field.

*   **0: Right.**
*   **1: Left.**

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Set this based on your starting position and the shape of your field. If you start on the left edge of a field, you will want the drone to step **Right (0)** to cover the remaining area.