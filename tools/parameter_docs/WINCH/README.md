# Winch Configuration (WINCH)

## Overview
The **WINCH** parameter group configures the **Autonomous Winch** subsystem. This allows the vehicle to lower and raise a payload on a cable.

## Key Concepts

### 1. Winch Types (`WINCH_TYPE`)
*   **1 (Servo):** Standard PWM winch servo.
*   **2 (MAVLink):** Winch controlled via an external MAVLink device.
*   **3 (DroneCAN):** CAN-based winch.

### 2. Rate Limits (`WINCH_RATE_MAX`)
Limits the speed (m/s) at which the cable is deployed or retracted.

## Developer Notes
*   **Library:** `libraries/AP_Winch`.
*   **Interaction:** Tightly coupled with the `PLDP` (Payload Place) library for automated cargo delivery.