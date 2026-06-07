---
layout: parameter
name: CAN_P1_FDBITRATE
display_name: CAN Port 1 FD Bitrate
description: The data phase bitrate (in Mbps) for CAN FD (Flexible Data-rate) frames on the first physical CAN port.
default_value: 5
range: 1 8
units: Mbps
group: CAN
visual_asset_id: can_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_CANManager/AP_CANIfaceParams.cpp#L42
---

# CAN Port 1 FD Bitrate (CAN_P1_FDBITRATE)

## Description
`CAN_P1_FDBITRATE` enables "High Speed" mode for modern CAN FD devices.

Standard CAN is limited to 1Mbps. CAN FD (Flexible Data-rate) allows the data payload portion of the packet to be sent much faster.

*   **5 (5 Mbps):** Standard for many modern DroneCAN FD peripherals.
*   **2 (2 Mbps):** Conservative setting.

## Tuning & Behavior
*   **Requirement:** Your hardware (Flight Controller and Peripheral) must support CAN FD.
