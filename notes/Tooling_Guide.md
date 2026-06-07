# Automated Tooling Guide

**Date:** June 7, 2026

All tools live under `tools/`. MAVLink tools require the board connected via USB on `/dev/ttyACM0` and QGroundControl **closed** (it holds the port exclusively).

---

## 1. Parameter Management

### 1.1 Dumping a Golden Config

Reads all parameters from the flight controller and saves to a `.param` file.

```bash
python3 tools/mavlink/param_dump.py -o params/blimp_micoair.param -v
```

**Output format:** Plain text, one `PARAM_NAME,VALUE` per line. Compatible with QGroundControl and Mission Planner import/export.

**Per-aircraft convention:**
```
params/
  blimp_micoair.param    # Golden blimp config (includes calibrations)
  avatar_micoair.param   # Golden avatar config (derive from blimp after diverging)
```

### 1.2 Applying a Config File

Applies a `.param` file to the flight controller. Shows a diff of what will change before applying.

```bash
# Apply full config
python3 tools/mavlink/param_apply.py params/blimp_micoair.param

# Preview changes without applying
python3 tools/mavlink/param_apply.py params/blimp_micoair.param --dry-run
```

**Bootstrapping note:** ArduPlane requires two apply passes after a fresh flash because `Q_ENABLE=1` must be set and the board rebooted before QuadPlane parameters (`Q_*`) are registered. Workflow:

```bash
./micoair_flash.sh --flash          # flash firmware
python3 tools/mavlink/param_apply.py params/blimp_micoair.param   # pass 1 (sets Q_ENABLE=1)
# power cycle
python3 tools/mavlink/param_apply.py params/blimp_micoair.param   # pass 2 (sets Q_* params)
# power cycle
python3 tools/mavlink/param_apply.py params/blimp_micoair.param --dry-run  # verify clean
```

**Permanently skipped params** (volatile or read-only — never written):
- `STAT_BOOTCNT`, `STAT_FLTTIME`, `STAT_RUNTIME` — counters
- `FORMAT_VERSION`, `SYSID_SW_MREV`, `SYSID_SW_TYPE` — read-only
- `BARO1/2/3_GND_PRESS` — re-sampled at every boot

### 1.3 Setting Individual Parameters

Sets one or more parameters directly without a file.

```bash
# Single param
python3 tools/mavlink/param_set.py WVANE_GAIN 1.0

# Multiple params at once
python3 tools/mavlink/param_set.py WVANE_DIRECTION 1 WVANE_GAIN 1.0 WVANE_ANG_MIN 1.0
```

Shows before/after value for each param. Use `--dry-run` on `param_apply.py` afterward to verify the full config is still clean.

### 1.4 Querying Servo Output Mapping

Reads all `SERVOn_FUNCTION` parameters and displays them in a table.

```bash
# Show current mapping
python3 tools/mavlink/servo_map.py

# Set specific servo functions
python3 tools/mavlink/servo_map.py --set 1=33 3=34 4=35
```

---

## 2. Parameter Documentation Lookup

Curated ArduPilot parameter docs live at `tools/parameter_docs/` (copied from the mavlink-hud research project). Each parameter has a dedicated `.md` file with description, default, range, units, and engineer-level notes sourced directly from the ArduPilot codebase.

```bash
# Exact param lookup
python3 tools/param_lookup.py WVANE_GAIN
python3 tools/param_lookup.py Q_TILT_RATE_UP
python3 tools/param_lookup.py SERIAL5_PROTOCOL

# Search by prefix or partial name
python3 tools/param_lookup.py WVANE        # lists all WVANE_* params
python3 tools/param_lookup.py SERIAL5      # lists SERIAL5_BAUD, _OPTIONS, _PROTOCOL
```

---

## 3. Firmware Build & Flash

### 3.1 MicoAir H743 (ArduPlane)

```bash
./micoair_flash.sh              # build plane + OTA flash (incremental)
./micoair_flash.sh --build      # reconfigure + build + OTA flash
./micoair_flash.sh --flash      # OTA flash last build (no rebuild)
./micoair_flash.sh --restore    # restore golden master via ST-Link (full chip)
```

The `--restore` path requires the board in STM32 ROM DFU mode (hold BOOT button on power-up) with ST-Link connected via SWD. It overwrites everything including parameters — always run `param_apply` afterward.

### 3.2 DAKE H743 Pro

```bash
./dake_flash.sh                 # same flag interface as micoair_flash.sh
```

---

## 4. Live Monitoring

```bash
# General ArduPilot log output (STATUSTEXT messages)
python3 tools/mavlink/monitor.py

# Live motor/servo output values
python3 tools/mavlink/motor_monitor.py

# RC input channels
python3 tools/mavlink/rc_monitor.py
```

---

## 5. QGroundControl

**Binary:** `~/Downloads/QGroundControl-x86_64.AppImage`

```bash
~/Downloads/QGroundControl-x86_64.AppImage
```

Auto-detects the flight controller on USB. When connecting custom firmware, **decline any firmware update prompts** — select "Skip" to keep the custom binary.

**Port conflict:** QGC holds `/dev/ttyACM0` exclusively. Close QGC before running any of the MAVLink scripts above.

For USB permissions without a full logout:
```bash
newgrp dialout
```

---

## 6. Common Workflows

### Fresh firmware flash → restore config
```bash
./micoair_flash.sh --flash
python3 tools/mavlink/param_apply.py params/blimp_micoair.param
# power cycle
python3 tools/mavlink/param_apply.py params/blimp_micoair.param
# power cycle
python3 tools/mavlink/param_apply.py params/blimp_micoair.param --dry-run
```

### Update golden config after intentional parameter changes
```bash
python3 tools/mavlink/param_dump.py -o params/blimp_micoair.param -v
git add params/blimp_micoair.param
git commit -m "update blimp golden config: <what changed>"
```

### Quick single-param change during bench testing
```bash
python3 tools/mavlink/param_set.py Q_TILT_RATE_UP 80
python3 tools/param_lookup.py Q_TILT_RATE_UP   # verify range/meaning first
```
