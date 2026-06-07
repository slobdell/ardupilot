---
layout: parameter
name: PRX1_TYPE
display_name: Proximity type (Sensor 1)
description: Selects the driver for the first Proximity sensor.
default_value: 0
range: 0 18
units: 
group: PRX
visual_asset_id: prx_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Proximity/AP_Proximity_Params.cpp#L15
---

# Proximity type (PRX1_TYPE)

## Description
`PRX1_TYPE` enables a 360-degree Lidar or Radar for Object Avoidance.

Unlike a Rangefinder (which is usually a 1D single-point distance sensor), a Proximity sensor scans a sector or a full circle to build a map of obstacles around the vehicle. This data is used by the `AVOID` (Object Avoidance) library to stop before hitting objects or path-plan around them.

*   **0: None.**
*   **2: MAVLink.** Data sent from a Companion Computer.
*   **4: RangeFinder.** Uses an existing `RNGFND` instance (turned into a proximity sensor).
*   **5: RPLidarA2.** Common 360 Lidar.
*   **6: TeraRangerTowerEvo.** 8-zone ToF array.
*   **14: DroneCAN.**
*   **16: LD06.** Inexpensive 360 Lidar.

## The Engineer's View
Defined in `AP_Proximity`.
Enabling this allocates the driver. The driver then populates the `AP_Proximity_Boundary_3D` structure, which the Avoidance library (`AC_Avoid`) queries during flight.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Reboot Required:** Yes.
*   **Orientation:** 360-degree Lidars must be mounted flat. Check `PRX1_ORIENT` if mounted upside down.
