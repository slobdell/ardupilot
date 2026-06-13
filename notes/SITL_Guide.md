# Avatar SITL Simulation Guide

ArduPilot's built-in SITL (Software In The Loop) runs the full ArduPlane firmware against a simulated physics model — no Gazebo required. The `--map` flag gives a live 2D overhead view sufficient for testing copter and plane modes.

## Custom SITL Frame

Avatar uses a custom `quadplane-avatar` SITL frame added to this repo. It maps servo channels to match Avatar's actual hardware assignments:

| Motor | SITL servo idx | ArduPilot channel | Function |
|-------|---------------|-------------------|----------|
| Left wing | 0 | SERVO1 | 33 |
| Right wing | 3 | SERVO4 | 34 |
| Rear tail | 2 | SERVO3 | 35 |
| Wing tilt | 4 | SERVO5 | 95 (k_scripting2) |

Files added:
- `libraries/SITL/SIM_Frame.cpp` — `avatar_motors[]` array
- `libraries/SITL/SIM_QuadPlane.cpp` — "avatar" frame case, `motor_offset=0`
- `Tools/autotest/pysim/vehicleinfo.py` — `quadplane-avatar` entry
- `Tools/autotest/default_params/quadplane-avatar.parm` — default servo assignments

## Building

```bash
./waf configure --board sitl    # no --disable-scripting needed
./waf plane
```

Subsequent builds (after code changes) just run `./waf plane` — no re-configure needed unless switching boards.

## Starting the Simulation

```bash
./Tools/autotest/sim_vehicle.py -v ArduPlane -f quadplane-avatar -w --console --map
```

Flags:
- `-w` — wipe EEPROM and load default params. Use on first run or to reset params. **Omit on subsequent runs** to reuse the saved `eeprom.bin` (params persist between runs like real FC flash).
- `-N` — skip rebuild (use when binary is already up to date)
- `--console` — floating status window
- `--map` — 2D overhead map view

**Typical workflow:**
```bash
# First run — fresh params
./Tools/autotest/sim_vehicle.py -v ArduPlane -f quadplane-avatar -w --console --map

# Subsequent runs — reuse saved eeprom.bin, skip rebuild
./Tools/autotest/sim_vehicle.py -v ArduPlane -f quadplane-avatar -N --console --map
```

## Generating SITL Params

Never edit the SITL param file directly. Generate it from the golden hardware file:

```bash
python3 tools/mavlink/gen_sitl_params.py
```

This produces `params/avatar_t1ranger_micoair_sitl.param` by stripping hardware-specific
calibration (INS, compass, BARO device IDs, SERIAL ports, OSD, DShot config) and overriding:
- `AHRS_ORIENTATION=0` — hardware is YAW_270; SITL has no physical rotation
- `ARSPD_TYPE=0`, `ARSPD_USE=0` — Avatar has no airspeed sensor. Hardware value `ARSPD_TYPE=1`
  maps to the DLVR I2C sensor in this ArduPilot build; the SITL DLVR simulator panics with
  "Should never be written to" when the driver sends its init write command.

Run this any time the golden params file is updated.

## Loading Avatar Parameters

At the MAVProxy prompt (looks like `MANUAL>` or `QSTABILIZE>`):

```
param load params/avatar_t1ranger_micoair_sitl.param
```

The SITL param file loads in a single pass. Some params (Q_ENABLE etc.) still require a
reboot to activate — just run `reboot` after loading. No second param load needed; values
are already saved to eeprom.bin.

## Basic MAVProxy Commands

```
mode QSTABILIZE          ← copter stabilise mode
mode FBWA                ← fixed-wing with attitude hold
arm throttle             ← arm (bypasses some pre-arm checks)
disarm                   ← disarm
rc 3 1500                ← set throttle channel to 50% (mid-stick)
rc 3 1000                ← throttle to zero
rc all 1500              ← all channels to centre
reboot                   ← soft-reboot the simulated FC
param show Q_A_RAT_RLL_P ← inspect a parameter
param set Q_A_RAT_RLL_P 0.25  ← set a parameter live
```

## Stopping the Sim

Always stop with **Ctrl-C in the sim_vehicle.py terminal**. This kills the SITL binary and all MAVProxy child processes together. Closing windows individually leaves orphan processes that hold the TCP port, causing "no link" on the next run.

If you end up with orphan processes:
```bash
pkill -9 -f arduplane; pkill -9 -f mavproxy.py; pkill -9 -f sim_vehicle
```

The `-9` (SIGKILL) is important — regular SIGTERM sometimes leaves MAVProxy child processes alive.
**"No link" is almost always orphan processes competing for the port 5760 TCP socket**, not a firmware
or params problem. Clean kill first, then restart.

## Reconnecting to a Running Sim

If MAVProxy is closed but the sim process is still running:

```bash
mavproxy.py --master tcp:127.0.0.1:5760
```

## Gazebo Harmonic 3D Visualization

Gazebo provides a full 3D view of the aircraft in flight. ArduPilot SITL communicates with
Gazebo over UDP (port 9002 by default) using the `ardupilot_gazebo` plugin.

### Installation (Ubuntu 24.04 Noble, one-time)

```bash
# Install prerequisites
sudo apt install -y curl gnupg

# Add OSRF apt repository and keyring
sudo curl https://packages.osrfoundation.org/gazebo.gpg \
  --output /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] \
  http://packages.osrfoundation.org/gazebo/ubuntu-stable noble main" \
  | sudo tee /etc/apt/sources.list.d/gazebo-stable.list

# Install (~800 MB download)
sudo apt update
sudo apt install -y gz-harmonic
```

Verify: `gz sim --version` should print `8.x.x`.

### ardupilot_gazebo Plugin (one-time build)

The `ardupilot_gazebo` plugin translates between Gazebo joint physics and ArduPilot's
servo/sensor UDP packets. Clone and build it once:

```bash
# Build dependencies (in addition to gz-harmonic itself)
sudo apt install -y rapidjson-dev libopencv-dev \
  libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev

cd ~/projects
git clone https://github.com/ArduPilot/ardupilot_gazebo.git
cd ardupilot_gazebo
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo
make -j$(nproc)
```

Add to `~/.bashrc` (so Gazebo finds the plugin and models at startup):

```bash
export GZ_SIM_SYSTEM_PLUGIN_PATH=$HOME/projects/ardupilot_gazebo/build
export GZ_SIM_RESOURCE_PATH=$HOME/projects/ardupilot_gazebo/worlds:$HOME/projects/ardupilot_gazebo/models
```

### Running with Gazebo

Two terminals required. Environment variables must be set — they are in `~/.bashrc` so
new terminals get them automatically, but existing terminals need a manual source:

```bash
source ~/.bashrc   # only needed if terminal was opened before Gazebo was installed
# Verify:
echo $GZ_SIM_SYSTEM_PLUGIN_PATH   # → ~/projects/ardupilot_gazebo/build
echo $GZ_SIM_RESOURCE_PATH        # → includes worlds and models dirs
```

**Step 1 — Start Gazebo (Terminal 1):**
```bash
cd ~/projects/ardupilot_gazebo
gz sim -v 4 worlds/avatar_runway.sdf
```
Click the **▶ Play** button in the Gazebo GUI bottom toolbar. Gazebo must be playing
before SITL starts, otherwise SITL prints "No JSON sensor message received" repeatedly
and the MAVLink link never comes up.

**Step 2 — Start SITL (Terminal 2):**
```bash
cd ~/projects/ardupilot
./Tools/autotest/sim_vehicle.py -v ArduPlane -f gazebo-avatar -w -N --console --map --add-param-file=params/avatar_t1ranger_micoair_sitl.param
```
`-w` wipes EEPROM for a clean param slate. `-N` skips rebuild (omit if you changed firmware code).
`--add-param-file` loads the SITL param overrides before the first boot — no manual `param load`
or `reboot` step needed. This is critical because hardware params include `AHRS_ORIENTATION=6`
(YAW_270) which would cause the attitude controller to fight itself.

**Step 3 — Load joystick module:**
```
module load joystick
```
Should print `Found joystick (8BitDo Ultimate 2C Wireless Controller)` with no error.
Left stick = throttle/yaw, right stick = roll/pitch (Mode 2).

**Step 4 — Arm and fly:**
```
arm throttle
mode QSTABILIZE
```
Then use the controller. Left stick up = throttle, right stick = attitude.

### Joystick Setup (one-time)

The 8BitDo controller config lives in the repo at `tools/joystick/8bitdo-ultimate-2c.yml`
and is symlinked into `~/.mavproxy/joysticks/` where MAVProxy looks first.

**To set up on a new machine:**
```bash
mkdir -p ~/.mavproxy/joysticks
ln -sf ~/projects/ardupilot/tools/joystick/8bitdo-ultimate-2c.yml ~/.mavproxy/joysticks/
```

MAVProxy also checks `$MAVPROXY_JOYSTICK_DIR` if set. The venv's site-packages joystick
dir is the fallback — do not store configs there as they are lost on venv rebuild.

To identify axes on a new controller:
```bash
python3 -m MAVProxy.modules.mavproxy_joystick.findjoy
```

### Protocol Notes (for debugging)

The `gazebo-avatar` vehicleinfo entry sets `"model": "JSON"` which makes SITL use
`SIM_JSON` instead of the old `SIM_Gazebo`. This is required because the modern
`ardupilot_gazebo` plugin expects `servo_packet_16` (magic=18458, uint16 PWM values),
which only `SIM_JSON` sends. The old `SIM_Gazebo` sends raw floats with no magic header,
causing "Incorrect protocol magic 0 should be 18458" errors in Gazebo logs.

The Avatar model SDF has `<lock_step>0</lock_step>`. Lock-step must be **disabled** in
Gazebo Harmonic — with it enabled, Gazebo waits for SITL to signal physics advancement
but the handshake never completes and no JSON state is ever sent back to SITL.

### Avatar Model and World

Custom files added to `ardupilot_gazebo/`:

| File | Purpose |
|------|---------|
| `models/avatar_with_ardupilot/model.sdf` | Avatar 3-motor tiltrotor physics model |
| `models/avatar_with_ardupilot/model.config` | Model metadata |
| `worlds/avatar_runway.sdf` | World with runway + Avatar spawn |

Servo channel mapping in the model:

| ch (0-idx) | ArduPilot | Joint | Type |
|-----------|-----------|-------|------|
| 0 | SERVO1 | rotor_left_joint | VELOCITY (CCW) |
| 2 | SERVO3 | rotor_rear_joint | VELOCITY (CCW) |
| 3 | SERVO4 | rotor_right_joint | VELOCITY (CW) |
| 4 | SERVO5 | tilt_joint | POSITION (0=hover, π/2=cruise) |

Tilt logic: servo_min (1000 PWM) → tilt_joint=0 rad (cruise, motors forward).
servo_max (2000 PWM) → tilt_joint=π/2 rad (hover, motors up).
`SERVO5_TRIM=2000` makes hover the default trim/failsafe position.
Hardware has SERVO5_REVERSED=1 and a tighter physical range (811–1827) — SITL overrides
these to REVERSED=0, MIN=1000, MAX=2000, TRIM=2000 so Gazebo receives the correct range.

### Known Gazebo Limitations and Gotchas

- **Motor thrust is approximate.** The lift-drag `cp` (center-of-pressure radius) is set
  to 0.100 m. This is larger than Avatar's actual prop geometry (≈0.063 m for 5-inch props)
  but tuned to give T/W ≈ 2.5× with hover at ~50% throttle.
- **No aerodynamic surfaces.** Ailerons and V-tail (SERVO6-9) are ignored by Gazebo.
  Only motor thrust and tilt joint have physics effect.
- **Tilt arm uses shared joint.** Both front motors tilt together on one joint, which
  matches Avatar hardware exactly.
- **link_name scoping.** Gazebo plugin link/joint names must NOT include the model name
  as a prefix (e.g. use `rotor_left`, not `avatar_with_ardupilot::rotor_left`). The
  `::` prefix implies a *nested* model; direct child links need unscoped names. This is
  different from the iris model which uses `iris_with_standoffs::rotor_0` because those
  links genuinely live in a nested included model.
- **Pre-arm checks always fail in Gazebo SITL.** Gyros, compass, and AHRS checks are
  meaningless with simulated sensors. The SITL param file sets `ARMING_CHECK=0` via
  `gen_sitl_params.py`. Always load SITL params and reboot before arming.

## Current SITL Status (as of June 2026)

**Stable hover has not been achieved.** The aircraft loses attitude control shortly after
throttle-up and flips. The Gazebo infrastructure is complete and all the control wiring is
correct, but the simulation physics do not yet match the real airframe closely enough for
the hardware-validated PID gains to hold stable.

Work done so far:
- Motor orientation, tilt servo direction, and SERVO5 param mapping all confirmed correct
- Pitch balance geometry tuned (rear motor at -0.52 m gives roughly equal pitch moments)
- Motor thrust tuned (cp=0.100, T/W ≈ 2.5×, hover at ~50% throttle)
- Base link inertia doubled (Ixx=0.10, Iyy=0.13, Izz=0.18 kg·m²) to better reflect
  nose-heavy airframe with battery forward — previous values were ~2× too low, causing
  PID corrections to overshoot violently

Suspected remaining issues:
- Inertia tensor may still be underestimated; real values require physical measurement
  (e.g. bifilar pendulum test) or CAD mass-properties export
- Motor drag model (damping coefficients) may not match real ESC + prop response time
- The hardware PIDs were tuned on the real aircraft and may need SITL-specific overrides
  (particularly Q_A_RAT_PIT_D and Q_A_RAT_RLL_D) if motor response time differs

Next steps when resuming:
1. Measure or estimate real Iyy/Ixx more accurately (battery mass × arm² is the dominant term)
2. If still unstable after inertia fix: add Q_A_RAT_PIT_D=0 and Q_A_RAT_RLL_D=0 as SITL
   overrides in gen_sitl_params.py (derivative terms amplify fast simulation motor response)
3. Validate in QSTABILIZE before attempting FBWA or transition

## SITL Limitations for Avatar

- **Plane aerodynamics are approximate.** Avatar's control surfaces (ailerons, V-tail on SERVO6-9) are not read by the built-in plane physics model, which expects surfaces on SERVO1-4. Motor physics (thrust, tilt) are correct; aerodynamic moments from surfaces are not.
- **Good for:** copter mode validation (QSTABILIZE, QHOVER, QLOITER), FBWA control logic, mode transition sequencing.
- **Not good for:** precise aerodynamic tuning of FBWA gains, stall behaviour, airspeed response.
