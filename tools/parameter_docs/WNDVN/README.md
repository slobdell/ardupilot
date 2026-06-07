# Wind Vane Configuration (WNDVN)

## Overview
The **WNDVN** parameter group configures the **Wind Vane** (Anemometer) sensor. This is required for **Autonomous Sailing** and provides high-accuracy wind data for landing and takeoff on all vehicles.

## Key Concepts

### 1. Sensor Types (`WNDVN_TYPE`)
Defines the hardware protocol.
*   **1 (Analog):** Potentiometer-based vane (reads voltage).
*   **2 (I2C):** Digital I2C sensor (e.g., AS5600).
*   **3 (NMEA):** Standard marine NMEA 0183 wind sensor.
*   **4 (DroneCAN):** CAN-based sensors.

### 2. Calibration (`WNDVN_DIR_OFS`)
Aligns the sensor's "zero" position with the vehicle's "Forward" axis.

## Parameter Breakdown

*   **`WNDVN_SPEED_TYPE`**: Selection of speed sensor (e.g., cup anemometer vs ultrasonic).
*   **`WNDVN_DIR_PIN`**: (Analog) ADC pin number.

## Integration Guide
1.  **Hardware:** Mount the vane at the highest point of the vehicle, clear of air turbulence.
2.  **Config:** Set `WNDVN_TYPE`.
3.  **Calibrate:** Point the vane exactly forward and use `WNDVN_DIR_OFS` to zero the reading in the GCS.

## Developer Notes
*   **Library:** `libraries/AP_WindVane`.