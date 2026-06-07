# Height Override Configuration (HGT)

## Overview
The **HGT** parameter group (specifically `HGT_OVR` or `FLOW_HGT_OVR`) configures the manual height reference for **Optical Flow** sensors.

## Key Concepts

### 1. Flow Height Requirement
Optical flow sensors cannot determine absolute speed without knowing the distance to the ground.
*   **Normal:** The system uses a Rangefinder (Lidar) to get live height data.
*   **Override (`HGT_OVR`):** If no rangefinder is present, you can enter a static height (in meters) into this parameter.
*   **Warning:** If you use an override, the Flow speed calculation will only be accurate when you are flying at exactly that height. If you fly higher, the drone will think it's moving slower than it actually is, potentially causing instability.

## Parameter Breakdown

*   **`HGT_OVR`**: Static height for flow calculation (meters).
    *   **0:** Use Rangefinder data (Default).

## Developer Notes
*   **Library:** `libraries/AP_OpticalFlow`.
*   **Usage:** Only intended for bench testing or very specific research environments where a fixed altitude is maintained via other means.