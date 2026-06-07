---
layout: parameter
name: NET_P1_TYPE
display_name: Network Port 1 Type
description: The connection type for virtual network serial port 1 (UDP Client/Server, TCP Client/Server).
default_value: 0
range: 0 4
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking_port.cpp#L32
---

# Network Port 1 Type (NET_P1_TYPE)

## Description
`NET_P1_TYPE` creates a "Virtual Serial Port" over the network. 

This allows you to send MAVLink data or GPS corrections over Ethernet or Wifi without using a physical UART cable.

*   **0: Disabled.**
*   **1: UDP Client.** The drone initiates a connection to a specific IP (defined in `NET_P1_IP`).
*   **2: UDP Server.** The drone waits for a GCS to send data to it.
*   **3: TCP Client.** Reliable connection initiated by the drone.
*   **4: TCP Server.** Reliable connection where the drone acts as a host.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Use **2 (UDP Server)** for standard GCS connections over Wifi. Use **3 (TCP Client)** if you are connecting to a fixed MAVLink routing server.
