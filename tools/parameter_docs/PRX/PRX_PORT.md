---
layout: parameter
name: PRX_PORT
display_name: Proximity Sensor Port (AP_Periph)
description: Selects the physical serial port index on the AP_Periph node used for the proximity sensor.
default_value: 0
range: 0 10
units: 
group: PRX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp#L563
---

# Proximity Sensor Port (PRX_PORT)

## Description
`PRX_PORT` is used on **AP_Periph** nodes to map a physical UART port to the proximity sensor driver.

If you are using a CAN-based peripheral node to bridge a serial Lidar to the main flight controller, this parameter tells the peripheral node which of its own serial ports is connected to the Lidar.

## Tuning & Behavior
*   **Default:** 0.
*   **Setup:** Refer to the wiring diagram for your specific AP_Periph hardware (e.g., Matek or CUAV CAN nodes) to find the correct port number.
*   **Reboot Required:** Yes.