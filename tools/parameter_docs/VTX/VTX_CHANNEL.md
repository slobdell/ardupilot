---
layout: parameter
name: VTX_CHANNEL
display_name: Video Transmitter Channel
description: Selects the specific frequency channel (1-8) within the current band.
default_value: 0
range: 0 7
units: 
group: VTX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_VideoTX/AP_VideoTX.cpp#L48
---

# Video Transmitter Channel (VTX_CHANNEL)

## Description
`VTX_CHANNEL` selects the specific frequency within your chosen [VTX_BAND](VTX_BAND.html).

Most bands have 8 channels. This parameter uses an index from **0 to 7** (representing channels 1 to 8).

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** If you are experiencing interference from another pilot, try switching to a different channel within your band.
*   **Verification:** You should see the frequency update on your GCS status screen (if using SmartAudio/Tramp) and your goggles should lose and re-acquire the signal on the new frequency.