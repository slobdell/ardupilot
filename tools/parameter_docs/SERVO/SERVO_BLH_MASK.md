---
layout: parameter
name: SERVO_BLH_MASK
display_name: BLHeli Channel Bitmask
description: A bitmask that enables BLHeli pass-thru and digital DShot protocols on specific output channels.
default_value: 0
range: 0 4294967295
units: 
group: SERVO
visual_asset_id: servo_blh_mask_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L53
---

# BLHeli Channel Bitmask (SERVO_BLH_MASK)

## Description
`SERVO_BLH_MASK` tells ArduPilot which physical output pins are connected to digital **BLHeli_S**, **BLHeli_32**, or **AM32** ESCs.

*   **PWM (Default):** If an output is NOT in this mask (and `SERVO_BLH_AUTO` is 0), it sends a standard analog PWM signal.
*   **DShot:** If an output IS in this mask, it sends a high-speed digital DShot signal (as defined by `MOT_PWM_TYPE`).

This mask is also required for **BLHeli Pass-Thru**, which allows you to configure your ESCs (like changing motor direction or updating firmware) directly through the flight controller using the BLHeliSuite software.

## The Mathematics
The parameter is a 32-bit integer bitmask.
$$ \text{Active Channels} = \sum 2^i \cdot b_i $$

*   **Bit 0 (1):** Output 1
*   **Bit 1 (2):** Output 2
*   **Bit 3 (8):** Output 4
*   **Example:** To enable DShot on Outputs 1, 2, 3, and 4: $1+2+4+8 = \mathbf{15}$.

## The Engineer's View
Used in `AP_BLHeli::init()`.
Setting this bitmask triggers the underlying HAL to reconfigure the timer pins for that channel into DShot mode. 
Note: On many boards, outputs are grouped into "Timer Groups." Enabling DShot on one pin in a group may force all other pins in that group to also use DShot or be disabled.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:**
    *   **Manual Config:** Use the bitmask to select exactly which motors are digital.
    *   **Automatic Config:** For standard quads, it is often easier to set `SERVO_BLH_AUTO = 1`, which automatically enables this mask for all outputs assigned as "Motors" (`SERVOx_FUNCTION` 33-40).
*   **Reboot Required:** You MUST reboot after changing this mask for the hardware pins to reconfigure.