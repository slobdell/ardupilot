---
layout: parameter
title: NMEA_MSG_EN
name: Messages Enable bitmask
group: NMEA
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NMEA_Output/AP_NMEA_Output.cpp#L64
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NMEA_Output/AP_NMEA_Output.h#L64
---

# NMEA_MSG_EN: Messages Enable bitmask

## Description
This is a bitmask of enabled NMEA messages. All messages will be sent consecutively at the same rate interval.

## Values
- **Bitmask:**
  - **Bit 0:** GPGGA (Global Positioning System Fix Data)
  - **Bit 1:** GPRMC (Recommended Minimum Specific GPS/Transit Data)
  - **Bit 2:** PASHR (Pitch, Roll, and Heading)

## Description
This parameter controls which standard NMEA 0183 sentences are output by the autopilot when configured as an NMEA source.

- **Usage:** Typically used to feed position and attitude data to external payloads, cameras, or trackers that expect NMEA format (rather than MAVLink).
- **Default (3):** Enables **GGA** and **RMC** (3 = 1 + 2).

## Source Code
[ardupilot/libraries/AP_NMEA_Output/AP_NMEA_Output.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NMEA_Output/AP_NMEA_Output.cpp#L64)

