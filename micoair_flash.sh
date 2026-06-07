#!/bin/bash
# Build and flash firmware to MicoAir H743 via USB (OTA).
#
# Usage:
#   ./micoair_flash.sh              # incremental build then flash
#   ./micoair_flash.sh --build      # force reconfigure + build, then flash
#   ./micoair_flash.sh --flash      # flash last build without rebuilding
#   ./micoair_flash.sh --restore    # restore golden master (full flash via OpenOCD)
#
# Notes:
#   --disable-scripting is required: MicoAir H743 has 2MB internal flash with no
#   external storage. The Lua scripting runtime doesn't fit alongside the firmware.
#
#   OTA flash (default) preserves parameters and calibrations.
#   Golden master restore (--restore) is a full chip write via ST-Link/OpenOCD and
#   overwrites everything including parameters — use only for recovery.

set -e

BOARD="MicoAir743"
PORT="${MICOAIR_PORT:-/dev/ttyACM0}"
APJ="build/${BOARD}/bin/arducopter.apj"
GOLDEN_MASTER="golden_master_77a622c7453d515531c14ff3bb1e12686fae3741"

BUILD=false
FLASH_ONLY=false
RESTORE=false

for arg in "$@"; do
  case "$arg" in
    --build)    BUILD=true ;;
    --flash)    FLASH_ONLY=true ;;
    --restore)  RESTORE=true; FLASH_ONLY=true ;;
    -h|--help)
      grep '^#' "$0" | sed 's/^# \?//'
      exit 0 ;;
  esac
done

# --- Golden master restore (ST-Link path) ---
if $RESTORE; then
  if [ ! -f "$GOLDEN_MASTER" ]; then
    echo "ERROR: Golden master not found: $GOLDEN_MASTER"
    exit 1
  fi
  echo "==> Restoring golden master via OpenOCD (ST-Link must be connected)..."
  echo "    IMPORTANT: Board must be in STM32 ROM DFU mode (hold BOOT button + plug power)."
  echo "    ArduPilot remaps SWD pins at startup — OpenOCD cannot connect to a running board."
  echo "    This will overwrite ALL flash including parameters and calibrations."
  read -p "    Are you sure? (y/N) " confirm
  [[ "$confirm" =~ ^[Yy]$ ]] || { echo "Aborted."; exit 0; }
  openocd -f micoair-h743.cfg \
    -c "program $GOLDEN_MASTER verify reset exit 0x08000000"
  echo "==> Golden master restored."
  exit 0
fi

# --- Build ---
if ! $FLASH_ONLY; then
  if $BUILD; then
    echo "==> Configuring for ${BOARD} (--disable-scripting)..."
    ./waf configure --board "$BOARD" --disable-scripting
  fi
  echo "==> Building arducopter..."
  ./waf copter
fi

# --- Verify firmware exists ---
if [ ! -f "$APJ" ]; then
  echo "ERROR: $APJ not found."
  echo "Run: ./waf configure --board $BOARD --disable-scripting && ./waf copter"
  exit 1
fi

if [ ! -e "$PORT" ]; then
  echo "ERROR: Serial port $PORT not found. Is the board plugged in and running ArduPilot?"
  exit 1
fi

# --- OTA flash (preserves parameters) ---
echo "==> Flashing ${APJ} to ${PORT} (OTA — parameters preserved)..."
python3 Tools/scripts/uploader.py --port "$PORT" "$APJ"
echo "==> Flash complete."
