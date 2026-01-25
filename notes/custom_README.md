# ArduPilot Workhorse Firmware for MicoAir H743

## 1. Project Vision

The goal of this project is to leverage a cheap, powerful flight controller (the MicoAir H743) as a generic "workhorse" for custom aircraft-related applications.

This firmware uses the production-grade ArduPilot ecosystem as a robust Hardware Abstraction Layer (HAL) and Real-Time Operating System (RTOS). This allows us to bypass the complexities of low-level hardware initialization, sensor filtering, and state estimation, and instead focus directly on implementing high-level application logic.

## 2. Core Architecture

The central architectural decision is to use a feature flag, `RUN_CUSTOM_LOOP`, to replace ArduPilot's main flight control loop with our own custom entry point.

This provides the best of both worlds:
- **ArduPilot's Stability:** The board boots up using ArduPilot's battle-tested initialization routines. All sensors are configured, calibrated, and fused by the EKF3 before our code runs.
- **Custom Application Logic:** Once initialized, the main scheduler hands control over to our custom `newMain()` function, which runs at the full 400Hz loop rate.

The hook point is located in `ArduCopter/mode.cpp`:
```cpp
// ArduCopter/mode.cpp
void Copter::update_flight_mode()
{
    // ...
#if RUN_CUSTOM_LOOP
    newMain();
#else
    flightmode->run();
#endif
}
```

## 3. Two-Mode Configuration Workflow

A key feature of this architecture is the ability to switch between a standard ArduPilot configuration mode and our custom application mode.

- **To Configure/Calibrate:**
  1. Set `RUN_CUSTOM_LOOP` to `false` in `libraries/AP_CustomConfig/AP_CustomConfig.h`.
  2. Build and flash the firmware.
  3. The board will now run standard ArduCopter. Connect to it with Mission Planner or QGroundControl to perform sensor calibrations, set parameters (e.g., for serial ports), and configure any attached hardware.

- **To Run the Custom Application:**
  1. Set `RUN_CUSTOM_LOOP` to `true` in `libraries/AP_CustomConfig/AP_CustomConfig.h`.
  2. Build and flash the firmware.
  3. The board will boot with all the saved settings, but will execute the `newMain()` function instead of the standard flight modes.

## 4. Command-Line Development Workflow

This entire project is managed from the command line.

### 4.1. Building the Firmware

The firmware is built using the `waf` build system. To create a debug-enabled build that will fit on the board's flash memory, use the following commands from the project root:

```bash
# Clean any previous build artifacts
./waf distclean

# Configure the build for the MicoAirH743 board with debug symbols
# --disable-scripting is necessary to make space for the debug symbols.
./waf configure --board MicoAir743 --debug --disable-scripting

# Compile the ArduCopter firmware
./waf copter
```

### 4.2. Flashing the Firmware

Flashing is performed using `openocd` with a hardware debugger (e.g., ST-Link). A custom configuration file is required due to the board's dual-bank flash memory.

**Key Files:**
- **Firmware:** `build/MicoAir743/bin/arducopter_with_bl.hex` (The file to be flashed).
- **Debug Symbols:** `build/MicoAir743/bin/arducopter` (The ELF file for GDB).
- **OpenOCD Config:** `micoair-h743.cfg` (Custom config to handle dual-bank flash).

**Flash Command:**
```bash
# Ensure arducopter_with_bl.hex is in the current directory
# This command uses the custom config to correctly program both flash banks.
openocd -f micoair-h743.cfg -c "program arducopter_with_bl.hex verify reset exit"
```

### 4.3. Debugging with GDB

Debugging is performed using a two-terminal setup.

**Terminal 1: Start the OpenOCD GDB Server**
```bash
# This command starts the server and waits for a connection. Leave it running.
openocd -f micoair-h743.cfg
```

**Terminal 2: Start the GDB Client**
```bash
# Launch GDB with the ELF file that contains the debug symbols.
# Ensure the 'arducopter' ELF file (renamed to arducopter.elf) is present.
gdb-multiarch arducopter.elf
```
**Inside the GDB session, run these commands:**
```gdb
# Connect to the OpenOCD server
target remote :3333

# Set a breakpoint at our custom entry point
break newMain

# Reset the board and halt execution at the very beginning
monitor reset halt

# Resume execution. The program will run until it hits the breakpoint.
continue
```

### 4.4. Serial Logging

Plain-text logging is configured to output on `SERIAL7` (physical port UART8).

- **Code:** The `newMain()` function in `custom_main.cpp` uses `AP::serialmanager().get_serial_by_id(7)` to get a handle to the port and initializes it at 115200 baud.
- **Hardware:** Connect a USB-to-Serial (FTDI) adapter from the UART8 TX/GND pins on the flight controller to your computer.
- **Viewing:** Use the Arduino IDE's Serial Monitor (or any other serial terminal) connected to the FTDI's COM port at **115200 baud**.

## 5. Key Project Files

- `libraries/AP_CustomConfig/AP_CustomConfig.h`: Contains the master `RUN_CUSTOM_LOOP` feature flag.
- `ArduCopter/custom_main.cpp`: Contains the `newMain()` function, the entry point for all custom application logic.
- `ArduCopter/mode.cpp`: Modified to include the hook that calls `newMain()` when the feature flag is enabled.
- `micoair-h743.cfg`: The custom OpenOCD configuration file required to correctly flash the dual-bank memory of the MicoAir H743.

## 6. Future Vision

With this foundation, the project is positioned to serve as a robust platform for various custom applications. Next steps include:
- Implementing low-level SPI drivers to communicate with the BMI088 directly (if needed, for comparison against the EKF).
- Developing logic to control motor outputs directly via the HAL.
- Integrating other custom sensors and peripherals.
- Creating more sophisticated state machines and control loops inside `newMain()`.
