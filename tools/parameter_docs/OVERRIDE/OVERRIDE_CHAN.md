---
layout: parameter
title: OVERRIDE_CHAN
name: IO override channel
group: OVERRIDE
---

# OVERRIDE_CHAN: IO override channel

## Description
If set to a non-zero value then this is an RC input channel number to use for giving IO manual control in case the main FMU microcontroller on a board with a IO co-processor fails.

## Values
- **Range:** 0 to 16
- **Increment:** 1
- **Default:** 0

## Description
This parameter configures a safety feature for flight controllers with a separate I/O processor (IOMCU).

- **Function:** If you assign an RC channel to `OVERRIDE_CHAN`, switching that channel high (>1750 PWM) will bypass the main flight processor (FMU) and give you direct manual control of the servos via the I/O processor.
- **Use Case:** Critical for recovering a plane if the main flight code crashes or freezes. It allows you to fly manually ("stick-to-servo") using the backup I/O chip.
- **0:** Disabled.

## Source Code
[ardupilot/ArduPlane/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L734)

