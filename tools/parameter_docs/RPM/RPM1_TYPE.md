---
layout: parameter
name: RPM1_TYPE
display_name: RPM Sensor Type (Sensor 1)
description: Enables the first RPM sensor and selects the hardware type.
default_value: 0
range: 0 7
units: 
group: RPM
visual_asset_id: rpm_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RPM/AP_RPM_Params.cpp#L25
---

# RPM Sensor Type (RPM1_TYPE)

## Description
`RPM1_TYPE` enables real-time monitoring of motor or rotor revolutions per minute (RPM). 

This is highly recommended for Helicopters (to monitor head speed) and for large Internal Combustion Engine (ICE) vehicles. It is also used by the Harmonic Notch Filter to dynamically track and eliminate motor-induced vibrations.

*   **0: None.** Disabled.
*   **2: GPIO.** For Hall effect or optical sensors connected to a digital pin.
*   **4: Harmonic Notch.** Derived from internal motor controllers (SITL/Special use).
*   **5: ESC Telemetry.** Averages RPM data from all ESCs reporting telemetry.
*   **7: DroneCAN.** For CAN-based RPM sensors.

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Integration:** Once enabled, you must configure the input pin ([RPM1_PIN](RPM1_PIN.html)) if using GPIO, and the scaling ([RPM1_SCALING](RPM1_SCALING.html)).