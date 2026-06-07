---
layout: parameter
name: ZIGZ_LINE_NUM
display_name: ZigZag Mode Total Lines
description: The total number of parallel legs to complete in a ZigZag mission.
default_value: 0
range: -1 32767
units: Lines
group: ZIGZ
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_zigzag.cpp#L57
---

# ZigZag Mode Total Lines (ZIGZ_LINE_NUM)

## Description
`ZIGZ_LINE_NUM` defines the "Mission Length" for ZigZag mode.

*   **-1: Infinity.** The drone will continue flying back and forth between the A and B points and stepping sideways until the pilot cancels the mode or the battery runs low.
*   **0:** Single Step. The drone will only perform the lateral movement when commanded, then wait.
*   **1-N:** The drone will automatically complete this many parallel legs across the field and then come to a halt.

## Tuning & Behavior
*   **Usage:** Set this to the number of rows in your field to automate the entire spraying or scanning job.