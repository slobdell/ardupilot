# Interval Configuration (INTRVAL)

## Overview
The **INTRVAL** parameter group (specifically `INTRVAL_MIN` or `CAM_INTRVAL_MIN`) sets time-based constraints for camera triggering.

## Key Concepts

### 1. Minimum Trigger Interval
Many digital cameras (DSLRs, mirrorless) require time to process an image and clear their buffer before they can take another photo.
*   **`INTRVAL_MIN`**: The minimum time in seconds (or milliseconds, check vehicle defaults) between successive shutter commands.
*   **Purpose:** Prevents the autopilot from "spamming" the camera, which can cause the camera to lock up, miss shots, or result in corrupt images.

## Developer Notes
*   **Library:** `libraries/AP_Camera`.
*   **Usage:** Crucial for high-speed mapping missions where waypoints are close together.