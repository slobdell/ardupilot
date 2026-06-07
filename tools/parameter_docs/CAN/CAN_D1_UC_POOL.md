---
layout: parameter
name: CAN_D1_UC_POOL
display_name: DroneCAN Memory Pool Size
description: Amount of memory (in bytes) to allocate for the DroneCAN memory pool.
default_value: 8192
range: 1024 32768
units: bytes
group: CAN
visual_asset_id: dronecan_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L137
---

# DroneCAN Memory Pool Size (CAN_D1_UC_POOL)

## Description
`CAN_D1_UC_POOL` sets the RAM budget for the DroneCAN communications stack. 

The CAN bus is a "Message Based" network. As more devices (GPS, Compass, ESCs) send data, the flight controller needs a larger buffer to store and process those messages. If this pool is too small, messages will be dropped, leading to "Sensor Unhealthy" errors or sluggish control.

## The Engineer's View
Defined in `AP_DroneCAN.cpp`. 
This memory is allocated from the system heap during driver initialization. It is used by the `libcanard` library to manage the transfer buffers and reassemble multi-frame transfers.

## Tuning & Behavior
*   **Default Value:** 8192 (8KB) on most boards; 16384 (16KB) on H7 boards.
*   **High Load:** If you have many CAN ESCs and sensors (high bus utilization), increase this to **16384** or **32768**.
*   **Low Memory Boards:** On 1MB Flash boards (like F4), be careful increasing this as it takes away from the main system memory.
*   **Reboot Required:** Yes.