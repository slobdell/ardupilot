# Actuator / Analog Sensor Configuration (ACT)

## Overview
The **ACT** parameter group is primarily associated with the **AD7091R5** Analog-to-Digital Converter (ADC) driver, commonly used on **DroneCAN Peripheral** nodes (such as the Zubax GNSS or specialized power modules) for high-precision battery monitoring.

While the prefix "ACT" suggests "Actuator," in the current ArduPilot ecosystem, these parameters are almost exclusively used to calibrate the analog sensing of Voltage and Current on distributed power systems.

## Key Concepts

### 1. Analog Scaling (`ACT_VOLT_MULT` / `ACT_AMP_PERVLT`)
To convert the raw ADC voltage (0-3.3V or 0-5V) into meaningful real-world units (Battery Volts and Amps), linear scaling factors are applied.
*   **Multiplier:** Converts sensor logic voltage to battery voltage.
*   **Amps per Volt:** Converts the current sensor's output voltage to Amperes.

### 2. Zero-Point Calibration (`ACT_AMP_OFFSET`)
Current sensors (especially Hall Effect sensors) often output a non-zero voltage even when 0 Amps are flowing. This "Offset" must be subtracted to prevent the autopilot from integrating phantom current consumption (mAh) while the vehicle is sitting idle.

### 3. Peripheral Telemetry (`ACT_TELEM_RATE`)
Controls how frequently the peripheral node broadcasts its status (or actuator feedback) over the CAN bus to the central flight controller.

## Parameter Breakdown

*   **`ACT_AMP_OFFSET`**: Voltage offset of the current sensor at 0 Amps.
*   **`ACT_AMP_PERVLT`**: Sensitivity of the current sensor (Amps per sensed Volt).
*   **`ACT_VOLT_MULT`**: Voltage divider multiplier.
*   **`ACT_CURR_MAX`**: Maximum expected current (sanity check/scaling limit).
*   **`ACT_TELEM_RATE`**: Frequency of status updates (Hz).

## Integration Guide

### Calibrating Power Modules
1.  **Measure:** Use a multimeter to measure the actual battery voltage.
2.  **Adjust:** Tweak `ACT_VOLT_MULT` until the GCS reported voltage matches the multimeter.
3.  **Zero Current:** Disconnect the load (if possible) or ensure motors are off. Adjust `ACT_AMP_OFFSET` until the current reads ~0.0A.
4.  **Load Test:** Apply a known load (or use a wattmeter) to calibrate `ACT_AMP_PERVLT`.

## Developer Notes
*   **Library:** `libraries/AP_BattMonitor` (specifically `AP_BattMonitor_AD7091R5`) and `Tools/AP_Periph`.
*   **Context:** These parameters usually exist on the **Peripheral Node** itself, not the main Autopilot. You access them via the "DroneCAN/UAVCAN Parameters" menu in your GCS, not the main parameter list.
*   **Naming:** The `ACT_` prefix is a specific choice for this driver in the `AP_Periph` firmware build to avoid conflicts with the main `BATT_` group.