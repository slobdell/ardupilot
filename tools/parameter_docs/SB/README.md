# OSD Sidebar Configuration (SB)

## Overview
The **SB** parameter group (specifically `SB_H_OFS` and `SB_V_EXT`) provides layout adjustments for the **OSD Sidebars** (the moving tapes for Speed and Altitude).

## Key Concepts

### 1. Tape Placement
On analog OSDs, the "Speed Tape" and "Altitude Tape" are rendered as sidebars. Depending on your goggles' field of view, these tapes might be too close to the center or clipped at the edges.
*   **`SB_H_OFS`**: Adjusts the horizontal spacing of the tapes.
*   **`SB_V_EXT`**: Adjusts the vertical length/extension of the tapes.

## Developer Notes
*   **Library:** `libraries/AP_OSD`.
*   **Context:** Only relevant for vehicles with active OSD rendering.