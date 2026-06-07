# Electronic Fuel Injection (EFI)

## Overview
The **EFI** parameter group configures the interface for monitoring internal combustion engines equipped with **Electronic Fuel Injection** (EFI) systems or engine control units (ECUs).

ArduPilot does not *control* the injection timing (the ECU does that); instead, it *monitors* the engine status to provide:
1.  **RPM:** For throttle governing and vibration filtering.
2.  **Fuel Flow:** For accurate remaining range estimation.
3.  **Health:** Cylinder temperatures, manifold pressure, and ECU errors.

## Key Concepts

### 1. Driver Support
Supports major UAV engine manufacturers:
*   **NWPMU:** Northwest Power Management Unit.
*   **Currawong:** CAN-based ECUs.
*   **Hirth:** Serial interface.
*   **Loweheiser:** Serial interface.
*   **MegaSquirt:** Via CAN or Serial.

### 2. Fuel Density (`EFI_FUEL_DENS`)
Gasoline weight varies by blend and temperature. Setting this correctly ensures accurate weight/balance calculations if the GCS tracks fuel weight.

## Parameter Breakdown

*   **`EFI_TYPE`**: Driver selection.
*   **`EFI_PORT`**: Serial port selection (if using UART-based ECU).
*   **`EFI_BAUDRATE`**: Serial speed.

## Integration Guide
1.  **Connection:** Wire the ECU telemetry output to an Autopilot UART or CAN bus.
2.  **Configure:** Set `EFI_TYPE` and port settings.
3.  **Verify:** Check the "RPM" and "Fuel" values in the Mission Planner "Status" tab.

## Developer Notes
*   **Library:** `libraries/AP_EFI`
*   **Logging:** Generates `EFI` log messages with detailed engine stats.