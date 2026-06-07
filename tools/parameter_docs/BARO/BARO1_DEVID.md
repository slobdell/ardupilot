---
layout: parameter
name: BARO1_DEVID
display_name: Barometer 1 Device ID
description: Unique hardware ID for the first barometer sensor.
default_value: 0
range: 
units: 
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Baro/AP_Baro.cpp#L191
---

# Barometer 1 Device ID (BARO1_DEVID)

## Description
`BARO1_DEVID` is a **Read-Only** parameter that identifies the specific barometer hardware detected by the autopilot as the primary sensor. It includes information about the sensor type (e.g., BMP280, MS5611), the communication bus (I2C/SPI), and the bus address.

*   **Role:** Diagnostic tool to verify that the expected barometer is being used.
*   **Usage:** If this is 0, the autopilot has failed to detect any barometer on the expected pins/buses.

## The Engineer's View
The ID is encoded using the standard ArduPilot `DeviceID` structure. 
It is populated during the `AP_Baro::init()` sequence when the driver successfully probes the hardware.

## Tuning & Behavior
*   **Default:** 0 (Detection failed or not yet performed).
*   **Action:** If your drone has multiple barometers, you can use this ID to identify which one is which in the logs.

