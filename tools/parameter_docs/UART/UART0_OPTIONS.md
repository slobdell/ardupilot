---
layout: parameter
name: UART0_OPTIONS
display_name: UART 0 Serial Options
description: Bitmask for advanced UART configurations (Inversion, Half-Duplex, Pin Swap).
default_value: 0
range: 0 15
units: 
group: UART
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/serial_options_dev.cpp#L36
---

# UART 0 Serial Options (UART0_OPTIONS)

## Description
`UART0_OPTIONS` (usually appearing as `SERIAL0_OPTIONS`) provides low-level electrical control over the primary communication port.

This is often used when connecting the flight controller to non-standard hardware that requires specific signal logic.

*   **Bit 0 (1): Invert RX.** Flips the high/low logic for receiving.
*   **Bit 1 (2): Invert TX.** Flips the high/low logic for transmitting.
*   **Bit 2 (4): Half-Duplex.** Combines TX and RX onto a single wire (One-Wire mode).
*   **Bit 3 (8): Swap Pins.** Swaps the RX and TX functionality (Requires STM32 F7/H7).

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Only change if your external hardware (like an RC receiver or specialized sensor) explicitly requires it.
*   **Reboot Required:** Yes.