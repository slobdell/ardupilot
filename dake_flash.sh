#!/bin/bash
# Build and flash firmware to DAKEFPV H743 Pro.
#
# Usage:
#   ./dake_flash.sh              # build (if stale) then flash
#   ./dake_flash.sh --build      # force reconfigure + build, then flash
#   ./dake_flash.sh --flash      # flash last build without rebuilding
#   ./dake_flash.sh --dfu        # force DFU flash (board already in DFU mode)
#
# Flashing modes:
#   Normal (ArduPilot bootloader present):
#     Sends MAVLink reboot-to-bootloader, then flashes arducopter.apj via serial.
#     Board must be running ArduPilot on /dev/ttyACM0.
#
#   DFU (first-time / no ArduPilot bootloader):
#     Board must be in DFU mode (hold BOOT + plug USB, or board will auto-enter
#     DFU after the MAVLink reboot if no ArduPilot bootloader is installed).
#     Flashes arducopter_with_bl.hex via dfu-util.
#     After this, future flashes use the normal serial path.

set -e

BOARD="DAKEFPVH743Pro"
PORT="${DAKE_PORT:-/dev/ttyACM0}"
APJ="build/${BOARD}/bin/arducopter.apj"
HEX="build/${BOARD}/bin/arducopter_with_bl.hex"

BUILD=false
FLASH_ONLY=false
FORCE_DFU=false

for arg in "$@"; do
  case "$arg" in
    --build)  BUILD=true ;;
    --flash)  FLASH_ONLY=true ;;
    --dfu)    FORCE_DFU=true; FLASH_ONLY=true ;;
    -h|--help)
      grep '^#' "$0" | sed 's/^# \?//'
      exit 0 ;;
  esac
done

# --- Build ---
if ! $FLASH_ONLY; then
  if $BUILD; then
    echo "==> Configuring for ${BOARD}..."
    ./waf configure --board "$BOARD"
  fi
  echo "==> Building arducopter..."
  ./waf copter
fi

# --- Detect which flash path to use ---
DFU_MODE=false
if $FORCE_DFU; then
  DFU_MODE=true
elif lsusb 2>/dev/null | grep -q "0483:df11"; then  # STM32 ROM DFU
  echo "==> Detected board in DFU mode."
  DFU_MODE=true
fi

if $DFU_MODE; then
  # DFU flash — installs firmware + ArduPilot bootloader
  if [ ! -f "$HEX" ]; then
    echo "ERROR: $HEX not found. Run './waf configure --board $BOARD && ./waf copter' first."
    exit 1
  fi
  if ! command -v dfu-util &>/dev/null; then
    echo "ERROR: dfu-util not installed. Install with: sudo apt-get install dfu-util"
    exit 1
  fi
  # dfu-util expects raw binary, not Intel HEX. Convert first.
  TMP_BIN=$(mktemp /tmp/ardupilot_dfu_XXXXXX.bin)
  trap "rm -f $TMP_BIN" EXIT
  echo "==> Converting HEX to binary..."
  objcopy -I ihex -O binary "$HEX" "$TMP_BIN"
  echo "==> DFU flashing ${TMP_BIN} ($(du -sh "$TMP_BIN" | cut -f1))..."
  dfu-util -a 0 --dfuse-address 0x08000000:leave -D "$TMP_BIN"
  echo "==> DFU flash complete. Board should boot automatically."
else
  # Normal OTA flash via ArduPilot bootloader
  if [ ! -f "$APJ" ]; then
    echo "ERROR: $APJ not found. Run './waf configure --board $BOARD && ./waf copter' first."
    exit 1
  fi
  if [ ! -e "$PORT" ]; then
    echo "ERROR: Serial port $PORT not found. Is the board plugged in and running ArduPilot?"
    echo "If the board has no ArduPilot bootloader, hold BOOT + replug USB, then use: $0 --dfu"
    exit 1
  fi
  echo "==> Flashing ${APJ} to ${PORT} (serial/MAVLink)..."
  python3 Tools/scripts/uploader.py --port "$PORT" "$APJ"
  echo "==> Flash complete."
fi
