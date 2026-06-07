# DDS Domain Configuration (DOMAIN)

## Overview
The **DOMAIN** parameter group (specifically `DOMAIN_ID`) allows configuring the **ROS 2 Domain ID** for the DDS interface.

**Note:** This is often an alias or legacy name for `DDS_DOMAIN_ID`.

## Key Concepts

### 1. ROS 2 Domains
In ROS 2, the "Domain ID" isolates groups of robots.
*   **Domain 0:** Default.
*   **Domain 1-232:** Alternate domains.

## Parameter Breakdown

*   **`DOMAIN_ID`**: Integer ID.

## Integration Guide
*   **Match:** This value **must** match the `ROS_DOMAIN_ID` environment variable set on your companion computer (Raspberry Pi/Jetson). If they differ, the robot will not receive messages.

## Developer Notes
*   **Library:** `libraries/AP_DDS`.