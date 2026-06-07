---
layout: parameter
name: EFI_EN
display_name: EFI Throttle Linearization Enable
description: Enables the mathematical model to linearize throttle demand vs. engine power for EFI-equipped engines.
default_value: 0
range: 0 1
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI_ThrottleLinearisation.cpp#L16
---

# EFI Throttle Linearization Enable (EFI_EN)

## Description
`EFI_EN` enables advanced throttle mapping for combustion engines.

Combustion engines are inherently non-linear; the power produced at 50% throttle position is rarely 50% of the total available power. This can make the autopilot's altitude and speed control loops (TECS) perform poorly. Enabling this feature allows ArduPilot to use a measured "Power Curve" to translate its requested power into the correct throttle percentage for the ECU.

*   **0: Disabled (Default).** Uses a simple linear throttle-to-RPM mapping.
*   **1: Enabled.** Activates the linearization model.