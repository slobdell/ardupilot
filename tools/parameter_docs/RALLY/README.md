# Rally Point Configuration (RALLY)

## Overview
The **RALLY** parameter group configures the **Rally Points** system. Rally points are alternate "Safe Havens" for the drone to return to during a Failsafe or RTL event, instead of returning all the way to the original takeoff (Home) point.

Rally points are essential for long-range missions (e.g., 20km pipelines) where the vehicle may not have enough battery to return home if a failsafe occurs at the far end of the mission.

## Key Concepts

### 1. Nearest Point Logic
By default, if Rally Points are loaded, the autopilot will calculate the distance to all points and the Home point. It will then choose the **closest** valid point to return to.
*   **`RALLY_INCL_HOME`**: Determines if the Home point is included in this "closest point" calculation.

### 2. Sanity Checks (`RALLY_LIMIT_KM`)
If the nearest Rally Point is extremely far away (e.g., left over from a previous flight at a different location), the autopilot will ignore it to prevent a "fly-away."
*   **`RALLY_LIMIT_KM`**: The maximum allowable distance to a rally point (default 5km).

## Parameter Breakdown

*   **`RALLY_TOTAL`**: Read-only count of uploaded rally points.
*   **`RALLY_LIMIT_KM`**: Distance safety limit.

## Integration Guide
1.  **Plan:** Use the "Plan" tab in Mission Planner to drop Rally Points along your mission path.
2.  **Upload:** Write them to the flight controller.
3.  **Verify:** Arm the vehicle and ensure the GCS shows the rally points on the map.

## Developer Notes
*   **Library:** `libraries/AP_Rally`.
*   **Storage:** Stored in a dedicated region of EEPROM.