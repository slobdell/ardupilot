# System Configuration Guide

This document provides a comprehensive guide to configuring the TVC (Thrust Vectoring Controller) and SFC (Secondary Flight Controller) firmware for different airframes. A correct configuration is critical for safe and stable flight.

## 1.0 Architectural Overview

The control system is distributed across two main microcontrollers, each with its own firmware and configuration:

1.  **The TVC (The "Brain"):** Runs on the ArduPilot-based flight controller. It is responsible for high-level decision-making, calculating target angles, and issuing generic, normalized commands.
2.  **The SFC (The "Muscle"):** Runs on the ESP32-based motor controllers. It is responsible for executing the TVC's commands, performing hardware-specific translations (like servo remapping), and driving the actuators.

Configuration requires setting parameters in **both** firmwares to match your specific airframe.

---

## 2.0 TVC Configuration

**File Location:** `ardupilot/ArduCopter/custom_main.h`

This file contains the high-level feature flags and system-wide parameters that define the TVC's behavior.

### 2.1 Master Feature Flags

These flags control the primary operating mode of the TVC.

-   `#define VTOL_MODE`:
    -   `true`: Enables the tilt-rotor VTOL logic, including the blending of hover and forward-flight control models.
    -   `false`: Enables the original 24-motor multicopter logic (differential thrust).

-   `#define OPEN_LOOP_SERVO_MODE`:
    -   `true`: **(For Servo Airframes Only)** Bypasses the IMU and PID controllers. The TVC calculates a target physical angle and converts it directly into a normalized command. This mode is simpler and avoids reliance on the IMU, but provides no feedback to correct for external forces.
    -   `false`: Enables the closed-loop, PID-based control system. This is required for the 24-motor multicopter and can be used for servo-based systems if feedback control is desired.

### 2.2 Physical Envelope Configuration

These constants define the TVC's understanding of the system's **intended maximum flight envelope**. These values are used to normalize the TVC's commands into a generic `-1.0` to `1.0` range.

-   `const float FORWARD_FLIGHT_PHYSICAL_ANGLE_DEG`:
    -   **Purpose:** Defines the maximum physical forward tilt angle (in degrees) the system is designed to achieve in forward flight.
    -   **Example:** `93.0f`

-   `const float REVERSE_FLIGHT_PHYSICAL_ANGLE_DEG`:
    -   **Purpose:** Defines the maximum physical reverse/negative tilt angle (in degrees) the system is designed to achieve.
    -   **Example:** `-10.0f`

### 2.3 Hover Stability Configuration

This constant limits the pilot's command authority in hover to ensure stability.

-   `const float MAX_TARGET_ANGLE_DEG`:
    -   **Purpose:** Defines the maximum tilt angle (in degrees) that the TVC will command in response to pilot stick input during hover. This is a stability limit, not a physical limit. It should be set to a value less than the physical limits.
    -   **Example:** `60.0f`

---

## 3.0 SFC Configuration

**File Location:** `led-drone-microcontrollers/caterpillar/motor-controller-unit/motor-controller-unit.ino`

This file contains the hardware-specific configuration for each of the "muscle" units.

### 3.1 Primary SFC ID

-   `#define SFC_ID`:
    -   **Purpose:** A unique identifier for each SFC, from `0` to `5`.
    -   **Critical:** This ID is used to map the SFC to the correct SBUS channels from the PFC for receiving its base throttle command. Each SFC on the airframe must have a unique ID.

### 3.2 SFC Operation Mode

-   `#define SFC_OPERATION_MODE`:
    -   **Purpose:** Sets the primary operational mode for the SFC. This must be aligned with the TVC's configuration.
    -   **Modes:**
        -   `SFC_MODE_MULTICOPTER`: For the 24-motor airframe. All actuators are motors, and it performs differential thrust.
        -   `SFC_MODE_VTOL`: For the tilt-rotor airframe. Actuators can be a mix of motors and servos.
        -   `SFC_MODE_PASSTHROUGH`: A generic mode that directly maps PFC SBUS inputs to actuator outputs.

### 3.3 Hardware-Specific Configuration

All hardware-specific setup is done in the `setup_sfc_config()` function.

-   `.actuator_types`:
    -   **Purpose:** An array that defines the physical type of actuator connected to each of the 4 output pins.
    -   **Values:** `ACTUATOR_MOTOR`, `ACTUATOR_SERVO`, `ACTUATOR_UNUSED`.

-   `.servo_functions`:
    -   **Purpose:** For servos, this defines their logical function.
    -   **Values:** `SERVO_FUNCTION_PITCH`, `SERVO_FUNCTION_ROLL`.

-   **Servo Mechanical Remapping:**
    -   `.servo_min_angle_deg` & `.servo_max_angle_deg`:
    -   **Purpose:** These arrays are the **most critical setting for servo-based airframes**. They tell the SFC how to translate the TVC's generic `-1.0` to `1.0` command into a real-world physical angle. You must measure your physical hardware and set these values.
    -   **Example:** For a servo whose physical range of motion is from -10 degrees to +93 degrees, you would set:
        ```cpp
        sfc_config.servo_min_angle_deg[1] = -10.0f;
        sfc_config.servo_max_angle_deg[1] = 93.0f;
        ```
    -   **Inverting Servo Direction:** To invert a servo's direction, simply swap the min and max values:
        ```cpp
        sfc_config.servo_min_angle_deg[1] = 93.0f; // Swapped
        sfc_config.servo_max_angle_deg[1] = -10.0f; // Swapped
        ```

---

## 4.0 Use Case Scenarios (Step-by-Step)

### Scenario 1: 24-Motor Multicopter (Closed-Loop)

This is the original configuration using differential thrust for vectoring.

1.  **TVC Settings (`custom_main.h`):**
    ```cpp
    #define VTOL_MODE false
    #define OPEN_LOOP_SERVO_MODE false
    ```
    *(The physical angle constants are not used in this mode but can be left as-is).*

2.  **SFC Settings (`motor-controller-unit.ino`):**
    -   Set the unique `#define SFC_ID` for each of the 6 units.
    -   Set the operation mode:
        ```cpp
        #define SFC_OPERATION_MODE SFC_MODE_MULTICOPTER
        ```
    -   The `setup_sfc_config()` function will automatically select the correct 4-motor configuration. No other changes are needed.

### Scenario 2: VTOL Tilt-Rotor (Open-Loop Servos)

This is the new configuration using servos for tilting.

1.  **TVC Settings (`custom_main.h`):**
    ```cpp
    #define VTOL_MODE true
    #define OPEN_LOOP_SERVO_MODE true

    // Set these to match the system's intended flight envelope
    const float FORWARD_FLIGHT_PHYSICAL_ANGLE_DEG = 93.0f;
    const float REVERSE_FLIGHT_PHYSICAL_ANGLE_DEG = -10.0f;
    ```

2.  **SFC Settings (`motor-controller-unit.ino`):**
    -   Set the unique `#define SFC_ID` for each unit.
    -   Set the operation mode:
        ```cpp
        #define SFC_OPERATION_MODE SFC_MODE_VTOL
        ```
    -   **Critically, you must configure the hardware layout in `setup_sfc_config()`:**
        ```cpp
        void setup_sfc_config() {
            #if SFC_OPERATION_MODE == SFC_MODE_VTOL
                sfc_config.mode = SFC_MODE_VTOL;

                // 1. Define which outputs are motors vs. servos
                sfc_config.actuator_types[0] = ACTUATOR_MOTOR;
                sfc_config.actuator_types[1] = ACTUATOR_SERVO;
                sfc_config.actuator_types[2] = ACTUATOR_SERVO;
                sfc_config.actuator_types[3] = ACTUATOR_UNUSED;

                // 2. Define the logical function of each servo
                sfc_config.servo_functions[1] = SERVO_FUNCTION_PITCH;
                sfc_config.servo_functions[2] = SERVO_FUNCTION_ROLL;

                // 3. Define the measured physical range of each servo
                sfc_config.servo_min_angle_deg[1] = -10.0f; // Pitch servo
                sfc_config.servo_max_angle_deg[1] = 93.0f;
                sfc_config.servo_min_angle_deg[2] = -45.0f; // Roll servo
                sfc_config.servo_max_angle_deg[2] = 45.0f;
            #endif
        }
        ```
