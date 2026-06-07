---
layout: parameter
name: GPS1_COM_PORT
display_name: GPS Device physical COM port
description: Selects the internal COM port of the GPS device to communicate with (primarily SBF/Septentrio and GSOF/Trimble).
default_value: 0
range: 0 10
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp#L92
---

# GPS Device physical COM port (GPS1_COM_PORT)

## Description
`GPS1_COM_PORT` identifies which physical connector *on the GPS hardware itself* is being used to talk to the flight controller. 

This is only required for high-end professional GNSS receivers (like Septentrio or Trimble) that have multiple internal UART ports. Most consumer GPS modules (U-Blox) do not need this setting.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** If you are using a Septentrio (SBF) or Trimble (GSOF) receiver and the flight controller is plugged into the receiver's second port, set this to **1** or **2** to match the receiver's internal port numbering.