# GPS SBAS Configuration (GPSSBAS)

## Overview
The **GPSSBAS** parameter group (specifically `GPS_SBAS_MODE`) configures the **Satellite-Based Augmentation System** support.

SBAS (WAAS in the US, EGNOS in Europe, MSAS in Japan) provides regional differential corrections via geostationary satellites to improve the horizontal and vertical accuracy of standard GPS fixes.

## Key Concepts

### 1. SBAS Mode
*   **0 (Disabled):** Use raw GPS only.
*   **1 (Enabled):** Use SBAS if available.
*   **2 (Auto):** Autopilot decides based on fix quality.

## Developer Notes
*   **Library:** `libraries/AP_GPS`.