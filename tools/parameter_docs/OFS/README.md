# Follow Offset Type (OFS)

## Overview
The **OFS** parameter group (specifically `OFS_TYPE` or `FOLL_OFS_TYPE`) configures the coordinate frame for **Follow Mode**.

## Key Concepts

### 1. Frame Selection
*   **0 (North-East-Down):** The offset from the leader is fixed to the world. If you set -10m X, the drone stays 10m South of the leader, regardless of which way the leader is facing.
*   **1 (Relative to Heading):** The offset is fixed to the leader's nose. If you set -10m X, the drone stays 10m behind the leader's tail. If the leader turns, the drone orbits around to stay behind it.

## Developer Notes
*   **Library:** `libraries/AP_Follow`.
*   **See Also:** [FOLL](../FOLL/README.md) for main follow configuration.