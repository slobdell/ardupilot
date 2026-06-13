#!/usr/bin/env python3
"""
Generate a SITL-compatible param file from a hardware golden param file.

Strips hardware-specific calibration values that are meaningless (or harmful)
in simulation, and overrides params that need different values in SITL.

Usage:
    python3 tools/mavlink/gen_sitl_params.py
    python3 tools/mavlink/gen_sitl_params.py --src params/avatar_t1ranger_micoair.param
    python3 tools/mavlink/gen_sitl_params.py --src params/foo.param --out params/foo_sitl.param
"""

import argparse
import os

# Params whose names start with any of these prefixes are stripped.
# These are hardware-specific and either irrelevant or actively wrong in SITL.
STRIP_PREFIXES = (
    "INS_ACC",       # accelerometer calibration
    "INS_GYR",       # gyro calibration
    "INS_TCAL",      # temperature calibration
    "SERIAL",        # UART hardware assignments
    "BRD_",          # board-specific config
    "STAT_",         # flight-time statistics (wrong counts)
    "OSD",           # OSD display hardware
    "SERVO_BLH_",    # BLHeli hardware config
    "SERVO_DSHOT_",  # DShot hardware config
    "CAN_",          # CAN bus hardware
)

# Individual params to strip that don't fall under the prefix rules above.
STRIP_EXACT = {
    # INS hardware IDs and masks
    "INS_ACC_ID", "INS_ACC2_ID",
    "INS_GYR_ID", "INS_GYR2_ID",
    "INS_ENABLE_MASK",
    # Barometer hardware cal
    "BARO1_DEVID", "BARO2_DEVID", "BARO3_DEVID",
    "BARO1_GND_PRESS", "BARO2_GND_PRESS", "BARO3_GND_PRESS",
    # Compass hardware cal and device IDs
    "COMPASS_DEV_ID",  "COMPASS_DEV_ID2",  "COMPASS_DEV_ID3",
    "COMPASS_PRIO1_ID","COMPASS_PRIO2_ID", "COMPASS_PRIO3_ID",
    "COMPASS_OFS_X",   "COMPASS_OFS_Y",    "COMPASS_OFS_Z",
    "COMPASS_OFS2_X",  "COMPASS_OFS2_Y",   "COMPASS_OFS2_Z",
    "COMPASS_OFS3_X",  "COMPASS_OFS3_Y",   "COMPASS_OFS3_Z",
    "COMPASS_DIA_X",   "COMPASS_DIA_Y",    "COMPASS_DIA_Z",
    "COMPASS_DIA2_X",  "COMPASS_DIA2_Y",   "COMPASS_DIA2_Z",
    "COMPASS_DIA3_X",  "COMPASS_DIA3_Y",   "COMPASS_DIA3_Z",
    "COMPASS_ODI_X",   "COMPASS_ODI_Y",    "COMPASS_ODI_Z",
    "COMPASS_ODI2_X",  "COMPASS_ODI2_Y",   "COMPASS_ODI2_Z",
    "COMPASS_ODI3_X",  "COMPASS_ODI3_Y",   "COMPASS_ODI3_Z",
    # Battery monitor hardware pins and scaling
    "BATT_CURR_PIN", "BATT_VOLT_PIN",
    "BATT_AMP_PERVLT", "BATT_VOLT_MULT", "BATT_VLT_OFFSET", "BATT_AMP_OFFSET",
    # Board-mounted notification hardware
    "NTF_BUZZ_PIN",
    # Physical IMU/AHRS trim (board-mount specific)
    "AHRS_TRIM_X", "AHRS_TRIM_Y", "AHRS_TRIM_Z",
}

# Params that must be set to specific values in SITL regardless of what the
# golden file says.
SITL_OVERRIDES = {
    "AHRS_ORIENTATION": 0,    # no physical board rotation in SITL (hardware is YAW_270)
    "ARMING_CHECK":     0,    # disable all arming checks in SITL (gyro/compass/AHRS fail with simulated sensors)
    # Avatar has no airspeed sensor. Hardware ARSPD_TYPE=1 maps to the DLVR I2C
    # sensor which panics in SITL when the driver sends an init write command.
    "ARSPD_TYPE":       0,
    "ARSPD_USE":        0,
    # SERVO5 = tilt joint. Avatar mixer outputs norm=0..1 (hover→cruise) via set_output_norm.
    # Gazebo model: 1000 PWM = 0 rad (hover, motors up), 2000 PWM = π/2 rad (cruise).
    # Hardware REVERSED=1 compensates for a backwards-mounted physical servo — not needed
    # in Gazebo which simulates the final physical result directly.
    # TRIM=1000: norm=0 (hover) → MIN=1000 → hover. Gives smooth 0→1 interpolation.
    "SERVO5_MIN":       1000,
    "SERVO5_MAX":       2000,
    "SERVO5_TRIM":      1000,
    "SERVO5_REVERSED":  0,
}


def should_strip(name):
    if name in STRIP_EXACT:
        return True
    return any(name.startswith(p) for p in STRIP_PREFIXES)


def parse_params(path):
    params = []
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            if "," in line:
                name, value = line.split(",", 1)
                params.append((name.strip(), value.strip()))
    return params


def generate(src, out):
    params = parse_params(src)

    kept, stripped, overridden = [], [], []
    seen = set()

    for name, value in params:
        if should_strip(name):
            stripped.append(name)
            continue
        if name in SITL_OVERRIDES:
            value = str(SITL_OVERRIDES[name])
            overridden.append(name)
        kept.append((name, value))
        seen.add(name)

    # Add any overrides that weren't present in the source file
    for name, value in SITL_OVERRIDES.items():
        if name not in seen:
            kept.append((name, str(value)))
            overridden.append(f"{name} (added)")

    os.makedirs(os.path.dirname(out) or ".", exist_ok=True)
    with open(out, "w") as f:
        f.write(f"# SITL params — auto-generated from {os.path.basename(src)}\n")
        f.write("# Do not edit directly; edit the golden file and re-run gen_sitl_params.py\n\n")
        for name, value in kept:
            f.write(f"{name},{value}\n")

    print(f"Source:   {src}  ({len(params)} params)")
    print(f"Output:   {out}  ({len(kept)} params)")
    print(f"Stripped: {len(stripped)}  Overridden: {len(overridden)}")
    if overridden:
        print(f"  Overrides: {', '.join(overridden)}")


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--src", default="params/avatar_t1ranger_micoair.param",
                        help="Source golden param file")
    parser.add_argument("--out", default=None,
                        help="Output path (default: params/<src_stem>_sitl.param)")
    args = parser.parse_args()

    if args.out is None:
        stem = os.path.splitext(os.path.basename(args.src))[0]
        args.out = os.path.join(os.path.dirname(args.src), f"{stem}_sitl.param")

    generate(args.src, args.out)


if __name__ == "__main__":
    main()
