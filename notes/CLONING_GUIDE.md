# Flight Controller Cloning & Manufacturing Guide
**Target Hardware:** MicoAir 743 (STM32H743)
**Objective:** Create a bit-for-bit "Golden Master" image of a tuned flight controller and flash it onto new hardware.

---

## 1. Prerequisites (Starting from Zero)

Before beginning, you must install the necessary communication and debugging tools. These allow your computer to talk to the microcontroller via the ST-Link hardware.

```bash
# Update your package list
sudo apt-get update

# Install OpenOCD (The communication bridge)
sudo apt-get install openocd

# Install the ARM toolchain (Required for GDB debugging and binary analysis)
sudo apt-get install gcc-arm-none-eabi
sudo apt-get install gdb-arm-none-eabi
```

---

## 2. Locate Your "Drivers" (Script Discovery)

OpenOCD uses pre-written scripts (scripts/interface and scripts/target) to understand how to talk to your specific programmer and chip. You don't need to write these; they are installed with OpenOCD.

### 2.1 Find the Programmer Script
For most flight controllers, we use the **ST-Link v2**. Find its script:
```bash
find /usr/share/openocd/scripts -name "stlink.cfg"
# Expected output: /usr/share/openocd/scripts/interface/stlink.cfg
```

### 2.2 Find the Chip Script
For the MicoAir 743, we are looking for the **STM32H7** target script:
```bash
find /usr/share/openocd/scripts -name "stm32h7x.cfg"
# Expected output: /usr/share/openocd/scripts/target/stm32h7x.cfg
```

---

## 3. Forcing Connection (DFU Mode)

Flight controllers running ArduPilot often "lock" the debug pins as soon as they boot. To ensure a stable connection for cloning, you must prevent ArduPilot from starting by booting into **DFU Mode**.

1.  **Unplug** the USB and ST-Link from the board.
2.  Press and **HOLD** the physical **BOOT button** on the flight controller.
3.  While holding the button, **plug in the USB cable** to your computer.
4.  Wait 1 second and **release the button**.
5.  *(The board is now in a "Paused" state and ready for a debugger connection).*

---

## 4. Hardware Connection

Connect the ST-Link to the Flight Controller's **SWD** port:
1.  **GND** -> **GND**
2.  **SWCLK** -> **SWCLK**
3.  **SWDIO** -> **SWDIO**
4.  **3.3V** -> **3V3** (Not required if board is powered by USB).

---

## 5. Hardware Discovery & Validation

Now that the board is in DFU mode, we verify that OpenOCD can see the memory.

### 5.1 Test Connection
```bash
openocd -f interface/stlink.cfg -f target/stm32h7x.cfg -c "init; halt; exit"
```
*Look for "Info : [stm32h7x.cpu0] Cortex-M7 r1p1 processor detected" to confirm success.*

### 5.2 Verify Flash Banks
It is critical to see if OpenOCD automatically detects the second 1MB bank.
```bash
openocd -f interface/stlink.cfg -f target/stm32h7x.cfg -c "init; halt; flash banks; exit"
```
**Critical Check:** 
- If you see **#0: stm32h7x.flash** AND **#1: stm32h7x.flash**, you are ready.
- If you **only** see Bank #0, you MUST manually define the second bank in the cloning commands (see Section 6).

---

## 6. Understanding the Memory Map (Finding the "Magic Numbers")

To clone a board without guessing, you need two values: the **Start Address** and the **Size**.

### 6.1 The Start Address: `0x08000000`
On virtually every STM32 microcontroller, the internal flash memory is hard-wired to start at the address `0x08000000`. This is where the **Bootloader** lives. By starting here, we capture everything.

### 6.2 The Size: How much to read?
You must determine the flash size of your specific chip. 
1.  **Identify the Chip:** Read the laser-etching on the chip (e.g., STM32H743**VI**).
2.  **Lookup the Flash Size:** 
    *   H743VI = 2MB
    *   F405RG = 1MB
3.  **Convert to Hexadecimal:**
    *   **1MB** (1024 KB) = `0x100000`
    *   **2MB** (2048 KB) = `0x200000`

---

## 7. Phase A: Creating the "Golden Master" Image

Connect your **fully tuned and calibrated** aircraft. We will perform a "Raw Memory Dump." This method is more reliable than using flash-specific drivers because it simply reads the raw bits from the memory map.

```bash
# Template: dump_image [filename] [start_address] [size]
# For MicoAir 743 (2MB):
openocd -f interface/stlink.cfg -f target/stm32h7x.cfg -c "init; halt; dump_image golden_master.bin 0x08000000 0x200000; exit"
```

---

## 8. Phase B: Flashing the Clone

Connect the **new, blank** flight controller. 

**Important:** For the H743 specifically, OpenOCD often fails to "see" the second 1MB flash bank automatically. To prevent a "no flash bank found" error, you must manually define the second bank in the command line before starting the program.

```bash
# Manual Bank Definition: 'flash bank bank1 stm32h7x 0x08100000 0x100000 0 0 stm32h7x.cpu0'
# This tells OpenOCD about the second 1MB starting at 0x08100000.

openocd \
  -f interface/stlink.cfg \
  -f target/stm32h7x.cfg \
  -c "flash bank bank1 stm32h7x 0x08100000 0x100000 0 0 stm32h7x.cpu0" \
  -c "init; program golden_master.bin verify reset exit 0x08000000"
```

### **Verification Checklist**
1.  **Programming Started:** You should see both banks being erased/written.
2.  **Verify OK:** This confirms the hardware now contains an exact bit-for-bit copy.
3.  **Boot Test:** Unplug the ST-Link, power via USB, and connect to ArduPilot. All parameters and calibrations from the Master should be present.

---

## 7. Troubleshooting

### "Target Not Found" or "Connection Failed"
- Check your wiring. SWDIO and SWCLK are often swapped by mistake.
- Ensure the board is getting enough power.
- Try lowering the adapter speed: Add `-c "adapter speed 2000"` to the start of your command.

### "Flash Write Failed"
- The H743 sometimes has "Option Bytes" that protect sectors. 
- You can perform a full mass erase before flashing: `-c "stm32h7x mass_erase 0"

```