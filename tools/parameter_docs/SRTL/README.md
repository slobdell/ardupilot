# Smart RTL Configuration (SRTL)

## Overview
The **SRTL** parameter group configures the **Smart Return to Launch** (SmartRTL) mode. Unlike standard RTL, which flies a straight line home, SmartRTL **retraces the exact path** the vehicle took to get there.

This is ideal for flying in areas with obstacles (like indoors or in a forest) where a straight-line path home might lead to a collision.

## Key Concepts

### 1. Breadcrumb Trail
As the drone flies, it continuously drops "breadcrumbs" in memory to record its path.
*   **`SRTL_POINTS`**: The maximum number of points held in memory. Once full, the oldest points are discarded (or simplified).

### 2. Path Pruning (`SRTL_ACCURACY`)
To save memory, the system "prunes" (simplifies) the path. If three points are in a nearly straight line, the middle point is deleted.
*   **`SRTL_ACCURACY`**: The maximum allowed deviation (meters) from the original path during pruning.

## Parameter Breakdown

*   **`SRTL_OPTIONS`**: Bitmask for specialized behaviors (e.g., face direction of flight during return).

## Integration Guide
*   **Prerequisite:** SmartRTL is always active in the background if enabled. You can switch to it manually via RC or let it be the target for a Failsafe action.

## Developer Notes
*   **Library:** `libraries/AP_SmartRTL`.
*   **Safety:** If the breadcrumb buffer is empty (e.g., failsafe happens immediately after takeoff), the vehicle defaults to standard straight-line RTL.