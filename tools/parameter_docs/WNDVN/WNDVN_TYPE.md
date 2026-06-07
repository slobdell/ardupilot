---
layout: parameter
name: WNDVN_TYPE
display_name: Wind Vane Type
description: Selects the hardware or method for determining wind direction.
default_value: 0
range: 0 11
units: 
group: WNDVN
visual_asset_id: windvane_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L46
---

# Wind Vane Type (WNDVN_TYPE)

## Description
`WNDVN_TYPE` enables support for measuring the wind direction relative to the vehicle. This is primarily used by Sailboats to trim their sails and by some autonomous vehicles for advanced weather logging or drift compensation.

*   **0: None.** Wind vane support is disabled.
*   **1: Heading when armed.** Assumes the wind is coming from the direction the vehicle is pointing when it arms.
*   **3: Analog.** For physical wind vanes that output a voltage proportional to the angle.
*   **4: NMEA.** For digital wind sensors (Anemometers) that output MAVLink or NMEA data strings.
*   **10-11: SITL.** For simulation testing.

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Setup:** Once enabled, you must configure the input pin ([WNDVN_DIR_PIN](WNDVN_DIR_PIN.html)) if using an Analog type.