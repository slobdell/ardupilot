---
layout: parameter
name: NET_PASS1_ENABLE
display_name: Networking Passthrough Enable
description: Enables the data routing (passthrough) between two networking or serial endpoints on a peripheral node.
default_value: 0
range: 0 1
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/networking_passthru.cpp#L26
---

# Networking Passthrough Enable (NET_PASS1_ENABLE)

## Description
`NET_PASS1_ENABLE` activates a powerful "Digital Patch Bay" feature on peripheral nodes.

This allows you to take data coming in from one port (like an Ethernet socket) and pipe it directly out of another port (like a physical UART Serial port) on the same device. This is essential for transparently connecting specialized sensors or companion computers that are not natively CAN/DroneCAN compatible to the rest of the network.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Use Case:** Use this on an H7-based peripheral board to bridge a MAVLink telemetry stream from Ethernet to a Serial radio.