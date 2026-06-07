---
layout: parameter
name: SERIAL_PASSTIMO
display_name: Serial Passthrough Timeout
description: The number of seconds of inactivity before the serial bridge is automatically closed.
default_value: 0
range: 0 120
units: s
group: SERIAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SerialManager/AP_SerialManager.cpp#L336
---

# Serial Passthrough Timeout (SERIAL_PASSTIMO)

## Description
`SERIAL_PASSTIMO` is a safety timer for the serial bridge.

If no data is sent or received on the bridged ports for this many seconds, the autopilot will automatically close the bridge and revert the ports to their normal flight functions. This prevents the drone from being left in a "Non-Flight" state if you forget to manually disable the passthrough.

*   **0:** Disabled (No automatic timeout).
*   **Value:** Timeout in seconds.