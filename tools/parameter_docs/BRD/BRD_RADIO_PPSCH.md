---
layout: parameter
name: BRD_RADIO_PPSCH
display_name: Internal Radio PPS Channel
description: Maps the received packet-per-second (PPS) rate to an RC channel.
default_value: 0
range: 0 16
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L59
---

# Internal Radio PPS Channel (BRD_RADIO_PPSCH)

## Description
`BRD_RADIO_PPSCH` allows you to monitor the "Frame Rate" of your radio link in real-time. 

It maps the number of packets received per second (PPS) to a virtual RC channel. You can then view this value on your OSD or GCS to see if the link is slowing down (indicating interference or range limits) or staying at its full operational speed.

*   **0:** Disabled.
*   **1-16:** The RC channel number used to report PPS.

## Tuning & Behavior
*   **Recommendation:** Set to an unused channel (e.g. 15) to monitor link health during long-range flights.
*   **Context:** Used for integrated SPI radios where the autopilot has direct access to low-level packet statistics.