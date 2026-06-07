---
layout: parameter
name: OSD_W_SNR
display_name: OSD RC Link SNR Warning
description: The Signal-to-Noise Ratio (SNR) at which the OSD will start flashing a warning.
default_value: 0
range: -20 10
units: dB
group: OSD
visual_asset_id: osd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OSD/AP_OSD.cpp#L230
---

# OSD RC Link SNR Warning (OSD_W_SNR)

## Description
`OSD_W_SNR` sets the "Noise Alarm" for your radio signal. 

SNR (Signal-to-Noise Ratio) measures how much stronger your transmitter's signal is compared to the background electrical noise. Even if your signal is strong (high RSSI), if the noise is also high, the link will be poor. A higher SNR is better. If the SNR drops below this value, the readout on your OSD will flash.

## Tuning & Behavior
*   **Default:** 0 dB.
*   **Context:** This is primarily used by modern digital radio links (like ELRS or Crossfire) that report SNR data.
*   **Recommendation:** Consult your radio manufacturer's documentation for the minimum reliable SNR for your specific frequency and protocol (e.g., ELRS at 250Hz might need > -5 dB).
*   **Note:** If your SNR is consistently low, check for noisy electronics (VTX, ESCs) mounted too close to your RC receiver.