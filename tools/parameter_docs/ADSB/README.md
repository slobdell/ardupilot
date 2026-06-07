# ADS-B Configuration (ADSB)

## Overview
The **ADSB** parameter group configures the **Automatic Dependent Surveillance–Broadcast** (ADS-B) subsystem. This system allows the autopilot to:
1.  **Receive (ADS-B In):** Detect nearby manned aircraft equipped with ADS-B transmitters. This data is fed into the **AVOID** library for potential collision avoidance actions.
2.  **Transmit (ADS-B Out):** Broadcast the drone's position, altitude, and velocity to air traffic control and other aircraft (requires a capable transceiver like the uAvionix Ping2020 or CubeOrange+ ADSB carrier board).

## Key Concepts

### 1. Hardware Selection (`ADSB_TYPE`)
Tells ArduPilot which driver to use for the connected hardware.
*   **1 (uAvionix):** For Ping/PingRX modules communicating via the uAvionix serial protocol.
*   **2 (MAVLink):** For devices that send standard ADSB_VEHICLE MAVLink messages (e.g., OpenOpener, some remote IDs).
*   **3 (Sagetech):** For Sagetech transponders.

### 2. Vehicle Identification (`ADSB_ICAO_ID` / `ADSB_SQUAWK`)
For "ADS-B Out" capable hardware, these parameters define the aircraft's identity.
*   **ICAO ID:** The unique 24-bit airframe address assigned by your aviation authority (FAA, EASA, etc.). **Do not make this up.**
*   **Squawk:** The 4-digit octal transponder code (usually 1200 for VFR in the US, 7000 in Europe).
*   **Callsign:** Often set via a separate parameter or string (`ADSB_CALLSIGN` or `FLIGHT_ID`).

### 3. Emitter Category (`ADSB_EMIT_TYPE`)
Defines the "Wake Turbulence Category" or type of vehicle broadcasted in the ADS-B message.
*   **14:** UAV (Unmanned Aerial Vehicle). This is the correct setting for most drones.

### 4. RF Configuration (`ADSB_RF_SELECT`)
Configures the radio receiver sensitivity (UAT 978MHz vs 1090ES).
*   **RX_ENABLED:** Enables receiving.
*   **UAT_RX:** Enable 978MHz reception (US general aviation below 18k ft).
*   **1090_RX:** Enable 1090MHz reception (Commercial airliners, international).

## Parameter Breakdown

*   **`ADSB_ENABLE`**: Master switch for the library.
*   **`ADSB_TYPE`**: Driver selection.
*   **`ADSB_BAUDRATE`**: Serial port speed (usually 57600).
*   **`ADSB_LIST_MAX`**: Maximum number of tracked targets held in RAM.
*   **`ADSB_LIST_RADIUS`**: Detection radius (meters) for tracking targets. Targets outside this are ignored to save memory.
*   **`ADSB_LOG`**: Log detected targets to the DataFlash log (ADSB message).

## Integration Guide

### ADS-B In Setup (PingRX)
1.  Connect PingRX to a Telem port.
2.  Set `SERIALx_PROTOCOL` to 2 (MAVLink 2) or specific ADSB protocol if required by driver logic (rare, usually auto-detected or mapped to `ADSB_TYPE`).
3.  Set `ADSB_TYPE = 1` (uAvionix).
4.  Reboot.
5.  Verify detections in GCS "Traffic" map.

### ADS-B Out Setup
1.  Requires GPS lock and valid time.
2.  Set `ADSB_ICAO_ID` to your assigned hex code.
3.  Set `ADSB_EMIT_TYPE` to 14.
4.  **Legal Warning:** Transmitting invalid ADS-B data is a federal offense in many jurisdictions. Ensure your ICAO ID is registered.

## Developer Notes
*   **Library:** `libraries/AP_ADSB`
*   **Singleton:** `AP_ADSB::get_singleton()`
*   **Interaction:** Feeds data into `AP_Avoidance` for "Simple Avoidance" or "ADSB Avoidance" behaviors (climb/descend/loiter).