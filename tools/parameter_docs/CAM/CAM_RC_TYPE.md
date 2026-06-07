---
layout: parameter
name: CAM_RC_TYPE
display_name: RunCam Device Type
description: Selects the specific RunCam model for serial communication and control.
default_value: 0
range: 0 5
units: 
group: CAM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Camera/AP_RunCam.cpp#L39
---

# RunCam Device Type (CAM_RC_TYPE)

## Description
`CAM_RC_TYPE` enables serial control for **RunCam** action cameras (like the Split, Hybrid, or Thumb). 

By connecting the camera's UART pins to the flight controller and setting this parameter, you can start/stop recording and navigate the camera's internal OSD menu using your transmitter sticks.

*   **0: Disabled.**
*   **1: RunCam Split.**
*   **2: RunCam Hybrid.**
*   **5: RunCam Thumb.**

## Tuning & Behavior
*   **Default:** 0.
*   **Requirement:** Requires a serial port to be configured for RunCam protocol (`SERIALx_PROTOCOL` = 26).
*   **Benefit:** Allows for hands-free recording control, ensuring you never forget to "hit record" before takeoff.