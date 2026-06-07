# KDE Direct CAN Configuration (KDE)

## Overview
The **KDE** parameter group (specifically `KDE_NPOLE`) configures the interface for **KDE Direct CAN ESCs**.

## Key Concepts

### 1. Pole Count
To calculate accurate RPM from a brushless motor, the ESC (and the autopilot) must know how many permanent magnets (poles) are in the motor bell.
*   **`KDE_NPOLE`**: Sets the number of poles for the connected KDE motors.
    *   **Calculation:** Total magnetic poles (usually an even number like 14, 28, etc.).

## Developer Notes
*   **Library:** `libraries/AP_KDECAN`.
*   **Context:** Only relevant if using KDE Direct specialized CAN ESCs.