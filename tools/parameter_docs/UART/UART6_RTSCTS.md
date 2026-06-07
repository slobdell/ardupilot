---
alias_target: UART1_RTSCTS
default_value: float(AP_HAL::UARTDriver::FLOW_CONTROL_DISABLE
description: Enable flow control. You must have the RTS and CTS pins available on
  the port. If this is set to 2 then flow control will be auto-detected by checking
  for the output buffer filling on startup.
display_name: Serial1 flow control
group: UART
investigation_status: alias
layout: parameter
name: UART6_RTSCTS
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/serial_options_dev.cpp#L42
units: ''
visual_asset_id: null
---

# Serial1 flow control

**Note:** This parameter functions identically to [UART1_RTSCTS](../UART/UART1_RTSCTS.html).
