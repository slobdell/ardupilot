---
layout: parameter
name: BCN_ORIENT_YAW
display_name: "Beacon systems rotation from north in degrees"
description: "Beacon systems rotation from north in degrees"
default_value: 0
range: -180 +180
units: "deg"
group: BCN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.cpp#L69
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.h#L130
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Beacon systems rotation from north in degrees (BCN_ORIENT_YAW)

## Description
This parameter defines the orientation of the beacon system's local "X" axis relative to True North.

If your beacon system is set up such that its "Forward" (X-axis) points East instead of North, you would set this to 90 degrees. This aligns the local coordinate grid with the global compass directions, ensuring that "Flying North" in the beacon frame corresponds to "Flying North" in the real world.

## The Mathematics
The autopilot applies a 2D rotation matrix to the beacon's local (X, Y) coordinates before adding them to the global origin.

$$ \begin{bmatrix} X_{aligned} \\ Y_{aligned} \end{bmatrix} = \begin{bmatrix} \cos(\theta) & -\sin(\theta) \\ \sin(\theta) & \cos(\theta) \end{bmatrix} \begin{bmatrix} X_{raw} \\ Y_{raw} \end{bmatrix} $$

Where $ \theta $ is `BCN_ORIENT_YAW`.

## The Engineer's View
In `AP_Beacon_Backend::correct_position()`, this yaw rotation is applied to the raw position reported by the driver. It allows for arbitrary alignment of the physical beacon anchors without needing to reinstall them to face exactly North.

## Tuning & Behavior
*   **Default Value:** 0 (Beacon X-axis points North)
*   **Range:** -180 to +180 Degrees
*   **Positive Value:** Rotates the system Clockwise (e.g., +90 means X points East).
*   **Negative Value:** Rotates the system Counter-Clockwise (e.g., -90 means X points West).
*   **Tuning:** If your vehicle flies sideways when you command it forward (in Loiter/PosHold), or if the "Map" position moves incorrectly, this parameter is likely 90 or 180 degrees off.

