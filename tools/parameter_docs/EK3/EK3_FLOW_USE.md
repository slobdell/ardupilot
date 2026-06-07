---
layout: parameter
name: EK3_FLOW_USE
display_name: EKF3 Optical Flow Usage
description: Controls how the EKF3 navigation filter uses data from a downward-facing Optical Flow sensor. Allows for navigation in GPS-denied environments.
default_value: 0
range: 0 2
units: 
group: EKF
visual_asset_id: ek3_flow_use_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L591
---

# EKF3 Optical Flow Usage (EK3_FLOW_USE)

## Description
`EK3_FLOW_USE` tells the flight controller what to do with the "eyes" of the drone—the Optical Flow sensor. 

Optical Flow sensors (like the PX4Flow or HereFlow) look at the ground and track how fast the pixels move. This data can be used to stabilize the drone's position, but only if the EKF knows how to interpret it. This parameter enables the fusion of that visual data into the drone's navigation math.

*   **0 (None):** The drone ignores the flow sensor.
*   **1 (Only for Terrain):** The drone uses the flow data specifically to help estimate the distance to the ground (useful for landing on varying textures).
*   **2 (For Navigation):** The drone uses the flow data as its primary source of speed (velocity). This is the setting used for **GPS-Denied flight** (indoor flight).

## The Mathematics
When set to **2 (Navigation)**, the EKF uses the flow rate ($\omega_{flow}$) and height ($h$) to calculate ground velocity ($V_g$):

$$ V_g = \text{Filter}(\omega_{flow} - \omega_{gyro}) \cdot h $$

Where:
*   $\omega_{gyro}$ is the drone's own rotation (subtracted to ensure the drone doesn't think it is "moving" just because it tilted).
*   $h$ is the altitude from a Rangefinder.

**Constraint:** Optical Flow **requires** a functioning Rangefinder. If `EK3_SRC1_POSZ` is not set to 2 (Rangefinder) or if the rangefinder fails, Optical Flow navigation will stop working.

## The Engineer's View
This parameter is the `_flowUse` member in `NavEKF3`.

It is a prerequisite for fusing flow data in `AP_NavEKF3_OptFlowFusion.cpp`:

```cpp
// AP_NavEKF3_OptFlowFusion.cpp
const bool fuse_optflow = (frontend->_flowUse == FLOW_USE_NAV) && frontend->sources.useVelXYSource(AP_NavEKF_Source::SourceXY::OPTFLOW);
```

Note that in modern ArduPilot (4.1+), you must also set the source selection in `EK3_SRCn_VELXY` to `OpticalFlow` for this parameter to have full effect.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 0 - 2
*   **Effect of Enabling (2):** The drone will be able to hover in one spot indoors without GPS.
*   **Effect of Disabling:** The drone will drift indoors and require manual correction by the pilot.

### Use Case Recommendations
*   **Indoor Warehouse Robotics:** **Set to 2.** Allows the drone to navigate autonomous paths between shelves using only floor texture.
*   **Outdoor GPS Fallback:** **Set to 2.** If GPS is lost near a building, the drone can "fail over" to Optical Flow to stay stationary rather than drifting into the building.
*   **Precision Landing:** **Set to 1.** Helps the EKF refine its local height estimate relative to the landing pad texture.

### Troubleshooting
*   **Scenario:** Drone starts "orbiting" (circles) as soon as I switch to Loiter indoors with Optical Flow.
    *   **Diagnosis:** Gyro-compensation mismatch. The EKF isn't correctly subtracting the drone's tilt from the flow data.
    *   **Fix:** Ensure `FLOW_ORIENT_YAW` is correct and perform the "Flow Calibration" flight.