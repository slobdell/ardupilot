# Crop Sprayer Configuration (SPRAY)

## Overview
The **SPRAY** parameter group configures the **Agricultural Sprayer** subsystem. This allows the drone to autonomously control pumps and spinners for crop dusting or industrial spraying missions.

## Key Concepts

### 1. Speed-Based Flow (`SPRAY_PUMP_RATE`)
To ensure even coverage, the pump speed must increase as the drone flies faster and decrease as it slows down.
*   **`SPRAY_PUMP_RATE`**: Defines the relationship between ground speed and pump PWM.

### 2. Auto-Shutoff (`SPRAY_SPEED_MIN`)
Prevents the drone from dumping chemicals while hovering or waiting for a GPS lock.
*   **`SPRAY_SPEED_MIN`**: The pump will only activate if the drone is moving faster than this speed (m/s).

## Parameter Breakdown

*   **`SPRAY_ENABLE`**: Master switch.
*   **`SPRAY_SPINNER`**: Toggles the centrifugal spinner (used to atomize the liquid).

## Integration Guide
1.  **Pin:** Map a servo output to `Sprayer` (Function 40) for the pump and `SprayerSpinner` (Function 83).
2.  **Config:** Calibrate the flow rate based on your nozzle specs.

## Developer Notes
*   **Library:** `libraries/AC_Sprayer`.