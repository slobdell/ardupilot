# Temperature Sensor Configuration (TEMP)

## Overview
The **TEMP** parameter group configures the **Temperature Sensing** subsystem. This library manages sensors for monitoring battery temperature, motor temperature, or ambient air temperature.

## Key Concepts

### 1. Sensor Types (`TEMPn_TYPE`)
ArduPilot supports multiple temperature sensor instances.
*   **1 (Analog):** Using a thermistor or active analog sensor on an ADC pin.
*   **2 (I2C-MCP9808):** High-precision digital temperature sensor.
*   **3 (DroneCAN):** CAN-based temperature reports.

### 2. Monitoring and Logging
*   **`TEMP_LOG`**: Toggles recording of temperature data to the DataFlash log.
*   **`TEMP_MSG_RATE`**: Defines how often temperature updates are sent over MAVLink.

## Parameter Breakdown

*   **`TEMP1_TYPE`**: Driver selection.
*   **`TEMP1_SRC`**: Selects what the sensor is measuring (Battery, Internal, Motor).
*   **`TEMP_PIN`**: (Analog only) ADC pin number.

## Integration Guide
1.  **Hardware:** Connect your sensor (e.g., an NTC thermistor to an ADC pin with a pull-up resistor).
2.  **Enable:** Set `TEMP1_TYPE` and `TEMP1_SRC`.
3.  **Calibrate:** For analog sensors, use the `TEMP1_A0`...`A5` coefficients to define the thermistor's Beta-curve.

## Developer Notes
*   **Library:** `libraries/AP_TempSensor`.