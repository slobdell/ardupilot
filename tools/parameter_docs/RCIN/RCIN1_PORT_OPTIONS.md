---
layout: parameter
name: RCIN1_PORT_OPTIONS
display_name: RC Input Port Options (Instance 1)
description: Bitmask for configuring serial properties (Inversion, Half-Duplex, etc.) on the primary RC input port.
default_value: 0
range: 0 15
units: 
group: RCIN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/rc_in.cpp#L66
---

# RC Input Port Options (RCIN1_PORT_OPTIONS)

## Description
`RCIN1_PORT_OPTIONS` provides low-level electrical control over the primary radio receiver connector.

This is often required for modern RC protocols like **FPort** (which needs inversion and half-duplex) or **SBUS** (which needs inversion). 

*   **Bit 0 (1): Invert RX.** Necessary for SBUS on some boards.
*   **Bit 1 (2): Invert TX.**
*   **Bit 2 (4): Half-Duplex.** Necessary for FPort or single-wire protocols.
*   **Bit 3 (8): Swap Pins.**

## Tuning & Behavior
*   **Default:** 0.
*   **Reboot Required:** Yes.
*   **Note:** This is usually handled automatically by the receiver protocol detection, but manual override is available for custom hardware setups.