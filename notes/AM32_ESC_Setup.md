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

New AM32 ESCs also ship with a **default Motor KV of 2220**, regardless of the motor actually installed. **This must be changed to match the real motor's KV rating.**

## Critical: Motor KV Must Match the Installed Motor

Motor KV isn't just a label — AM32 uses it to schedule the startup/commutation timing (the sinusoidal open-loop ramp before BEMF sensing takes over). The default 2220KV assumes a small, light, fast-spinning motor with low torque demand. If the real motor is a lower-KV, higher-torque unit (e.g. a 900KV motor swinging a large multi-blade prop), the mismatch causes the ESC's startup/commutation model to fight the actual load.

**Symptom observed:** front motors appeared saturated at all throttle levels with no perceptible thrust difference between low and max throttle — RC out tracked RC in correctly, but real thrust never scaled with it. Root cause was the un-updated 2220KV default fighting a 900KV motor spinning a 9x5x3 prop. Setting Motor KV to the correct value (900) in the configurator immediately fixed it.

**Takeaway:** any time a motor is installed or swapped, set **Motor KV** in the AM32 configurator to that motor's actual rating before flying — don't assume the default is harmless just because 3D mode and pole count are already correct.

## Configuring for Unidirectional Motors

1. Connect as described above
2. Click **Read** to load current settings
3. Uncheck **3D Mode**
4. Set **Motor KV** to the actual installed motor's rating (see below — do not leave at the 2220 default)
5. Click **Save** / **Write**
6. Power-cycle the ESC (disconnect battery, reconnect) — settings take effect on next boot
7. Click **Read** again to confirm the changes stuck

## Protocol

AM32 auto-detects the input protocol (PWM, DShot, etc.) — no manual setting required in the configurator. ArduPilot's DShot output will be picked up automatically on the signal wire.

## Motor Direction

If the motor spins the wrong direction after setup, toggle **Motor Direction** in the configurator and re-write. Match to your prop's CW/CCW marking.
