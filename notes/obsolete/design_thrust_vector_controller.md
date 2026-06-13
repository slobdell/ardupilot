SOFTWARE DESIGN DOCUMENT: TVC (Thrust Vectoring Controller \- The "Brain")

NOTE: I am looking at alternatives to the ESP32-S3, I found this F405 board for cheap with good IMU: “AERO SELFIE F405 Drone Flight Controller, 2-6S LiPo, BMI088 IMU, SPL06 Barometer, OSD, 6 UART, 10 PWM, BEC 5V/9V, MicroSD Slot, Supports Betaflight, Ardupilot, INAV” OR “H743 Flight Controller for Drones \- Dual IMU, 7 UART, 10 PWM, ArduPilot & PX4 Support” (see [link](https://aeroselfie.myshopify.com/products/flight-controller-h743-for-drones))

NOTE: Use Mahoney algorithm instead of madgwick for IMU

Firmware Version: 1.5 Target Hardware: ESP32-S3 Primary Role: The dedicated "brain" for all translation and thrust vectoring maneuvers within a distributed flight control system.

1.0 SYSTEM ARCHITECTURE OVERVIEW

This firmware is for the Thrust Vectoring Controller (TVC), which is one of three distinct controller types in a custom 24-motor aircraft. The overall architecture consists of:

* A Primary Flight Controller (PFC) running ArduPilot.  
* One TVC (running this firmware).  
* Six Secondary Flight Controllers (SFCs) acting as motor drivers.

This document pertains ONLY to the TVC software.

2.0 CORE RESPONSIBILITIES

This firmware's primary responsibilities are to:

* Read an onboard IMU and compute a stable attitude estimate for the mechanically linked motor pods.  
* Listen for high-level pilot commands from the PFC on a primary SBUS bus (Bus A).  
* Calculate the target vectoring angle required to achieve the commanded translation.  
* Run a full cascaded PID control loop to move the motor pods to the target angle smoothly and accurately.  
* Dynamically adjust PID gains based on commanded thrust using a Gain Scheduling algorithm.  
* Perform preemptive saturation checks to ensure all vectoring commands are physically achievable by the motors.  
* Calculate a thrust compensation factor to maintain altitude during vectoring maneuvers.  
* Broadcast the final, safe vectoring commands to the SFCs on a secondary SBUS bus (Bus B).

3.0 CONFIGURATION

The firmware is configured via a set of constants defined at the top of the sketch.

* HARDWARE PINS: Defines the GPIO pins for I2C communication with the IMU and the two UARTs used for SBUS A (input) and SBUS B (output).  
* IMU & FILTER CONSTANTS: Defines the I2C address, registers, sample rate, and filter cutoff frequencies. These values are based on the user's previous, tested flight controller for consistency. The calibrated accelerometer and gyroscope offsets are also defined here.  
* PID GAINS: Defines two sets of PID gains. The gains for the outer "Angle" PID loops are fixed. The gains for the inner "Rate" PID loops have two sets, a \_LOW and a \_HIGH, which are used as the endpoints for the linear interpolation in the gain scheduling algorithm.  
* SAFETY LIMITS: A MAX\_TARGET\_ANGLE\_DEG constant defines the maximum allowable physical tilt for the motor pods, used for input shaping.

4.0 COMMUNICATION PROTOCOL (INPUTS & OUTPUTS)

* INPUTS (SBUS Bus A from PFC): The TVC listens to 9 channels from the PFC. Channels 7, 8, and 9 provide the raw pilot commands for Thrust, Forward, and Lateral motion, respectively. It also reads channels 1 through 6, which contain the base throttle values for the six conceptual hexacopter motors, using this data for its saturation check.  
* OUTPUTS (SBUS Bus B to SFCs): The TVC transmits a 3-channel SBUS frame to all six SFCs, containing the final calculated `vector_pitch`, `vector_roll`, and `thrust_compensation_factor`.  
* DATA SCALING: All SBUS integer values are de-interpolated from the ArduPilot range of 172-1811 to floats upon reception, and encoded back to that range on transmission.

5.0 CORE LOGIC & ORDER OF OPERATIONS (MAIN LOOP)

The main loop executes the following sequence continuously:

1. DATA RECEPTION: Reads the latest data packet from SBUS Bus A.  
2. SAFETY & FAILSAFE CHECKS: Checks if the PFC has commanded all 6 motors to be off (values < 300). If so, it resets all PIDs and filters, sends neutral commands on Bus B, and waits. It continues to call `read_imu()` during this inactive state to keep the attitude filter "warm". If the `failsafe` flag from Bus A is active, it performs the same reset and wait routine.  
3. INPUT PROCESSING: De-interpolates all 9 command channels from SBUS A into their respective floating-point variables.  
4. INPUT SHAPING (ALTITUDE PRIORITY): It prioritizes altitude control by budgeting thrust. The logic calculates the maximum available thrust for horizontal movement after accounting for the pilot's vertical thrust command. If the pilot's combined `forward` and `lateral` commands exceed this budget, they are scaled back proportionally to ensure the total commanded thrust vector does not exceed 1.0, preventing altitude loss during aggressive maneuvers.
5. GAIN SCHEDULING: Calculates the 3D vector magnitude of the pilot's command and uses this value to linearly interpolate the P, I, and D gains for the two inner "rate" PID controllers for the current loop cycle.  
6. IMU & STATE UPDATE: Calls `read_imu()` to get the latest `current_pitch`, `current_roll`, and their rates from the sensor and Madgwick filter.  
7. CASCADED PID CONTROL: Calculates the `target_pitch_deg` and `target_roll_deg` using `atan2` trigonometry. These are fed into the outer "angle" PID loops. The output of these loops (a target angular rate) is then filtered before being fed as the setpoint to the inner "rate" PID loops.  
8. SATURATION CLIPPING: Calls the `clip_vectors_for_saturation` function on the PID outputs. This function uses the 6 base throttle values from the PFC to calculate the available headroom and clips the vector commands symmetrically. It then updates the static `pitch_saturated` and `roll_saturated` flags that are fed back into the PID controllers on the next loop cycle.  
9. THRUST COMPENSATION: Calculates the `thrust_factor` based on the CURRENT IMU angles, applying safety clamps to both the input angle and the final factor to prevent IMU failure from causing a throttle spike.  
10. TRANSMISSION: Encodes the final, clipped vector commands and the final, clamped thrust factor into SBUS integer values and transmits them on Bus B.  
11. PERIODIC LOGGING: Every 2 seconds, prints a detailed, multi-line status report of all key system variables to the serial monitor for troubleshooting.

6.0 INITIALIZATION (setup())

The setup function handles all one-time hardware and software initialization. It initializes the IMU, the Madgwick filter, the SBUS receiver (Bus A) and transmitter (Bus B), and all PID and sensor filters. It also applies the D-term filter to the rate PIDs if the `FILTER_D` flag is true.

---
## 7.0 CHANGE LOG & UPDATES (Blimp Adaptation)

### 7.1. Full 270-Degree Vectoring Range
*   **Modification:** The physical angle limit constant `MAX_TARGET_ANGLE_DEG` in `TVC_Core.h` was updated from **89.0** to **180.0**.
*   **Reason:** The original limit clamped the servo output, preventing the vectoring mechanism from pointing downwards (180°). This change allows the full 270° range (-90° Back to +180° Down).
*   **Behavior:**
    *   **Forward Stick (90°):** Maps to Horizontal Forward.
    *   **Reverse Throttle (180°):** Maps to Vertical Down.

### 7.2. Bidirectional Throttle Logic
*   **Input Mapping:** The `QuadPlane::get_pilot_throttle` function was modified to bypass the expo curve for the Blimp, passing a linear 0..1 signal.
*   **Internal Processing:** `AP_Motors6DOF` uses `get_throttle_bidirectional()` to map the 0..1 input (where 0 is Low Stick) to a -1..1 command (where -1 is Low Stick).
*   **Spool Logic Fix:** The `AP_MotorsMulticopter` spool logic was updated to use the **absolute magnitude** (`fabsf`) of the bidirectional throttle. This prevents the motors from cutting off (going to Idle) when the throttle stick is at minimum (-1.0 Thrust), ensuring they spin at full power for reverse vectoring.
*   **Low-Throttle Idle Fix:** `QuadPlane::hold_stabilize` was updated to bypass the `GROUND_IDLE` enforcement at zero throttle for reversible setups, allowing `THROTTLE_UNLIMITED` state even at minimum stick.

### 7.3. Unidirectional Motor Support for Reversible Thrust
*   **Concept:** "Reverse Thrust" for this airframe means "Spin Motors + Point Down", not "Spin Motors Backwards".
*   **Implementation:** `AP_Motors6DOF` was updated to pass the **absolute value** of the calculated thrust to the Lift Motors.
    *   **Command -1 (Reverse):** Motors receive `abs(-1) = 1` (Full Power). TVC receives `-1` (Tilt Down).
    *   **Command +1 (Forward):** Motors receive `abs(+1) = 1` (Full Power). TVC receives `+1` (Tilt Up).

### 7.4. Manual Override Configuration
*   **Channel:** Re-mapped to **RC8** (Channel 8).
*   **Threshold:** Active when PWM > **1200**.
*   **Logic:** Updated to use the same **Trim-Centric** PWM mapping as the auto mode, ensuring consistent behavior where neutral stick equals neutral servo trim.
*   **Direction:** Manual pitch input is inverted in code to align "Stick Forward" with "Tilt Forward".

