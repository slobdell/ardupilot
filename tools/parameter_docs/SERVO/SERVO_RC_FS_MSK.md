---
layout: parameter
name: SERVO_RC_FS_MSK
display_name: Servo RC Failsafe Mask
description: A bitmask that determines the behavior of RC Passthrough channels during a radio failsafe.
default_value: 0
range: 0 65535
units: 
group: SERVO
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SRV_Channel/SRV_Channels.cpp#L100
---

# Servo RC Failsafe Mask (SERVO_RC_FS_MSK)

## Description
`SERVO_RC_FS_MSK` controls what happens to your "Passthrough" servos when you lose radio signal.

If you have a camera gimbal or a pan/tilt mechanism controlled directly by a knob on your transmitter (`RCx_OPTION = PassThru`), what should it do if the radio link dies?
*   **Bit Unset (0):** The servo holds its last known position (Freeze).
*   **Bit Set (1):** The servo moves to its Trim/Center position.

## The Mathematics
$$ \text{Output} = \begin{cases} \text{Trim} & \text{if } \text{Bit Set} \land \text{Failsafe} \\ \text{Last Known} & \text{otherwise} \end{cases} $$

## Tuning & Behavior
*   **Default Value:** 0 (Hold Last).
*   **Recommendation:**
    *   **Gimbals:** Leave at **0** (Hold) to keep the camera pointing at the target.
    *   **Landing Gear:** Leave at **0** (Hold) so the gear doesn't accidentally retract/deploy.
    *   **Safety Mechanisms:** Set bit to **1** if you want a mechanism to return to a safe "Neutral" state on signal loss.
