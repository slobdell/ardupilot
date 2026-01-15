# ArduPlane Adaptation for Vector-Thrust Blimp: Technical Design Document

## 1. Project Overview & Context
This document outlines the architectural adaptation of the **ArduPlane** flight stack to control a **Vector-Thrust Blimp**.

### The Challenge
We are building a semi-buoyant (95% buoyancy) airframe that requires characteristics of both a Plane (efficient forward flight on fins/wings) and a Copter (powered lift for hover).
*   **Why not ArduBlimp?** Existing Blimp flight stacks often assume neutral buoyancy or lack the advanced energy management features needed for long-duration flight.
*   **Why not QuadPlane?** We want to avoid the complexity and weight of separate lift motors. We aim to use a single set of thrust-vectoring motors for *both* lift and forward thrust.
*   **The Goal:** Adapt **ArduPlane** to treat the blimp as a fixed-wing aircraft with a **0 m/s stall speed**, seamlessly transitioning from aerodynamic lift (Cruise) to powered lift (Hover) using a unified control strategy.

### The Core Thesis: "Vectoring as a Virtual Elevator"
Instead of creating a complex new flight mode or state machine, we will modify the low-level **Output Mixer**.
*   The Autopilot will "think" it is flying a standard plane with a massive elevator.
*   We will intercept the **Pitch Output** signal.
*   **Low Demand:** Maps to the physical **Elevator**.
*   **High Demand (Saturation):** Spills over to rotate the **Main Motors**, converting thrust into lift.
This allows the standard PID loops, Navigation (L1), and Energy Management (TECS) systems to control the blimp without needing to know about its unique actuators.

---

## 2. Abstract Control Philosophy
The core objective of this adaptation is to enable a Blimp to fly using the standard ArduPlane flight stack. While Blimps are typically lighter-than-air, this project specifically models the airframe as a **Fixed-Wing Aircraft with a 0 m/s Stall Speed**.

### The Physics of the Blimp
*   **Heavy-Than-Air (HTA):** The blimp is approximately **95% buoyant**. It requires constant lift (aerodynamic or powered) to maintain altitude.
*   **Nose-Heavy:** The Center of Gravity (CG) is forward of the Center of Lift/Buoyancy. Without active control, the blimp naturally pitches down.
*   **Self-Weathervaning:** The large vertical surface area of the fins ensures the airframe naturally points into the wind, stabilizing yaw without active control in many conditions.
*   **No Roll Control:** The blimp is pendularly stable in roll. We explicitly **do not control roll**.
*   **Inertia:** The blimp has high rotational inertia. PID loops must be tuned to accommodate slow responses without integral windup causing oscillation, though the Thrust Vectoring provides much faster authority than aerodynamic surfaces at low speeds.

### The Problem: Control Authority at Zero Airspeed
Standard fixed-wing aircraft rely on the flow of air over control surfaces (Elevators, Rudders) to generate torque. The force generated is proportional to the square of airspeed ($V^2$).
*   **At Cruise Speed:** The Elevator is highly effective; small movements generate large pitch moments.
*   **At Zero Speed (Hover):** The Elevator generates **zero force**. A standard Plane controller would simply saturate the servo and fail to prevent the nose from dropping.

### The Solution: Vectoring as a Virtual Elevator
We treat **Thrust Vectoring as an extension of the Elevator**.
*   **The Continuum:** A single "Pitch Lever" manages both actuators.
    *   The first half of the lever's travel moves the physical **Elevator**.
    *   Once the Elevator saturates (or reaches a set split point), the lever continues, seamlessly activating the **Thrust Vectoring**.
*   **The Equilibrium:**
    *   **In Calm Air (0 m/s):** The controller demands Pitch Up to counter the nose-heavy weight. The Elevator saturates, and the Motors tilt Up (e.g., to 60°) to provide vertical lift.
    *   **In Wind (5 m/s):** The Airspeed makes the Elevator effective. The Pitch Demand drops. The Motors rotate back towards Forward (90°). The blimp flies "on the wing," achieving high efficiency.

---

## 3. Airframe & Actuator Configuration

### Physical Layout
*   **Lift/Buoyancy:** Aerostatic hull (95% buoyant).
*   **Aerodynamic Surfaces:** Elevator and Rudder.
*   **Propulsion:** Two main motors on a rotatable shaft.

### Thrust Vectoring Geometry (Actuator Mapping)
The motor mount is capable of **270° of rotation**. We define the angles relative to the airframe body:
*   **+90° (Forward):** **Standard Cruise Position.** Motors push the blimp forward.
*   **0° (Vertical Up):** **Hover / Max Lift.** Motors push the blimp straight up. Used for VTOL and extreme Pitch-Up moments.
*   **-45° (Braking Limit):** **Braking Limit.** The motors point back and up. (Note: Mechanical/Calibration range extends to -90°, but software is clamped at `BLIMP_MAX_REVERSE_ANGLE`).
*   **+180° (Vertical Down):** **Dive / Descent.** Motors push the blimp straight down. Used for extreme Pitch-Down moments.

### Servo Calibration & Trim Strategy
To ensure precise control around the critical Hover state, we utilize the standard Servo Trim functionality to lock the **0° (Vertical)** position.

*   **Servo Range:** The physical servo moves from Minimum PWM to Maximum PWM.
*   **Calibration Points:**
    *   **MIN (Trim Low):** Corresponds to **-90° (Reverse)**.
    *   **TRIM (Midpoint):** Corresponds to **0° (Vertical Up)**. This provides a hardware-calibrated "Home" position for Hover.
    *   **MAX (Trim High):** Corresponds to **+180° (Down)**.
*   **Interpolation Implications:**
    *   Because the physical range is split at 0° (Vertical), we must use **Asymmetric Interpolation**.
    *   **Forward Range (0° to +180°):** Interpolates between `TRIM` and `MAX` PWM values.
    *   **Reverse Range (0° to -90°):** Interpolates between `TRIM` and `MIN` PWM values.
    *   *Note:* The "Forward Flight" position (+90°) is now effectively "Halfway" between TRIM and MAX.

---

## 4. The "Split-Range" Control Strategy

To implement this without rewriting the core PID controllers, we utilize a **Split-Range Mixer** that sits *downstream* of the autopilot logic.

### The Concept
The ArduPlane Pitch Controller outputs a generic `Pitch_Demand` signal. We map this single signal across our two actuators.

1.  **The "Split Point":** We define a threshold (represented by `BLIMP_MIXER_SPLIT_THRESHOLD`) that represents the transition from Aerodynamic Control to Powered Vector Control.
2.  **Range 1 (0% to Split%): The Aerodynamic Regime.**
    *   Used for small corrections and high-speed flight.
    *   **Action:** The **Elevator** moves from Neutral to Full Deflection.
    *   **Vectoring:** Remains at **+90° (Forward)**.
3.  **Range 2 (Split% to 100%): The Powered Regime.**
    *   Used for large corrections and low-speed/hover flight.
    *   **Action:** The **Elevator** holds at Full Deflection (Saturated).
    *   **Vectoring:** The motors rotate from **+90° (Forward)** towards **-45° (Braking Limit)** (for Pitch Up) or **+180° (Down)** (for Pitch Down).

### Synergy with Gain Scheduling & Energy Balance
ArduPlane inherently includes a `surface_speed_scaler` that scales PID output based on airspeed ($Scaler \propto 1/V^2$).
*   **At High Speed:** The scaler is small. The PID output stays within the 0-Split% range. **Only the Elevator moves.**
*   **At Low Speed:** The scaler is large. A small pitch error results in a massive PID output (100% or more). This automatically pushes the demand past the Split Point, engaging the **Thrust Vectoring**.
*   **Energy Balance Synergy:** This design leverages the TECS "Pitch Down to Accelerate" logic. When the blimp needs forward speed, TECS reduces pitch demand. This naturally "unwinds" the motor vectoring from Vertical (0°) towards Forward (90°), perfectly aligning the physical actuator with the energy management goals.

---

## 5. Implementation Details

### A. Attitude Limits vs. PID Effort
We must distinguish between the *Aircraft Attitude* and the *Control Effort*.

*   **Attitude Limit (`PTCH_LIM_MAX_DEG`):**
    *   Sets the maximum physical pitch angle the autopilot may command.
    *   **Recommendation:** Set "Reasonably High" (e.g., **45° to 60°**) to ensure good transient response.
    *   **Role:** Allows the P-Term to generate an initial "Kick" (large error) to rotate motors quickly during transients, preventing reliance solely on I-Term windup.
*   **PID Control Effort (The "Split"):**
    *   **Integrator Role:** The I-Term (`PTCH_RATE_I`) handles the steady-state load. Even if Pitch Error is 0 (holding 45°), the Integrator will wind up to hold the motors at the necessary lift angle.
    *   **Split Logic:** We intercept the **0-100% PID Effort** signal.
        *   **0 to Split% Effort:** Drives Elevator.
        *   **Split% to 100% Effort:** Drives Vectoring.

### B. Servo Function Mapping (Non-Intrusive Integration)
To keep the adaptation clean, we will **not** assign the standard `Elevator` function to any physical pin. Instead, we will use `Scripting` functions to drive the hardware.

*   **Logical Input:** The code reads the internal `k_elevator` channel (driven by the PID).
*   **Physical Outputs:**
    *   **Real Elevator Servo:** Assign parameter `SERVOn_FUNCTION` to `94` (**Scripting1**).
    *   **Tilt Mechanism Servo:** Assign parameter `SERVOn_FUNCTION` to `95` (**Scripting2**).
*   **The Code:** Our modified `Plane::set_servos()` will write the mixed results to `k_scripting1` and `k_scripting2`.

### C. The Signal Mixer Logic (`ArduPlane/servos.cpp`)
We intercept the calculated pitch demand and apply the split-range logic with explicit software constraints.

**Pseudocode Mixer:**
```cpp
// In Plane::set_servos()

// 1. Get the standard PID demand (-4500 to +4500)
// This is what the Autopilot "thinks" the elevator is doing.
float pitch_demand = SRV_Channels::get_output_scaled(SRV_Channel::k_elevator);

// 2. Define Split Threshold (e.g., 2250 is 50% of 4500)
// Value defined by BLIMP_MIXER_SPLIT_THRESHOLD constant or parameter.
const float split_threshold = 4500.0f * BLIMP_MIXER_SPLIT_THRESHOLD;
float elevator_pwm_out = 0.0f; // To be sent to Scripting1
float vector_angle_out = 90.0f; // To be sent to Scripting2 (Default Forward)

// 3. Process Pitch UP (Positive)
if (pitch_demand >= 0) {
    if (pitch_demand <= split_threshold) {
        // Stage 1: Elevator Only (0..Split% demand)
        // Map 0..split -> 0..4500 (Full Elevator Throw)
        elevator_pwm_out = (pitch_demand / split_threshold) * 4500.0f;
        vector_angle_out = 90.0f; // Remain Forward
    } else {
        // Stage 2: Elevator Saturation + Vectoring (Split%..100% demand)
        elevator_pwm_out = 4500.0f; 
        
        // Map remaining split..4500 -> 90..-45 degrees tilt
        float remainder = pitch_demand - split_threshold; 
        float range = 4500.0f - split_threshold;
        float fraction = remainder / range; // 0.0..1.0
        
        // Linear Interpolation: 90 - (Fraction * 135)
        vector_angle_out = 90.0f - (fraction * 135.0f);
    }
}
// 4. Process Pitch DOWN (Negative)
else { // pitch_demand < 0
    float abs_demand = -pitch_demand;
    if (abs_demand <= split_threshold) {
        // Stage 1: Elevator Only
        elevator_pwm_out = -(abs_demand / split_threshold) * 4500.0f;
        vector_angle_out = 90.0f;
    } else {
        // Stage 2: Elevator Saturated + Vectoring Down
        elevator_pwm_out = -4500.0f;
        float remainder = abs_demand - split_threshold;
        float range = 4500.0f - split_threshold;
        float fraction = remainder / range;
        
        // Map 90 -> 180 (Down) -> Range: 90 degrees
        vector_angle_out = 90.0f + (fraction * 90.0f);
    }
}

// 5. Software Constraints (Current Project Policy)
// Clamp the vector output to the defined operational range
vector_angle_out = constrain_float(vector_angle_out, BLIMP_MAX_REVERSE_ANGLE, 180.0f);

// 6. Final Output
// Write to the "Scripting" channels which are mapped to physical pins
SRV_Channels::set_output_scaled(SRV_Channel::k_scripting1, (int16_t)elevator_pwm_out);

// Convert Angle to PWM for the Tilt Servo using Asymmetric Trim (0 deg = TRIM)
int16_t tilt_pwm;
if (vector_angle_out >= 0) {
    // Forward/Down Range (0 to +180) -> Map to [TRIM..MAX]
    float pct = vector_angle_out / 180.0f;
    tilt_pwm = trim_pwm + (pct * (max_pwm - trim_pwm));
} else {
    // Backwards Range (0 to -90) -> Map to [TRIM..MIN]
    float pct = abs(vector_angle_out) / 90.0f;
    tilt_pwm = trim_pwm - (pct * (trim_pwm - min_pwm));
}
SRV_Channels::set_output_scaled(SRV_Channel::k_scripting2, tilt_pwm);
```

### D. TECS Integration & Braking
Standard ArduPlane TECS (Total Energy Control System) uses Pitch to manage Airspeed.
*   **The "Overspeed" Case:** If the blimp is too fast, TECS commands **Pitch Up** to trade kinetic energy for altitude.
*   **The Vectoring Synergy:**
    *   TECS demands High Pitch Up -> Mixer sees High Demand.
    *   Mixer rotates motors towards **-45° (Braking Limit)**.
    *   **Result:** We get "Active Braking" combined with the standard Aerodynamic Braking (Drag). This perfectly aligns with TECS philosophy: we are maximizing drag/reverse thrust to reduce energy.
*   **Modifications:**
    *   **Parameter Constraint:** In `ArduPlane/Parameters.cpp`, change the `AIRSPEED_MIN` range definition to allow **0**.
    *   **Logic Floor:** In `libraries/AP_TECS/AP_TECS.cpp`, change the hardcoded `_TAS_state` floor in `_update_speed` from `3.0f` to **0.0f**.
    *   **Safety Check:** When removing the floor, add `MAX(_TAS_state, BLIMP_TECS_SAFE_MIN_SPEED)` to division operations (like kinetic energy limits) to preserve stability and prevent division-by-zero crashes.
    *   **Underspeed Protection:** By setting `AIRSPEED_MIN = 0`, we mathematically prevent the system from ever detecting an "Underspeed" condition (since speed cannot be less than 0). This effectively **disables** the standard logic that would force a pitch-down dive to recover speed.

### E. Takeoff Mode & Hardcoded Constraints
To support `TAKEOFF` mode without the plane pitching down (expecting stall), we must modify several hardcoded assumptions in the codebase.

*   **1. `AIRSPEED_MIN` Parameter Clamp:**
    *   **Location:** `ArduPlane/defines.h` and `Parameters.cpp`
    *   **Issue:** `AIRSPEED_MIN` is constrained to `5` m/s by the `MIN_AIRSPEED_MIN` macro.
    *   **Fix:** Change `#define MIN_AIRSPEED_MIN 5` to **0** in `ArduPlane/defines.h`.
*   **2. TECS Hardcoded Minimum:**
    *   **Location:** `libraries/AP_TECS/AP_TECS.cpp` (`_update_speed` function)
    *   **Issue:** TECS has a hardcoded floor of `3.0 m/s` for `_TAS_state`.
    *   **Fix:** Change this constant to `0.0f`.
*   **3. Takeoff Pitch Suppression:**
    *   **Location:** `ArduPlane/takeoff.cpp` (`takeoff_calc_pitch`)
    *   **Issue:** Pitch is suppressed until `TKOFF_ROTATE_SPD` is reached.
    *   **Fix:** Set `TKOFF_ROTATE_SPD` to **0**.
    *   **Verification:** If Rotate Speed is 0, TECS takes over immediately. Since `min_airspeed` is 0, TECS should command full pitch up (Climb) immediately.

### F. Airspeed & Navigation Assumptions (`libraries/AP_NavEKF3`)
*   **Zero Airspeed:**
    *   We must ensure `AP_NavEKF3` allows the estimated airspeed to drop to zero without resetting.
*   **Infinite Gain Protection:**
    *   The `surface_speed_scaler` can grow infinitely large as speed approaches zero.
    *   **Fix:** In `ArduPlane/servos.cpp`, **clamp** the scaler to a maximum value `BLIMP_MAX_SPEED_SCALER` (e.g., 4.0x).
*   **Negative Speed Handling:**
    *   **Is it allowed?** Yes. Since `min_airspeed = 0`, the system will simply read negative speed as "0" or "Low" (sensor dependent) and will not Stall-Prevent (Pitch Down).
    *   **Heading Instability (Nav Modes):** In AUTO/RTL/GUIDED, standard L1 Navigation assumes `GroundSpeed Vector` matches `Heading`. Drifting backward might cause the controller to command a turn to "fix" the heading.
    *   **FBWA/FBWB (Stabilized Modes):** The "Turn Around" logic is inactive. Drifting backward is perfectly safe and stable in these modes.

### G. Tuning & Failsafes

*   **Integrator Tuning (`PTCH_RATE_I`):**
    *   Crucial for the "Hover Equilibrium". The I-term will "learn" the necessary vector angle to hold the nose up against gravity.
*   **Servo Slew Rate:**
    *   Use `SERVOx_RATE` parameters to limit the speed of the Tilt Servo to prevent reaction torque oscillations.
*   **Airspeed Sensor Failsafe:**
    *   If the Airspeed Sensor fails, the `surface_speed_scaler` will default to 1.0 (Cruise).
    *   **Mitigation:** Set `AIRSPEED_MIN` and `AIRSPEED_MAX` parameters carefully.

### H. Landing Parameters
To ensure smooth auto-landing behavior using the Vectoring Flare logic, specific standard ArduPlane parameters must be tuned:
*   **`LAND_PITCH_DEG`:** Set to **15°** (or similar positive value). This defines the target pitch for the Flare. The Mixer will translate this high pitch demand into Vectoring (Lift).
*   **`LAND_FLARE_ALT`:** Set slightly higher than typical planes (e.g., **5m**). This accounts for the servo slew rate time required to rotate motors from Forward to Up.
*   **`LAND_FLARE_SEC`:** Alternative to altitude; defines flare trigger time.
*   **`LAND_SLOPE_RCALC`:** Ensure slope recalculation is enabled (e.g., **2.0m**) to smooth the glide slope as speed decreases.

### I. Airspeed Sensor Analysis (Requirement vs. Benefit)
*   **Recommendation:** **Highly Recommended for Responsiveness.**
*   **Benefit with Sensor:** The `surface_speed_scaler` reacts *instantly* to low airspeed. This allows the P-Term to command motor vectoring immediately when a gust hits or the blimp slows down, ensuring tight control.
*   **Behavior without Sensor:** The system must rely on "Synthetic Airspeed," which may be inaccurate in hover. The P-Term will likely be too weak (Low Scaler), and the system will rely on the **Integrator (I-Term)** to slowly wind up and activate the vectoring.
*   **Trade-off:** Without a sensor, the blimp will fly and hold altitude (via Integrator), but control will be "mushy" and less responsive to gusts compared to the crisp reaction provided by a Pitot tube.

### J. Navigation Logic (Yaw-Turn Strategy)
ArduPlane's coordinated turn logic typically relies on **Actual Roll** to calculate Yaw Rate (`AP_YawController`). Since our blimp cannot roll, this standard logic would fail to command a turn (Yaw Demand = 0).

**The Solution: "Hotwiring" the Turn Command**
We must "trick" the autopilot into thinking it is banking so that it generates a coordinated yaw command, which we then use as our primary steering signal.

**Required Parameter Changes:**
*   **`ROLL_LIMIT_DEG` = 45:** Allow the autopilot to command a "Phantom Bank." It will try to bank (move ailerons) to turn.
*   **`KFF_RDDRMIX` = 1.0 (or higher):** This is the "Hotwire." It feeds the Aileron Command (from the Phantom Bank) directly into the Rudder.
    *   *Logic Flow:* Nav wants turn -> Commands Bank (Aileron) -> Mixer sees Aileron -> **Moves Rudder** -> Blimp Yaws.
*   **`RUDDER_ONLY` = 1:** Helps prioritize rudder for heading control in some modes.

**Alternative (Code Change):**
Override `calc_nav_yaw_coordinated` in `Attitude.cpp` to explicitly calculate yaw rate from lateral acceleration, bypassing the bank angle check entirely.

### K. Weathervaning & Wind Estimation
*   **FBWA (Stabilize):** ArduPlane does **not** rigidly hold heading in FBWA when sticks are centered; it only damps rates. This allows the blimp to naturally weathervane into the wind without fighting the controller.
*   **Wind Estimation:** Without rolling/banking, the EKF's wind estimation might be slow to converge if no airspeed sensor is present.
    *   **With Pitot Tube:** The system can estimate wind by comparing `Airspeed` vs. `GroundSpeed`.
    *   **Without Pitot Tube:** Wind estimation relies on banking maneuvers (which we can't do).
    *   **Conclusion:** This reinforces the requirement for a physical **Airspeed Sensor** to ensure accurate wind data, which helps the TECS and Navigation controllers.

---

## 6. Case Studies: Validation of Design

### Case 1: TAKEOFF Mode
*   **Configuration:** `TKOFF_THR_MINACC = 0`, `TKOFF_ROTATE_SPD = 0`.
*   **Behavior:** Upon arming, the target pitch (e.g. 15°) creates a large error. Because airspeed is 0, the gain scaler is maxed. The Mixer saturates the Elevator and immediately rotates the **Motors to Vertical (Up)**. The blimp lifts off nose-high without dragging its tail.

### Case 2: LAND Mode (Auto-Flare)
*   **Configuration:** `LAND_PITCH_DEG = 15`, `LAND_FLARE_ALT = 5m`.
*   **Behavior:** At flare altitude, ArduPlane commands a pitch-up. Ground speed is very low. The Elevator saturates. The **Motors Tilt Up**.
*   **The Outcome:** The blimp uses vertical thrust to "hover-settle" onto the ground. Instead of stalling onto the runway, it performs a soft, powered vertical descent at the point of touchdown.

### Case 3: OVERSPEED (TECS Active Braking)
*   **Behavior:** If the blimp exceeds target airspeed (e.g. in a dive), TECS commands **Pitch Up** to bleed energy.
*   **The Outcome:** The high pitch demand pushes the motors past vertical towards the **-45° operational limit**. The blimp utilizes active reverse thrust to brake in mid-air, perfectly fulfilling the TECS energy-reduction goal.

### Case 4: Navigation (Yaw-Turn Logic)
*   **Problem:** Standard Plane navigation relies on Bank-to-Turn (Roll), but the Blimp has **No Roll Control**.
*   **Recommendation:** This requires a specific code intervention to decouple `nav_roll` from `nav_yaw` for "Flat Turns." (To be implemented).

### Case 5: Hover in Wind (The "Kite" Effect)
*   **Configuration:** **Airspeed Sensor Installed**.
*   **Behavior:** Wind 5 m/s. Blimp stationary (Ground Speed 0).
*   **Logic:** The Pitot tube measures 5 m/s. The `surface_speed_scaler` drops (Fins are effective). PID Pitch Demand decreases.
*   **Outcome:** The Mixer rotates motors **Forward (90°)**. The Elevator manages the pitch. The motors provide forward thrust to hold position against the wind. The blimp flies "on the wing" efficiently, verifying the primary efficiency goal of the project.

### Case 6: Transition from Hover to Cruise
*   **Requirement:** Transitioning from static hover to forward flight.
*   **Mechanism:** When forward speed is demanded, TECS commands a **Pitch Down** to accelerate.
*   **Outcome:** The Mixer interprets this reduced pitch demand as a command to rotate the motors from **Vertical (0°)** towards **Forward (90°)**. As forward speed builds, the fins gain authority and the motors continue to "unwind" towards neutral forward flight. The energy controller naturally handles the actuator transition.

---

## 7. Implementation Summary

### Consolidated Parameter Configuration
This checklist defines the critical parameters required to enable the "Blimp Flight Physics" without modifying the C++ codebase (except where noted).

| Parameter | Value | Purpose |
| :--- | :--- | :--- |
| **Servo Output** | | |
| `SERVOn_FUNCTION` (Elevator Pin) | `94` | Maps physical elevator to **Scripting1** (Output of Mixer). |
| `SERVOn_FUNCTION` (Tilt Pin) | `95` | Maps physical tilt servo to **Scripting2** (Output of Mixer). |
| `SERVOx_RATE` (Tilt Servo) | Low (e.g., 50) | Limits slew rate to prevent rotational inertia oscillation. |
| **Blimp Specific (New)** | | |
| `B_PTCH_SPLIT` | `0.5` | **New Parameter:** Ratio of pitch demand assigned to elevator vs motors (0.0 to 1.0). |
| **Pitch Control** | | |
| `PTCH_LIM_MAX_DEG` | `45` - `60` | Allows high pitch angles for Hover/Braking transients. |
| `PTCH_RATE_I` | High | Tuned to hold the nose up against gravity (HTA compensation). |
| **Navigation & Steering** | | |
| `ROLL_LIMIT_DEG` | `45` | Enables "Phantom Bank" commands from the Nav Controller. |
| `KFF_RDDRMIX` | `1.0`+ | Feeds "Phantom Bank" effort directly to Rudder for yaw turns. |
| `RUDDER_ONLY` | `1` | Prioritizes rudder for heading control. |
| **Takeoff & Landing** | | |
| `TKOFF_THR_MINACC` | `0` | Disables launch acceleration check (Takeoff from stationary). |
| `TKOFF_ROTATE_SPD` | `0` | Disables pitch suppression; allows immediate vectoring. |
| `LAND_PITCH_DEG` | `15` | Target pitch for landing flare (triggers vectoring). |
| `LAND_FLARE_ALT` | `5m` | Higher flare altitude to allow time for motor tilt. |
| `LAND_SLOPE_RCALC` | `2.0m` | Smooths approach path. |
| **Safety** | | |
| `ARMING_CHECK` | *Custom* | Disable "Min Airspeed" or "Stall" checks if they persist. |

### Consolidated Required Code Changes
These are the specific C++ modifications required in the `ArduPlane/` directory.

#### 0. Define Project Constants
In `ArduPlane/Plane.h` (or a dedicated configuration header), define these constants to avoid magic numbers:
*   `BLIMP_MAX_REVERSE_ANGLE` = **-45.0f**
*   `BLIMP_MAX_SPEED_SCALER` = **4.0f**
*   `BLIMP_TECS_SAFE_MIN_SPEED` = **3.0f**
*   `BLIMP_MIXER_SPLIT_THRESHOLD_DEFAULT` = **0.5f** (Fallback if parameter is missing)

#### 1. Modify `ArduPlane/defines.h` and `Parameters.cpp`
*   Change `#define MIN_AIRSPEED_MIN 5` to **0** in `ArduPlane/defines.h`.
*   Update `AIRSPEED_MIN` comment range in `Parameters.cpp` to allow 0.
*   **Add New Parameter:** Define `B_PTCH_SPLIT` in `Parameters.cpp` (Range 0.0 to 1.0).

#### 2. Modify `libraries/AP_TECS/AP_TECS.cpp`
*   In `_update_speed()`, change the hardcoded floor of `_TAS_state` from `3.0f` to **0.0f**.
*   **Critical:** Add `MAX(_TAS_state, BLIMP_TECS_SAFE_MIN_SPEED)` to any division operations (e.g., in `_update_speed_demand` and `_update_pitch`) to prevent division-by-zero crashes.

#### 3. Modify `ArduPlane/servos.cpp` (The Mixer)
*   In `Plane::set_servos()`:
*   **Clamp Scaler:** Constrain `surface_speed_scaler` to max `BLIMP_MAX_SPEED_SCALER`.
*   **Intercept:** Read `k_elevator` output.
*   **Split Logic:** Apply the split based on `B_PTCH_SPLIT` parameter (or `BLIMP_MIXER_SPLIT_THRESHOLD_DEFAULT`).
*   **Interpolate:** Map the Vectoring demand to `k_scripting2` using the **Asymmetric Trim** logic (0° = TRIM).
*   **Enforce Limits:** Apply `constrain_float(vector_angle_out, BLIMP_MAX_REVERSE_ANGLE, 180.0f)`.
*   **Output:** Write modified elevator to `k_scripting1`.

#### 4. Modify `ArduPlane/Attitude.cpp` (Optional but Recommended)
*   In `calc_nav_yaw_coordinated()`:
*   Add a check for the Blimp airframe type.
*   Force `yaw_rate_demand` calculation based on lateral acceleration, ignoring the bank angle check.
*   *Note: This replaces the "Phantom Bank" parameter trick with a cleaner, native solution.*