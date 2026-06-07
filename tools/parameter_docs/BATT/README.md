# Battery Monitor Configuration (BATT)

## Overview
The **BATT** parameter group configures the power monitoring subsystem. This is essential for:
1.  **Safety:** Triggering a failsafe (RTL/Land) before the battery is exhausted.
2.  **Telemetry:** Reporting Voltage (V), Current (A), and Consumed Energy (mAh) to the pilot.
3.  **Estimation:** The autopilot uses voltage levels to scale motor outputs (voltage compensation) for consistent performance as the battery drains.

## Key Concepts

### 1. Monitor Type (`BATT_MONITOR`)
Selects the driver/hardware interface.
*   **3 (Analog Voltage Only):** Simple voltage divider.
*   **4 (Analog Voltage & Current):** Standard power module (Mauch, Holybro, generic).
*   **7 (SMBus-I2C):** Smart batteries (Maxell, Solo, some generic I2C BMS).
*   **8 (DroneCAN):** Digital power modules (Zubax, Mauch CAN).

### 2. Calibration (Analog)
For standard analog sensors (`Type = 4`), you must tune the scaling factors.
*   **`BATT_VOLT_MULT`**: Scales the 0-3.3V ADC reading to actual battery voltage.
*   **`BATT_AMP_PERVLT`**: Defines how many Amps correspond to 1V on the current pin.

### 3. Failsafes (`BATT_FS_...`)
ArduPilot supports "Low" and "Critical" battery failsafes.
*   **Triggers:** Low Voltage (`BATT_LOW_VOLT`), Low Capacity (`BATT_LOW_MAH`).
*   **Actions:** Report Only, Land, RTL, SmartRTL, Terminate.

### 4. Multiple Batteries (`BATT2_`, `BATT3_`...)
ArduPilot supports up to 16 battery monitors. The data can be:
*   **Summed:** Total voltage/current reported to GCS.
*   **Individual:** Reported separately.
*   **Redundant:** Automatic switchover if one fails (rare).

## Parameter Breakdown

*   **`BATT_MONITOR`**: Driver selector.
*   **`BATT_CAPACITY`**: Battery pack capacity in mAh (used for % remaining calculation).
*   **`BATT_VOLT_PIN` / `CURR_PIN`**: Hardware ADC pin assignment.
*   **`BATT_ARM_VOLT`**: Minimum voltage required to arm (prevents taking off with a dead battery).

## Integration Guide

### Calibrating a Standard Power Module
1.  **Connect:** Plug in the battery and connect via USB.
2.  **Measure:** Use a multimeter to read the actual voltage at the XT60 connector.
3.  **Adjust:** Modify `BATT_VOLT_MULT` until the GCS voltage matches your multimeter.
4.  **Current:** Apply a known load (motors spinning) and adjust `BATT_AMP_PERVLT` to match a wattmeter.

### Smart Battery Setup
1.  Set `BATT_MONITOR = 7` (SMBus).
2.  Set `BATT_I2C_BUS` to the correct bus (usually 0 or 1).
3.  Reboot.

## Developer Notes
*   **Library:** `libraries/AP_BattMonitor`
*   **Singleton:** `AP_BattMonitor::get_singleton()`
*   **Scaling:** Voltage compensation logic is handled in `AP_Motors`.