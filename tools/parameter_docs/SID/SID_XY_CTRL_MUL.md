---
layout: parameter
name: SID_XY_CTRL_MUL
display_name: "System identification XY control multiplier"
description: "Gain multiplier for XY position controller during System ID"
default_value: 0.1
range: 0.05 1.0
units: ""
group: SID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/systemid.cpp#L72
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/systemid.h#L68
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# System identification XY control multiplier (SID_XY_CTRL_MUL)

## Description
This safety parameter detunes (softens) the horizontal position controller during VTOL System Identification maneuvers. When injecting chirp or step signals to model the vehicle dynamics, the position controller normally tries to fight these disturbances. Reducing its gain allows the test signal to propagate effectively while still providing enough position holding to keep the vehicle from drifting away entirely.

## The Mathematics
$$ K_{\text{effective}} = K_{\text{standard}} \times \text{SID\_XY\_CTRL\_MUL} $$

## The Engineer's View
Defined in `ArduPlane/systemid.cpp`.
*   **Context:** Only active during the `SYSTEM_ID` flight mode when performing axis sweeps.

## Tuning & Behavior
*   **Default Value:** 0.1 (10% of normal gain)
*   **Increase:** If the vehicle drifts dangerously fast during SysID.
*   **Decrease:** If the SysID data is contaminated by the position controller fighting the test signal.