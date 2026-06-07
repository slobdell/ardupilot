# GPS Auto Switching (GPSAUTO)

## Overview
The **GPSAUTO** parameter group (specifically `GPS_AUTO_SWITCH`) defines how ArduPilot handles multiple GPS receivers.

When two GPS units are connected, the autopilot can automatically select which one to trust based on real-time health metrics.

## Key Concepts

### 1. Switching Logic
The autopilot continuously monitors the satellites visible, the HDOP (Horizontal Dilution of Precision), and the lock type (3D, RTK, etc.) for both units.
*   **Best Available:** If the primary GPS loses lock or its quality degrades below the secondary unit, the system seamlessly "swaps" the active navigation source.

## Parameter Breakdown
*   **`GPS_AUTO_SWITCH`**:
    *   **0:** Disabled (Use GPS 1 only).
    *   **1:** Use Best (Switch based on quality).
    *   **2:** Blend (Use a weighted average).
    *   **3:** Use GPS 2 only.

## Integration Guide
*   **Redundancy:** Essential for professional drones. If one GPS antenna fails or suffers from interference, the backup ensures the vehicle doesn't lose position hold.

## Developer Notes
*   **Library:** `libraries/AP_GPS`.
*   **See Also:** [GPS](../GPS/README.md) for general configuration.