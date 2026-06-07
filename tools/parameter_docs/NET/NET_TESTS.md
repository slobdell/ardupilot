---
layout: parameter
name: NET_TESTS
display_name: Networking Tests
description: Bitmask to enable internal networking tests (Echo, Discard, etc.).
default_value: 0
range: 0 15
units: 
group: NET
visual_asset_id: networking_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Networking/AP_Networking.cpp#L32
---

# Networking Tests (NET_TESTS)

## Description
`NET_TESTS` enables standard debugging services on the drone's IP address.

*   **Bit 0 (1):** UDP Echo (Port 7). The drone bounces back any UDP packet sent to port 7.
*   **Bit 1 (2):** TCP Echo (Port 7).
*   **Bit 2 (4):** TCP Discard (Port 9). Accepts connections but ignores data.
*   **Bit 3 (8):** TCP Reflect (Port 19?).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Leave **0** unless you are debugging the network stack itself.