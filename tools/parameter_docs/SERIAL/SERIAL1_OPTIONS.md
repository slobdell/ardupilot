---
layout: parameter
name: SERIAL1_OPTIONS
display_name: Telem1 options
description: Advanced options for the SERIAL1 port (Invert, Half-Duplex, Pull-ups).
default_value: 0
range: 0 8191
units: 
group: SERIAL1
visual_asset_id: serial_options_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_SerialManager/AP_SerialManager.cpp#L267
---

# Telem1 options (SERIAL1_OPTIONS)

## Description
`SERIAL1_OPTIONS` is a bitmask to configure low-level hardware properties of the UART port.

*   **Bit 0 (1): Invert RX.** Inverts the logic level of the Receive pin. Used for S.Bus and some telemetry protocols.
*   **Bit 1 (2): Invert TX.** Inverts the Transmit pin.
*   **Bit 2 (4): Half Duplex.** Combines RX and TX onto a single wire (usually the TX pin). Used for FPort, S.Port, and some older protocols.
*   **Bit 3 (8): Swap TX/RX.** Swaps the physical pins (if supported by the STM32 hardware).
*   **Bit 4 (16): Pull Down RX.** Enables internal pull-down resistor.
*   **Bit 5 (32): Pull Up RX.** Enables internal pull-up resistor.
*   **Bit 6 (64): Pull Down TX.**
*   **Bit 7 (128): Pull Up TX.**

## The Mathematics
$$ \text{Options} = \sum 2^i \cdot b_i $$

Example: For **FPort** (Inverted + Half Duplex):
Inverted TX (2) + Half Duplex (4) = **6**? Or sometimes Inverted RX (1) + Half Duplex (4) = **5**?
(Note: Half Duplex usually implies TX pin usage. The inversion requirement depends on whether the receiver sends inverted S.Port or un-inverted FPort).

## The Engineer's View
These bits map directly to the HAL `UARTDriver::set_options()` method.
This provides software control over signal inversion, which historically required hardware inverters on older Flight Controllers (like Pixhawk 1). Modern F7/H7 chips have built-in inverters.

## Tuning & Behavior
*   **Default Value:** 0 (Standard 8N1, Full Duplex)
*   **Common Use Cases:**
    *   **S.Bus:** Usually requires **Invert RX (1)** if connected to a UART (not the RCIN pin).
    *   **S.Port / FPort:** Requires **Half Duplex (4)** and often **Invert (2)** depending on the receiver firmware.
    *   **GPS/Telemetry:** Usually **0**.