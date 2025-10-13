# **Software Design Document: SFC (Secondary Flight Controller)**

**Firmware Version:** 1.4 (ESP32-S3 Implementation) **Target Hardware:** ESP32-S3 **Primary Role:** "Muscle" unit in a distributed flight control system. Acts as a smart SBUS-to-DShot signal converter and mixer.

---

## **1.0 System Architecture Overview**

This firmware is designed for one of six identical **Secondary Flight Controller (SFC)** units on a custom 24-motor heavy-lift H-frame aircraft.

The overall aircraft architecture is a decoupled, multi-controller system designed for maximum redundancy and specialization:

* A **Primary Flight Controller (PFC)** running ArduPilot provides overall attitude stabilization (pitch, roll, yaw) and high-level commands.  
* A **Thrust Vectoring Controller (TVC)** or "Brain" with its own IMU calculates all logic related to thrust vectoring for translation maneuvers.  
* **Six SFC units** (running this firmware) act as the "muscle," translating commands from both the PFC and the TVC into DShot signals for the motors.

This document pertains **only** to the software for a single SFC unit.

---

## **2.0 Core Responsibilities**

This firmware's primary responsibilities are to:

* Drive **4 DShot ESCs** using the ESP32's **RMT peripheral**.  
* Listen for commands simultaneously on two independent **SBUS buses**.  
* Perform the final motor mix, combining base stabilization throttle, a thrust compensation factor for vectoring, and thrust vectoring differentials.  
* Apply a non-linear **thrust curve** to the final motor command to ensure a linear thrust response from the motors.  
* Handle multiple safety and failsafe conditions, including signal loss and a commanded "all motors off" state.

---

## **3.0 Configuration**

The code is designed to be identical across all six SFC units. The only change required when flashing each unit is the `SFC_ID`.

* **`SFC_ID`**: A unique identifier from 0 to 5\. This ID is critical as it determines which SBUS channel (1-6) the unit listens to for its base throttle command from the PFC. The mapping of ID to physical position is defined in the code comments.  
* **Pin Definitions**: The GPIO pins for the 4 motor outputs (`MOTOR_PINS`) and the 2 SBUS inputs (`SBUS_A_RX_PIN`, `SBUS_B_RX_PIN`) are defined as constants and should be configured to match the physical hardware layout.  
* **Motor Mapping**: The logical-to-physical mapping of the 4 motors in the cluster (e.g., `MOTOR_FRONT_LEFT`) is defined as a constant. This must be verified against the physical wiring and motor spin directions to ensure the vectoring mix is applied correctly.

---

## **4.0 Communication Protocol (Inputs)**

The SFC receives all commands as raw integer values over two SBUS buses. These values are de-interpolated back into floating-point numbers for use in calculations. The SBUS range is configured for ArduPilot's output (**172-1811**).

### **SBUS Bus A (from ArduPilot PFC)**

* **Source:** Primary Flight Controller.  
* **Purpose:** Provides base throttle commands for attitude stabilization.  
* **Data:** The SFC reads one channel from this bus, determined by its `SFC_ID`. This channel contains the linear `base_throttle` (0.0 to 1.0) for the 4-motor cluster. The SFC also monitors channels 0-5 on this bus for the "All Motors Off" safety check.

### **SBUS Bus B (from TVC "Brain")**

* **Source:** Thrust Vectoring Controller.  
* **Purpose:** Provides commands for thrust vectoring maneuvers.  
* **Data:** The SFC reads three channels:  
  * `vector_pitch` (-1.0 to 1.0)  
  * `vector_roll` (-1.0 to 1.0)  
  * `thrust_compensation_factor` (e.g., 1.0 to 1.5)

---

## **5.0 Core Logic and Order of Operations (Main Loop)**

The main `loop()` executes the following sequence continuously:

1. **Data Reception:** Reads the latest data packets from both SBUS buses.  
2. **Safety & Failsafe Checks:**  
   * It first performs the **"All Motors Off"** check by iterating through the first 6 channels of SBUS Bus A. If all are below the `MOTOR_OFF_THRESHOLD` (300), it stops the motors and halts further execution for that loop cycle.  
   * It then checks the `failsafe` flag from Bus A. If the signal from the PFC is lost, it stops the motors and halts.  
   * It then checks the `failsafe` flag from Bus B. If the signal from the TVC is lost, it resets all vectoring commands to a safe, neutral state (`pitch=0`, `roll=0`, `factor=1.0`) and continues, allowing the aircraft to fly as a standard hexacopter.  
3. **Mixing Logic:**  
   * It applies the `thrust_compensation_factor` to the `base_throttle` to calculate the `compensated_throttle`.  
   * It applies the `vector_pitch` and `vector_roll` commands as a differential to the `compensated_throttle` to calculate the final linear thrust for each of the 4 motors.  
4. **Output Processing (Per-Motor):**  
   * The final linear thrust for each motor is **clamped** to a range of 0.0 to 1.0 to prevent saturation.  
   * The clamped value is then passed through a **low-pass filter** to smooth the output signal.  
   * The filtered, linear value is passed to the `thrust_to_dshot()` function, which applies the non-linear **thrust curve** to get the final DShot integer value (48-2047).  
   * This final DShot value is sent to the corresponding motor.  
5. **Periodic Logging:** Every `LOG_PERIOD` (2000ms), the unit prints a status line to the serial monitor containing key state variables and the calculated average loop frequency (Hz).

---

## **6.0 Initialization (`setup()`)**

The `setup()` function handles all one-time hardware and software initialization. It initializes the DShot drivers, the two SBUS receivers, and then calls the `arm_motors()` function. This function performs a two-stage, 3-second blocking sequence to safely arm the BLHeli ESCs and flush the motor filters before the main loop begins.

