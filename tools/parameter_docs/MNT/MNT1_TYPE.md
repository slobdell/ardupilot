---
layout: parameter
name: MNT1_TYPE
display_name: Mount Type (Instance 1)
description: Selects the driver/protocol for the first gimbal (mount).
default_value: 0
range: 0 13
units: ""
group: MNT
visual_asset_id: mnt_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Mount/AP_Mount_Params.cpp#L16
---

# Mount Type (MNT1_TYPE)

## Description
`MNT1_TYPE` enables gimbal control for your primary camera or payload. ArduPilot supports a wide variety of gimbals, from simple servos to high-end serial gimbals with integrated cameras.

*   **0: None.** Gimbal control is disabled.
*   **1: Servo.** For DIY gimbals controlled via PWM outputs on the flight controller.
*   **3: Alexmos Serial.** For BaseCam/SimpleBGC controllers.
*   **4: SToRM32 MAVLink.**
*   **6: Gremsy.** Professional serial gimbals.
*   **8: Siyi.** For Siyi ZR10/A8/ZR30 and similar integrated gimbals.
*   **11: Viewpro.**

## The Engineer's View
Defined in `AP_Mount`.
Enabling a mount type allocates the corresponding driver backend. The backend is responsible for receiving target angles from the autopilot (or RC passthrough) and commanding the hardware.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Reboot Required:** Yes. Mount drivers are allocated at boot.
*   **Integration:** Once enabled, you must also configure the default mode ([MNT1_DEFLT_MODE](MNT1_DEFLT_MODE.html)) and limits ([MNT1_PITCH_MIN](MNT1_PITCH_MIN.html), etc.).