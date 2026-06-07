# DDS / ROS 2 Interface (DDS)

## Overview
The **DDS** parameter group configures the **Micro-ROS (DDS)** client embedded within ArduPilot. This system allows the autopilot to communicate natively with **ROS 2** (Robot Operating System) nodes running on a companion computer (e.g., Raspberry Pi, Jetson).

This replaces the traditional MAVLink-to-ROS bridge (mavros) with a direct, high-bandwidth, low-latency link using the XRCE-DDS protocol.

## Key Concepts

### 1. Connection
The Micro-ROS client connects to a **Micro-ROS Agent** running on the companion computer via Serial or UDP.

### 2. Domain ID (`DDS_DOMAIN_ID`)
In DDS, the "Domain" is like a virtual network segment. Robots on Domain 0 cannot see messages from robots on Domain 1. This allows multiple robots to operate on the same WiFi network without crosstalk.

### 3. Reliability (`DDS_MAX_RETRY` / `DDS_TIMEOUT_MS`)
Configures how the client behaves if the Agent is not reachable (e.g., companion computer booting up).

## Parameter Breakdown

*   **`DDS_ENABLE`**: Master switch.
*   **`DDS_DOMAIN_ID`**: ROS 2 Domain ID (default 0).
*   **`DDS_UDP_PORT`**: Port for UDP transport (default 2019 or 8888 depending on transport).
*   **`DDS_TIMEOUT_MS`**: Ping timeout.

## Integration Guide

### Setting up ROS 2
1.  **Companion:** Install ROS 2 (Humble or later) and the `micro_ros_agent`.
2.  **ArduPilot:** Set `DDS_ENABLE = 1`.
3.  **Transport:** Connect Serial or Ethernet.
4.  **Launch:** Start the agent: `ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyACM0 ...`
5.  **Verify:** Run `ros2 topic list` to see ArduPilot topics (IMU, Battery, etc.).

## Developer Notes
*   **Library:** `libraries/AP_DDS`
*   **Protocol:** XRCE-DDS (eProsima).