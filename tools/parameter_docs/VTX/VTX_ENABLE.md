---
layout: parameter
title: VTX_ENABLE
name: Is the Video Transmitter enabled or not
group: VTX
---

# VTX_ENABLE: Is the Video Transmitter enabled or not

## Description
Toggles the Video Transmitter on and off.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disable |
| 1 | Enable |

- **Default:** 0

## Description
This parameter enables the **Video Transmitter (VTX) Control** subsystem.

- **Function:** When enabled, ArduPilot will attempt to communicate with the VTX (using SmartAudio, IRC Tramp, or CRSF) to set the channel, band, and power level based on the `VTX_` parameters.
- **Benefit:** Allows you to change your video channel from the OSD menu or Ground Control Station without pressing buttons on the VTX itself. It also enables features like "Pit Mode" to keep power low until you are ready to fly.
