# RSSI Configuration (RSSI)

## Overview
The **RSSI** parameter group configures the **Received Signal Strength Indication**. This system allows the autopilot to monitor the quality of the radio link between the RC transmitter and the vehicle.

## Key Concepts

### 1. RSSI Types (`RSSI_TYPE`)
How does the receiver tell the autopilot the signal strength?
*   **1 (Analog Pin):** Legacy. High voltage (3.3V) on a dedicated wire means full signal.
*   **2 (PWM/RC Channel):** The receiver sends RSSI as a standard PWM value on a spare channel (e.g., Channel 8).
*   **3 (Receiver Protocol):** Modern. RSSI is embedded directly in the digital data stream (SBUS, CRSF, FPort). **Highly Recommended.**

### 2. Scaling (`RSSI_CHAN_LOW` / `HIGH`)
Maps the raw input (PWM or Voltage) to 0-100%.

## Parameter Breakdown

*   **`RSSI_TYPE`**: Input method selection.
*   **`RSSI_ANA_PIN`**: (Analog only) ADC pin number.

## Integration Guide
*   **Modern Setup:** If using CRSF (ELRS) or SBus, set `RSSI_TYPE = 3`. No further calibration is needed.
*   **Display:** Ensure the "RSSI" widget is enabled in your OSD to monitor link health during flight.

## Developer Notes
*   **Library:** `libraries/AP_RSSI`.