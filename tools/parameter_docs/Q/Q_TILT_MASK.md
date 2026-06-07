---
layout: parameter
name: Q_TILT_MASK
display_name: Tilt Rotor Mask
description: A bitmask selecting which motors can tilt to provide forward thrust.
default_value: 0
range: 0 65535
units: 
group: Q
visual_asset_id: q_tilt_mask_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L446
---

# Q_TILT_MASK: Tilt Rotor Mask

## Description
A bitmask selecting which motors can tilt to provide forward thrust.

## Description
`Q_TILT_MASK` defines which of your vertical lift motors are capable of rotating forward to fly like a plane.

*   **0: None (Standard QuadPlane).** Separate lift motors and a separate forward pusher motor.
*   **Bitmask:** Selects specific motors. For example, if Motors 1 and 2 (Front Left/Right) tilt, but the rear motor is fixed, you would select bits 0 and 1 (Value = 3).

## The Mathematics
$ \text{Tilt Motors} = \sum 2^{i-1} $
Where $i$ is the motor number (1-based).

*   **Convergence (Tri):** Front two motors tilt. Motor 1 and 2. Value =  + 2 = \mathbf{3}$.
*   **V-22 Osprey (Bicopter):** Both motors tilt. Motor 1 and 2. Value = **3**.
*   **Quad Tilt:** All 4 motors tilt. Value = **15**.

## The Engineer's View
Used in `Tiltrotor::setup()`.
If a motor is in this mask, ArduPilot will actuate the corresponding tilt servo (assigned via `SERVOx_FUNCTION = 41`) to transition the motor from vertical to horizontal as airspeed increases.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Set strictly according to your physical airframe.
*   **Vectored Yaw:** If all lifting motors tilt, you can often use `Q_TILT_TYPE` to enable "Vectored Yaw," using the tilt servos to steer the plane in hover instead of differential torque.