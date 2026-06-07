---
layout: parameter
name: AHRS_ORIENTATION
display_name: Board Orientation
description: Overall board orientation relative to the standard orientation for the board type. This rotates the IMU and compass readings to allow the board to be oriented in your vehicle at any 90 or 45 degree angle.
default_value: 0
range: 0 43
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# Board Orientation (AHRS_ORIENTATION)

## Description
Software rotation for the flight controller mounting orientation.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Common Values:** 0:None, 1:Yaw45, 2:Yaw90, 4:Yaw180, 8:Roll180, 100:Custom
*   **Requires reboot and re-leveling after change.**
