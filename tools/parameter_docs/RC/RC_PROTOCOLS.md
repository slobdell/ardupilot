---
layout: parameter
name: RC_PROTOCOLS
display_name: RC Protocols Mask
description: A bitmask that selects which RC protocols are scanned and decoded on the RC Input pin.
default_value: 1
range: 0 4294967295
units: 
group: RC
visual_asset_id: rc_options_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/RC_Channel/RC_Channels_VarInfo.h#L112
---

# RC Protocols Mask (RC_PROTOCOLS)

## Description
`RC_PROTOCOLS` tells the autopilot which languages to listen for on the RC Input pin.

By default, ArduPilot scans for **All (1)** known protocols (SBUS, DSM, PPM, CRSF, etc.). This makes setup easy but can cause CPU load or false detections. If you know exactly what receiver you are using, you can disable the others to speed up the detection process and prevent glitches.

*   **Bit 0 (1):** All Protocols (Default).
*   **Bit 1 (2):** PPM.
*   **Bit 2 (4):** IBUS.
*   **Bit 3 (8):** SBUS.
*   **Bit 4 (16):** SBUS Non-Inverted.
*   **Bit 5 (32):** DSM / Spektrum.
*   **Bit 6 (64):** SUMD.
*   **Bit 7 (128):** SRXL.
*   **Bit 8 (256):** SRXL2.
*   **Bit 9 (512):** CRSF (Crossfire / ELRS).
*   **Bit 10 (1024):** FPort.

## The Engineer's View
Defined in `AP_RCProtocol`.
The autopilot runs a state machine that samples the input pin. If `RC_PROTOCOLS` has Bit 0 set, it iterates through all available backend decoders. If you specify a single bit (e.g., 512 for CRSF), the loop skips the other decoders, saving CPU cycles and reducing the chance of a "ghost" signal being detected on a noisy line.

## Tuning & Behavior
*   **Default Value:** 1 (All).
*   **Recommendation:**
    *   **ExpressLRS / Crossfire:** Set to **513** (All + CRSF) or just **512** (CRSF only) if you want to be strict.
    *   **SBUS:** Set to **8**.
    *   **Ghosting:** If your servos twitch randomly, try disabling "All" and selecting only your specific protocol bit.
