# GPS / GNSS Configuration (GPS)

## Overview
The **GPS** parameter group configures the **Global Positioning System** (and other GNSS constellations like GLONASS, Galileo, BeiDou). GPS is the primary source for horizontal position, ground velocity, and UTC time for the autopilot.

ArduPilot supports up to 2 simultaneous GPS units (`GPS` and `GPS2`), with advanced logic for blending and redundancy.

## Key Concepts

### 1. Driver Type (`GPS_TYPE`)
Tells ArduPilot which communication protocol to use.
*   **1 (Auto):** Autodetects standard u-Blox, MTK, or NMEA.
*   **2 (u-Blox):** Forces u-Blox binary protocol (recommended for most).
*   **9 (DroneCAN):** For CAN-based GPS units (e.g., Here3, CubePilot).
*   **17 (Moving Baseline):** For high-precision RTK Yaw.

### 2. Multi-GPS Redundancy (`GPS_AUTO_SWITCH`)
*   **0 (Disabled):** Use only the primary GPS.
*   **1 (Use Best):** Automatically switches to the GPS with the best satellite count and HDOP.
*   **2 (Blend):** Merges both GPS solutions into one for smoother navigation.

### 3. Moving Baseline Yaw (`GPS_MB_...`)
Advanced RTK setup where two GPS units on the same vehicle calculate a relative vector between each other to determine the vehicle's heading (Yaw). This allows for accurate heading even in areas with high magnetic interference where compasses fail.

### 4. Configuration (`GPS_SAVE_CFG`)
ArduPilot can automatically send configuration commands to u-Blox receivers at boot to set the correct update rate and constellations.

## Parameter Breakdown

*   **`GPS_TYPE`**: Primary driver.
*   **`GPS_PRIMARY`**: Which GPS is instance 1 (0 or 1).
*   **`GPS_GNSS_MODE`**: Bitmask to select constellations (GPS, SBAS, Galileo, etc.).
*   **`GPS_MIN_ELEV`**: Minimum satellite elevation (degrees) to ignore satellites near the horizon (noisy).
*   **`GPS_POS_X/Y/Z`**: The physical offset of the GPS antenna from the vehicle center of gravity.

## Integration Guide

### Standard Setup
1.  **Hardware:** Connect GPS to the `GPS` (Serial 3 or 4) port.
2.  **Config:** Set `GPS_TYPE = 1` (Auto).
3.  **Wait:** Power up outdoors. Check GCS for "3D Fix."

### Setting up Dual GPS Blending
1.  Connect two GPS units.
2.  Set `GPS_TYPE = 1` and `GPS_TYPE2 = 1`.
3.  Set `GPS_AUTO_SWITCH = 2` (Blend).
4.  Set `GPS_POS_...` and `GPS2_POS_...` offsets accurately.

## Developer Notes
*   **Library:** `libraries/AP_GPS`.
*   **Precision:** Use **RTK-capable** receivers (u-Blox F9P) and an injection source (MavESP8266 or GCS) for centimeter-level accuracy.