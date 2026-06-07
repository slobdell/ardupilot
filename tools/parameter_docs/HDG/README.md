# Heading Correction Configuration (HDG)

## Overview
The **HDG** parameter group (specifically `HDG_CORR_EN` and `HDG_CORR_WT`) configures the **Heading Correction** logic, primarily within the context of **Autonomous Docking** (`DOCK` mode) for ArduRover.

During the final stages of a docking approach, the vehicle must align its heading perfectly with the docking station entrance to avoid a collision.

## Key Concepts

### 1. Correction Enable (`HDG_CORR_EN`)
Toggles the alignment correction logic. When enabled, the rover prioritizes heading alignment over direct-to-waypoint navigation during the "Final Approach" phase.

### 2. Weighting (`HDG_CORR_WT`)
Defines the strength of the correction.
*   **Higher values:** Vehicle will maneuver more aggressively to line up the heading.
*   **Lower values:** Smoother transition but may result in "crooked" docking.

## Developer Notes
*   **Library:** `Rover/mode_dock.cpp`.
*   **Context:** Only relevant for **ArduRover**.