---
layout: parameter
name: VTX_BAND
display_name: Video Transmitter Band
description: Selects the frequency band for the video transmitter.
default_value: 0
range: 0 5
units: 
group: VTX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VideoTX/AP_VideoTX.cpp#L55
---

# Video Transmitter Band (VTX_BAND)

## Description
`VTX_BAND` defines the group of frequencies (Band) your video transmitter is using.

*   **1: Band A.**
*   **2: Band B.**
*   **3: Band E.**
*   **4: Airwave (Fatshark).**
*   **5: Raceband.** (Most popular for multi-pilot racing).

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Set this to match your video goggles. If you are flying with others, coordinate your Band and Channel to prevent signal overlap.