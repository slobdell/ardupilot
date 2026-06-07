---
layout: parameter
name: BRD_IO_ENABLE
display_name: Enable IO co-processor
description: Allows for the IO co-processor on boards with an IOMCU to be disabled.
default_value: 1
range: 0 2
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Enable IO co-processor (BRD_IO_ENABLE)

## Description
Controls the integrated I/O co-processor (IOMCU) found on many flight controllers (e.g., Pixhawk). The IOMCU handles low-level PWM output and safety switch logic.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Values:** 0:Disabled, 1:Enabled, 2:EnableNoFWUpdate
*   **Requires reboot to take effect.**
