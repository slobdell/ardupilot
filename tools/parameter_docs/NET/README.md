# Network Configuration (NET)

## Overview
The **NET** parameter group configures the **Ethernet** and **Networking** subsystem for high-end flight controllers (e.g., Pixhawk 5X, 6X, Orange Cube Plus with Ethernet Carrier).

This system allows the autopilot to communicate over a standard Local Area Network (LAN) using TCP or UDP, providing extremely high bandwidth compared to traditional serial telemetry.

## Key Concepts

### 1. Static vs. Dynamic IP (`NET_DHCP`)
*   **DHCP (1):** Autodetect IP address from a router.
*   **Static (0):** Use the IP addresses manually defined in `NET_IPADDR0`...`3`.

### 2. Network Ports (`NET_Pn_...`)
ArduPilot supports multiple concurrent network connections (Sockets).
*   **`NET_P1_TYPE`**: 0=UDP Client, 1=UDP Server, 2=TCP Client, 3=TCP Server.
*   **`NET_P1_PORT`**: The network port number (e.g., 14550 for MAVLink).
*   **`NET_P1_PROTOCOL`**: Selects the protocol (1=MAVLink, 5=GPS, etc.).

### 3. MAC Address Configuration
Allows overriding the hardware MAC address for network environments with strict MAC filtering.

## Parameter Breakdown

*   **`NET_ENABLE`**: Master switch.
*   **`NET_IPADDRx`**: Static IP configuration.
*   **`NET_NETMASK`**: Network mask (usually 24 for 255.255.255.0).

## Integration Guide
1.  **Hardware:** Plug the autopilot into an Ethernet switch or companion computer.
2.  **Enable:** Set `NET_ENABLE = 1`.
3.  **Configure Port:** Set `NET_P1_TYPE = 1` (UDP Server) and `NET_P1_PORT = 14550`.
4.  **Connect:** Open Mission Planner and select "UDP" with port 14550.

## Developer Notes
*   **Library:** `libraries/AP_Networking`.
*   **Performance:** Ethernet can handle much higher logging and telemetry rates (100Hz+) without saturation.