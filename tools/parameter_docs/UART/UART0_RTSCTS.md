---
layout: parameter
name: UART0_RTSCTS
display_name: UART 0 Flow Control
description: Enables hardware flow control (RTS/CTS) for the primary serial port.
default_value: 0
range: 0 2
units: 
group: UART
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/serial_options_dev.cpp#L42
---

# UART 0 Flow Control (UART0_RTSCTS)

## Description
`UART0_RTSCTS` enables Hardware Flow Control for the primary serial/USB port.

It is functionally identical to [UART1_RTSCTS](UART1_RTSCTS.html).