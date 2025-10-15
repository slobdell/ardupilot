# SBUS Channel and Signal Architecture
**Document Version:** 1.0
**Date:** 2025-10-14

## 1.0 Overview

This document provides the definitive mapping of all SBUS channels used in this distributed flight control system. A clear and consistent channel assignment is critical for system stability and future development. All channel numbers are 1-based for readability, with the 0-based array index noted in parentheses.

## 2.0 Bus 1: PFC -> TVC & SFCs ("State Bus")

This bus is a broadcast from the Primary Flight Controller (PFC) and is read by both the TVC and all SFCs. It is responsible for communicating the high-level state of the ArduPilot `QuadPlane` state machine and the outputs of the hover stabilization controller.

| Channel | Index | Signal Name | Data Type | Description |
| :--- | :--- | :--- | :--- | :--- |
| **1-6** | 0-5 | `base_throttle[0-5]` | `float` (0.0-1.0) | The per-pod stabilization thrust from the 6DOF hover attitude controller. |
| **7** | 6 | `hover_thrust_cmd` | `float` (0.0-1.0) | The raw pilot command for vertical thrust in hover modes. |
| **8** | 7 | `hover_forward_cmd` | `float` (-1.0-1.0) | The raw pilot command for forward/backward movement in hover modes. |
| **9** | 8 | `hover_lateral_cmd` | `float` (-1.0-1.0) | The raw pilot command for lateral movement in hover modes. |
| **10** | 9 | *Unassigned* | - | Reserved for future use. |
| **11** | 10 | `transition_progress` | `float` (0.0-1.0) | The state of the VTOL transition. 0.0 = pure hover, 1.0 = pure forward flight. |
| **12** | 11 | `plane_throttle_cmd` | `float` (0.0-1.0) | The throttle command from the ArduPilot fixed-wing controller. |
| **13** | 12 | `TUNING_SELECTOR` | 3-Pos Switch | **(Proposed)** The RC switch used to select which PID gain (P, I, or D) to tune. Passed through from the pilot's receiver. |
| **14** | 13 | `TUNING_VALUE` | `float` (0.0-1.0) | **(Proposed)** The RC knob/slider value used to adjust the selected PID gain. Passed through from the pilot's receiver. |
| **15-16**| 14-15| *Unassigned* | - | Reserved for future use. |

## 3.0 Bus 2: TVC -> SFCs ("Blended Control Signal Bus")

This bus is a broadcast from the Thrust Vectoring Controller (TVC) to all SFCs. It carries the final, blended control signals that the SFCs will execute. The meaning of these channels is **consistent** across all flight modes.

| Channel | Index | Signal Name | Data Type | Description |
| :--- | :--- | :--- | :--- | :--- |
| **1-12** | 0-11 | `blended_vectors[0-11]` | `float` (-1.0-1.0) | The 12 final, blended per-pod vector commands (Pitch/Roll for each of the 6 pods). These are the result of the TVC's internal blending of the hover and forward-flight angle controllers. |
| **13** | 12 | `hover_thrust_factor` | `float` (1.0-2.0+) | The **unblended** thrust compensation factor (`1/cos(angle)`) for hover. The SFCs use this as part of their "Hover Model" calculation before the final blend. |
| **14-15**| 13-14| *Unassigned* | - | Reserved for future use. |
| **16** | 15 | `tvc_health` | `bool` (Low/High) | A binary signal indicating the health of the TVC's AHRS. Low = Unhealthy, High = Healthy. Used by SFCs for a pre-flight safety check. |

---
*Note on Indexing: ArduPilot `rcin` and `sbus` arrays are 0-indexed. SBUS Channel 1 corresponds to array index 0.*
