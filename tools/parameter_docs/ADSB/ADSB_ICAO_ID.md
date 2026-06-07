---
layout: parameter
name: ADSB_ICAO_ID
display_name: ICAO_ID vehicle identification number
description: ICAO_ID unique vehicle identification number of this aircraft. This is an integer limited to 24bits. If set to 0 then one will be randomly generated. If set to -1 then static information is not sent, transceiver is assumed pre-programmed.
default_value: 0
range: -1 16777215
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# ICAO_ID vehicle identification number (ADSB_ICAO_ID)

## Description
Unique identifier for this aircraft in the ADS-B system.

## Tuning & Behavior
*   **Default Value:** 0 (Randomly generated)
*   **Range:** -1 to 16777215
*   **-1 means static information is not sent (pre-programmed transceiver).**
