# Custom ArduPilot Fork: Notes & Documentation

This is a custom fork of ArduPilot optimized for two vectored-thrust aircraft: the **Blimp** and the **Avatar**. The majority of custom work lives in the `AP_Motors6DOF` library (otherwise experimental and unmaintained in upstream ArduPilot) and in `ArduPlane/quadplane.cpp`.

Both aircraft share the same firmware binary, config system, and TVC (Thrust Vectoring Controller) brain. Switching between them is a single `#define` in `libraries/AP_CustomConfig/AP_CustomConfig.h`.

---

## Active Aircraft

**Blimp** — 95% buoyant, nose-heavy, 2 vectoring gondola motors + tail yaw motor. Uses a split-range "vectoring as virtual elevator" approach in plane mode. Copter mode uses pure TVC tilt with no pitch PID (high rotational inertia). Not yet flight-tested (helium cost); Avatar validation carries over.

**Avatar** — Tilt-wing fixed-wing (test airframe: Hee-wing T1 Ranger). Wings rotate on a servo-driven axis: vertical for hover, horizontal for forward flight. Bench-tested June 2026 on MicoAir H743. Shares TVC brain with blimp.

---

## Key Custom Code Locations

| Path | What lives here |
|------|----------------|
| `libraries/AP_CustomConfig/` | Config selector (`ACTIVE_CONFIG`), `blimpConfig` / `avatarConfig` |
| `libraries/AP_Motors/AP_Motors6DOF*` | 6DOF mixer dispatch, `BlimpMixer`, `AvatarMixer`, output routing |
| `libraries/AP_Motors/TVC_Core.*` | Pure TVC logic (`tvc_run_main_logic`) — no ArduPilot dependencies, unit-testable |
| `libraries/AP_Motors/TVC_PID.*` | PID controllers used by TVC brain |
| `libraries/AP_Motors/TVC_Filters.*` | Low-pass filters used by TVC brain |
| `ArduPlane/quadplane.cpp` | QuadPlane backend init, blimp/avatar branching for plane-mode behavior |
| `ArduPlane/defines.h` | `MIN_AIRSPEED_MIN = 0` (required for blimp zero-airspeed flight) |

---

## Document Index

### Aircraft Design

**[Avatar_Design.md](Avatar_Design.md)**
Current design document for the Avatar tilt-wing fixed-wing. Covers control architecture (6DOF mixer philosophy, TVC brain, stall prevention, plane-mode pitch control, rear motor stabilization), servo assignments and calibration for the T1 Ranger, the `AvatarMixer` implementation, and the production aircraft design intent. **Start here when working on Avatar.**

**[Blimp_Design.md](Blimp_Design.md)**
Design, setup, and parameter reference for the blimp. Covers the physics rationale (nose-heavy, no roll control, high inertia, zero stall speed), the split-range "vectoring as virtual elevator" architecture, TECS modifications for zero-airspeed flight, full parameter tables, hardware wiring for MicoAir H743 (with MatekH743 as alternative), peripherals (lidar, optical flow), and EKF3 fusion config. **Start here when working on the blimp.**

### Hardware & Build

**[MicoAirH743_Board_Guide.md](MicoAirH743_Board_Guide.md)**
Primary flight controller reference. UART assignments, build command (`./waf configure --board MicoAir743 --enable-scripting --disable-crsf && ./waf plane`), OTA flash workflow via `micoair_flash.sh`, golden master restore via ST-Link, GDB debugging, and USB device identification. **Start here for any build or flash operation on the primary board.**

**[DAKEFPVH743Pro_Board_Guide.md](DAKEFPVH743Pro_Board_Guide.md)**
Reference for the DAKE H743 Pro board. Build commands, `dake_flash.sh` usage, USB VIDs, DFU/ST-Link flashing. No built-in compass (unlike MicoAir). Same flag interface as `micoair_flash.sh`.

**[Cloning_Guide.md](Cloning_Guide.md)**
How to clone a fully-calibrated flight controller to a new board using a golden master binary. Covers creating a golden master (full 2 MB flash dump via OpenOCD), restoring it via ST-Link, OTA firmware updates (parameter-preserving), the H743 dual-bank caveat, DFU mode procedure, and troubleshooting.

**[AM32_ESC_Setup.md](AM32_ESC_Setup.md)**
AM32 ESC configurator setup. Web-based tool at am32.ca/configurator; connect USB first then battery. New ESCs ship with 3D (bidirectional) mode on — must disable for Avatar (unidirectional motors). Keep enabled for blimp tail yaw motor.

### Tooling & Workflow

**[Tooling_Guide.md](Tooling_Guide.md)**
All tools under `tools/`. Covers parameter dump/apply/set (`param_dump.py`, `param_apply.py`, `param_set.py`), servo output mapping (`servo_map.py`), live monitoring (`monitor.py`, `motor_monitor.py`, `rc_monitor.py`), firmware build and flash shortcuts (`micoair_flash.sh`, `dake_flash.sh`), QGroundControl, and common end-to-end workflows (fresh flash → restore config, update golden config). **Start here for day-to-day operations.**

**[SITL_Guide.md](SITL_Guide.md)**
Running Avatar in ArduPilot's built-in SITL (no Gazebo required). Custom frame setup, `--map` for live overhead view, and test procedures for copter and plane modes.

**[QGroundControl_Setup.md](QGroundControl_Setup.md)**
QGC installation on Ubuntu 24.04. App image location, USB permissions (`newgrp dialout`), declining firmware update prompts on custom firmware, port conflict with MAVLink scripts.

### Outstanding Work

**[TODO.md](TODO.md)**
Consolidated list of pending items: Avatar and blimp items that need the aircraft on hand, SITL stabilisation work, and code cleanup. Organised by category with cross-references to the relevant design doc sections.

### Reference

**[SBUS_Reference.md](SBUS_Reference.md)**
SBUS scaling formulas (empirically validated), Bus A channel map (PFC → TVC/SFCs: motor throttles, pilot commands, transition progress), and Bus B channel map (TVC → SFCs: blended vectors, thrust factor, health). Reference when wiring up or debugging the distributed control bus.

**[Custom_Code_Architecture.md](Custom_Code_Architecture.md)**
Architecture and history of our custom TVC code. Covers the Humble Object pattern (pure `tvc_run_main_logic` vs HAL mixer layer), data contracts (`MixerInputs/Outputs/State`, `TVC_Inputs/Outputs/CoreState`), development lineage (standalone prototype → ported into ArduPilot → refactored), SFC Cross-Fade motor model for VTOL transitions, unit test history, and the dormant Caterpillar H-frame config (24-motor aircraft, still in code but disabled).

**[VTOL_Tricopter_Architecture.md](VTOL_Tricopter_Architecture.md)**
Historical design of the VTOL tricopter (PFC/TVC/SFC distributed architecture). The tricopter airframe is retired but `ENABLE_TRICOPTER_VTOL_BACKEND` remains the active flag for both blimp and avatar. Read this for context on the broadcaster/brain/blender hierarchy and the build configuration that evolved into the current Avatar build.

---

## Obsolete Docs

Stale or superseded documents are in [`obsolete/`](obsolete/). Nothing is deleted — consult them for historical context if needed.
