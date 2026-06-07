---
layout: parameter
name: LOG_BITMASK
display_name: Log Bitmask
description: A bitmask that selects which data categories are recorded to the SD card DataFlash logs.
default_value: 176126
range: 0 4294967295
units: 
group: LOG
visual_asset_id: logging_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/defines.h#L97
---

# Log Bitmask (LOG_BITMASK)

## Description
`LOG_BITMASK` is the "Recording Selector" for your drone's black box.

ArduPilot can log a massive amount of data, but recording everything all the time would fill up your SD card too fast and might overload the CPU. This bitmask allows you to pick exactly what you want to record.

## Key Bits
*   **Bit 0 (1): ATTITUDE_FAST.** Logs attitude at the fastest possible rate. (Heavy CPU).
*   **Bit 1 (2): ATTITUDE_MED.** Logs attitude at a medium rate. (Standard).
*   **Bit 2 (4): GPS.** Logs GPS position and satellite health.
*   **Bit 3 (8): PM.** Processor Monitoring (CPU load and loop times).
*   **Bit 7 (128): IMU.** Raw accelerometer and gyro data.
*   **Bit 9 (512): CURRENT.** Battery voltage and amperage.
*   **Bit 12 (4096): PID.** Motor controller P-I-D gains and errors. (Essential for tuning).
*   **Bit 19 (524288): IMU_RAW.** Extreme high-speed raw IMU data for vibration analysis.

## Tuning & Behavior
*   **Default Value:** 176126 (Standard set including GPS, ATT_MED, CTUN, NTUN, etc.).
*   **Recommendation:**
    *   **Tuning PIDs:** Ensure Bit 12 (PID) is enabled.
    *   **Troubleshooting Vibrations:** Enable Bit 19 (IMU_RAW) briefly for one flight, then disable it (it generates huge files).