---
layout: parameter
name: EK3_BETA_MASK
display_name: Bitmask controlling sideslip angle fusion
description: Controls use of sideslip angle fusion for estimation of non-wind states during forward flight.
default_value: 0
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Bitmask controlling sideslip angle fusion (EK3_BETA_MASK)

## Description
Enables the "synthetic sideslip" assumption, which assumes that fixed-wing aircraft generally fly with zero sideslip. This allows the EKF to better estimate heading and wind even without a compass or during sensor failures.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Always (Force fusion even if a yaw sensor is available)
    *   Bit 1: WhenNoYawSensor (Only use if magnetometer/GPS-Yaw fails)
