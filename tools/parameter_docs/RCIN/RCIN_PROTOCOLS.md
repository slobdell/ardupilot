---
layout: parameter
name: RCIN_PROTOCOLS
display_name: Enabled RC Protocols (AP_Periph)
description: A bitmask used to restrict RC signal detection to specific protocols (SBUS, DSM, etc.).
default_value: 1
range: 0 65535
units: 
group: RCIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/rc_in.cpp#L41
---

# Enabled RC Protocols (RCIN_PROTOCOLS)

## Description
`RCIN_PROTOCOLS` is used on **AP_Periph** CAN nodes that are being used to bridge an RC receiver to the main flight controller.

By default, the system attempts to automatically detect the protocol of any receiver plugged into the serial port. However, if auto-detection is slow or failing, you can use this bitmask to force the system to only look for specific protocols.

*   **1:** All protocols enabled (Auto-detect).
*   **Bit 0:** PPM
*   **Bit 1:** SBUS
*   **Bit 2:** DSM
*   **Bit 3:** SUMD
*   **Bit 4:** SRXL
*   **Bit 10:** CRSF (Crossfire/ELRS)

## Tuning & Behavior
*   **Default:** 1 (Auto).
*   **Recommendation:** Leave at **1** unless your specific receiver is not being detected correctly.