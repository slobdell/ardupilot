---
layout: parameter
name: FRAME_CONFIG
display_name: "Frame configuration"
description: "Selects the physical motor layout (mixer) for the Sub"
default_value: 1
range: 0 7
units: ""
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduSub/Parameters.cpp#L282
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Frame configuration (FRAME_CONFIG)

## Description
This parameter defines the physical arrangement of thrusters on the ROV. It selects the "Mixer Matrix" that translates pilot commands (Forward, Strafe, Vertical, Yaw, Pitch, Roll) into individual motor PWM outputs.

## The Mathematics
$$ \vec{\omega}_{\text{motor}} = \mathbf{M}_{\text{mixer}} \times \vec{u}_{\text{control}} $$

## The Engineer's View
Defined in `ArduSub/Parameters.cpp`. Values map to `AP_Motors6DOF::sub_frame_t`:
*   **0:** BlueROV1
*   **1:** Vectored (BlueROV2 Default)
*   **2:** Vectored 6DOF
*   **3:** Vectored 6DOF 90deg
*   **4:** SimpleROV-3
*   **5:** SimpleROV-4
*   **6:** SimpleROV-5
*   **7:** Custom

## Tuning & Behavior
*   **Critical:** Must be set correctly before the first dive. An incorrect setting will cause the ROV to spin uncontrollably or move in wrong directions.
*   **Reboot Required:** Changes usually require a reboot to take effect properly.