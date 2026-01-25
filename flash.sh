#!/bin/bash

# Configuration
GOLDEN_IMAGE="golden_master_77a622c7453d515531c14ff3bb1e12686fae3741"
FIRMWARE_HEX="arduplane_with_bl.hex"

echo "--- RESTORING GOLDEN USERDATA ---"
# We flash the full 2MB binary dump to restore parameters and calibrations.
# Address 0x08000000 is the start of flash.
# openocd -f micoair-h743.cfg -c "init; program $GOLDEN_IMAGE verify reset exit 0x08000000"

echo "--- UPDATING FIRMWARE ---"
# We flash the 1MB hex file. This overwrites the firmware but preserves 
# the userdata region at the end of the 2MB flash.
openocd -f micoair-h743.cfg -c "init; program $FIRMWARE_HEX verify reset exit"
