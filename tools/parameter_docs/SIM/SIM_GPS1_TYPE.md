---
layout: parameter
name: SIM_GPS1_TYPE
display_name: Simulated GPS 1 Type
description: Selects the protocol for the primary simulated GPS.
default_value: 1
range: 0 19
units: 
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L743
---

# Simulated GPS 1 Type (SIM_GPS1_TYPE)

## Description
`SIM_GPS1_TYPE` tells the simulator which GPS language to speak to the autopilot.

*   **1: UBlox (Default).** The standard binary protocol used by M8N/F9P modules.
*   **5: NMEA.** The standard text-based protocol used by older or generic GPS units.
*   **19: MSP.** MultiWii Serial Protocol, used by DJI or Walksnail video systems to pass GPS data.

## Tuning & Behavior
*   **Default Value:** 1.
*   **Recommendation:** Keep at **1 (UBlox)** for the most realistic simulation of standard ArduPilot hardware.