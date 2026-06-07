---
alias_target: SERIAL1_OPTIONS
default_value: 0
description: Control over UART options. The InvertRX option controls invert of the
  receive pin. The InvertTX option controls invert of the transmit pin. The HalfDuplex
  option controls half-duplex (onewire) mode, where both transmit and receive is done
  on the transmit wire. The Swap option allows the RX and TX pins to be swapped on
  STM32F7 based boards.
display_name: Serial options
group: UART
investigation_status: alias
layout: parameter
name: UART6_OPTIONS
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/serial_options_dev.cpp#L36
units: ''
visual_asset_id: null
---

# Serial options

**Note:** This parameter functions identically to [SERIAL1_OPTIONS](../SERIAL1/SERIAL1_OPTIONS.html).
