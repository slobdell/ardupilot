---
layout: parameter
name: VISO_TYPE
display_name: Visual Odometry Type
description: Selects the visual odometry camera driver.
default_value: 0
range: 0 3
units: 
group: VISO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_VisualOdom/AP_VisualOdom.cpp#L37
---

# VISO_TYPE: Visual Odometry Type

## Description
Selects the visual odometry camera driver.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | MAVLink (OpenMV, T265 via MAVLink) |
| 2 | Intel T265 (USB) - Linux boards only |
| 3 | VOXL (Serial) |

- **Default:** 0

## Description
This parameter enables the **Visual Odometry** subsystem, allowing the drone to hold position and navigate without GPS by tracking features in the environment.

- **MAVLink (1):** Most common. Used when a companion computer (like a Raspberry Pi or Jetson) runs the VIO software (e.g., OpenVINS, ORB-SLAM) and sends the pose data to the flight controller via MAVLink.
- **T265 (2):** Only applicable for Linux-based flight controllers that can directly read the Intel Realsense T265 via USB.

