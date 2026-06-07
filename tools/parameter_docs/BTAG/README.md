# Smart Battery Tags (BTAG)

## Overview
The **BTAG** parameter group supports **Smart Battery Tagging** (NFC/RFID or SMBus). This system tracks the health and usage history of individual battery packs across multiple flights.

Unlike standard `BATT` parameters which configure the *sensor*, `BTAG` stores persistent data about the *battery pack itself* if the hardware supports retrieving a unique ID from the battery.

## Key Concepts

### 1. Cycle Counting
The autopilot tracks charge/discharge cycles to estimate battery aging.
*   **`BTAG_CYCLE_MIN`**: Minimum discharge (mAh or %) required to count as a "cycle."

### 2. Usage History
*   **`BTAG_FIRST_USE`**: Timestamp of first flight.
*   **`BTAG_LAST_USE`**: Timestamp of most recent flight.

## Parameter Breakdown

*   **`BTAG_CAPACITY`**: The factory capacity of the detected pack.

## Developer Notes
*   **Context:** Requires specific hardware support (e.g., Tattu/GensAce Smart Batteries or custom NFC readers).