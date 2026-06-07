---
layout: parameter
name: NTF_LED_TYPES
display_name: LED Driver Types
description: A bitmask that selects which types of LED drivers are active.
default_value: 309
range: 0 524287
units: 
group: NTF
visual_asset_id: led_types_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Notify/AP_Notify.cpp#L208
---

# LED Driver Types (NTF_LED_TYPES)

## Description
`NTF_LED_TYPES` determines which lights on your drone will flash to indicate status (like GPS lock, Arming, or Low Battery).

ArduPilot supports many different LED systems simultaneously. You can have the built-in board LED flashing alongside an external NeoPixel strip and a DroneCAN high-brightness LED.

*   **Bit 0 (1): Built-in LED.** The small RGB LED on the flight controller itself.
*   **Bit 2 (4): External ToshibaLED.** The standard "I2C LED" found on many external GPS/Compass modules (e.g., Here2, Here3).
*   **Bit 5 (32): DroneCAN.** For CAN-bus connected LEDs.
*   **Bit 8 (256): NeoPixel.** For addressable LED strips (WS2812B) connected to a PWM output.
*   **Bit 11 (2048): DShot.** Uses the LEDs built into BLHeli_32/AM32 ESCs.

## The Engineer's View
Defined in `AP_Notify.cpp`. 
During initialization, the `AP_Notify::add_backends()` function iterates through the set bits and instantiates the corresponding driver classes. Each driver is then added to the `_devices` array and updated at 50Hz.

## Tuning & Behavior
*   **Default Value:** 309 (Built-in + Internal Toshiba + External Toshiba + DroneCAN + NeoPixel).
*   **Recommendation:**
    *   **Standard Build:** Leave at default.
    *   **ESC LEDs:** If you want your motor LEDs to flash status, set **Bit 11** (add 2048).
    *   **Show Lights:** If you connect a NeoPixel strip for a light show, ensure **Bit 8** (256) is set.