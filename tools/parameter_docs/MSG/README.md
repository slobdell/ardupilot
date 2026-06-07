# Message Display Configuration (MSG)

## Overview
The **MSG** parameter group (specifically `MSG_TIME` or `OSD_MSG_TIME`) manages the visibility of status notifications.

## Key Concepts

### 1. Message Persistence
When the autopilot triggers a status message (e.g., "Armed," "RTL Engaged," or "Low Battery"), it is displayed as a pop-up on the On-Screen Display (OSD).
*   **`MSG_TIME`**: Sets how long (in seconds) the text remains on screen before fading away.
    *   **Recommendation:** 5-10 seconds is standard. Longer values ensure you don't miss warnings, but may block other telemetry.

## Developer Notes
*   **Library:** `libraries/AP_OSD`.
*   **Context:** Only relevant if an analog or digital OSD is active.