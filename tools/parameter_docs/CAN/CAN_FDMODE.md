---
layout: parameter
name: CAN_FDMODE
display_name: Enable CAN FD Mode
description: Enables CAN Flexible Data-rate (FD) with Bit Rate Switching (BRS).
default_value: 0
range: 0 1
units: 
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp#L173
---

# Enable CAN FD Mode (CAN_FDMODE)

## Description
`CAN_FDMODE` upgrades the CAN bus protocol to **CAN FD** (Flexible Data-rate).

Standard CAN is limited to 8 bytes per frame and typically 1 Mbps. CAN FD supports up to 64 bytes per frame and much higher data rates (up to 5-8 Mbps) for the data payload phase. This reduces bus congestion and latency.

*   **0: Disabled (Classic CAN).**
*   **1: Enabled (CAN FD).**

## Tuning & Behavior
*   **Default:** 0.
*   **Hardware Requirement:** All devices on the bus MUST support CAN FD. If a single legacy CAN device is connected, communication will fail.
*   **AP_Periph:** This parameter is commonly found on AP_Periph nodes (like GPS or Airspeed sensors) to switch them into high-speed mode.