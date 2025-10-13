# SBUS Hardware-in-the-Loop (HITL) Test Notes

This document summarizes the validation of the SBUS input and output functionality on the MicoAir H743 flight controller running a custom ArduPilot firmware.

## 1. Test Setup

The test was conducted using a closed-loop hardware setup:

- **Flight Controller (FC):** MicoAir H743 running the custom ArduPilot loop.
- **SBUS Generator:** An ESP32S3 microcontroller programmed to send arbitrary, static SBUS frames. This was connected to the FC's designated RC Input port (`SERIAL5`).
- **SBUS Parser:** A second ESP32S3 microcontroller programmed to read, parse, and log incoming SBUS frames. This was connected to the FC's designated SBUS Output port (`SERIAL1`).
- **Logging:** The FC's custom `newMain()` function was configured to log received RC input values to a debug serial port (`SERIAL4`).

## 2. SBUS Scaling Formulas

The primary goal was to validate the scaling between the raw 11-bit SBUS channel values (0-2047) and the PWM microsecond values (e.g., 1000-2000 µs) used within ArduPilot's `RC_Channels` and `SRV_Channels` libraries.

The following linear scaling formulas were empirically validated and confirmed to be correct.

### 2.1. SBUS Input (Raw SBUS to PWM)

This formula is used by ArduPilot to convert incoming raw SBUS data into PWM microseconds.

`PWM = (RAW_SBUS * 0.625) + 875`

### 2.2. SBUS Output (PWM to Raw SBUS)

This formula is used by ArduPilot to convert outgoing PWM microsecond commands into raw SBUS data for transmission.

`RAW_SBUS = (PWM - 875) * 1.6`

## 3. Validation Data

### 3.1. Input Test (Generator -> FC)

The SBUS generator sent the following raw values, and the FC's logs confirmed the correctly scaled PWM values.

| Raw SBUS Sent | Expected PWM (µs) | Actual PWM Logged (µs) | Status |
| :-----------: | :---------------: | :--------------------: | :----: |
|      368      |       1105        |          1105          |  OK    |
|     1024      |       1515        |          1515          |  OK    |
|     1680      |       1925        |          1925          |  OK    |

### 3.2. Output Test (FC -> Parser)

The FC's `exampleOutput()` function sent the following PWM values, and the SBUS parser's logs confirmed the correctly scaled raw SBUS values.

| PWM Sent (µs) | Expected Raw SBUS | Actual Raw SBUS Logged | Status |
| :-----------: | :---------------: | :--------------------: | :----: |
|     1000      |        200        |          201           |  OK    |
|     1500      |       1000        |          1001          |  OK    |
|     1600      |       1160        |          1161          |  OK    |
|     2000      |       1800        |          1801          |  OK    |

*Note: Off-by-one differences are expected due to integer math and rounding.*

## 4. Conclusion

The end-to-end SBUS input and output functionality has been successfully validated. The data scaling is correct, linear, and conforms to standard SBUS conventions. This provides a reliable baseline for any future development involving RC input or servo/motor output via SBUS.
