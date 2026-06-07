# NMEA Output Configuration (NMEA)

## Overview
The **NMEA** parameter group configures the **NMEA 0183** data output from the autopilot. This is used to share the vehicle's position with external devices that expect a standard GPS-style serial stream (e.g., marine radars, handheld GPS units, or legacy data loggers).

## Key Concepts

### 1. Message Selection (`NMEA_MSG_EN`)
Determines which standard NMEA sentences are included in the serial stream.
*   **GGA:** Global Positioning System Fix Data (Time, Position, Fix Quality).
*   **RMC:** Recommended Minimum Specific GNSS Data (Time, Position, Speed, Date).
*   **VTG:** Course Over Ground and Ground Speed.

## Parameter Breakdown

*   **`NMEA_MSG_EN`**: Bitmask of enabled NMEA messages.

## Integration Guide
1.  **Port Setup:** Set `SERIALx_PROTOCOL = 15` (NMEA Output) on the desired UART.
2.  **Baud Rate:** Set the baud rate to match the receiving device (usually 4800 or 9600).
3.  **Config:** Enable the required messages in `NMEA_MSG_EN`.

## Developer Notes
*   **Library:** `libraries/AP_NMEA_Output`.