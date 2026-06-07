# AM32 ESC Setup Guide

## Configurator

Web app: https://am32.ca/configurator

## Power Sequence (Important)

AM32 requires a specific connection order:

1. Connect the ESC signal wire to USB passthrough / configurator interface
2. Open the configurator and connect via USB **first**
3. **Then** power the ESC with the battery

If you power the ESC before connecting via USB, the configurator may not detect it.

## Out-of-Box Defaults (Watch Out)

New AM32 ESCs ship with **3D mode enabled** (bidirectional). For standard unidirectional motors (e.g., Avatar wing motors), you must disable this before use.

## Configuring for Unidirectional Motors

1. Connect as described above
2. Click **Read** to load current settings
3. Uncheck **3D Mode**
4. Click **Save** / **Write**
5. Power-cycle the ESC (disconnect battery, reconnect) — settings take effect on next boot
6. Click **Read** again to confirm the change stuck

## Protocol

AM32 auto-detects the input protocol (PWM, DShot, etc.) — no manual setting required in the configurator. ArduPilot's DShot output will be picked up automatically on the signal wire.

## Motor Direction

If the motor spins the wrong direction after setup, toggle **Motor Direction** in the configurator and re-write. Match to your prop's CW/CCW marking.
