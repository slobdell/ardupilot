---
layout: parameter
name: VISO_ORIENT
display_name: Visual Odometry Orientation
description: The physical orientation of the VIO camera relative to the flight controller.
default_value: 0
range: 0 35
units: 
group: VISO
visual_asset_id: prx_orientation_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L69
---

# Visual Odometry Orientation (VISO_ORIENT)

## Description
`VISO_ORIENT` defines the mounting angle of your Visual Inertial Odometry (VIO) camera. 

For the autopilot to correctly translate "Camera Motion" into "Vehicle Motion," it must know which way the camera is facing. 

*   **0: Rotation_None (Standard).** Camera is facing forward, right-side up.
*   **Other Values:** Standard ArduPilot rotations (e.g. 25 for Downward).

## Tuning & Behavior
*   **Default:** 0.
*   **Reboot Required:** Yes.
*   **Validation:** View the `VISO` position data in your GCS while moving the drone. If moving forward causes the reported position to move backward or sideways, this orientation parameter is likely incorrect.