#!/usr/bin/env python3 -u
"""
Apply a .param file to ArduPilot over MAVLink.

Reads a param file (KEY,VALUE per line) and sets each parameter. Prints a
diff of what changed vs current values before applying.

Usage:
    python3 param_apply.py params/avatar_micoair.param
    python3 param_apply.py params/avatar_micoair.param --dry-run
    python3 param_apply.py --port /dev/ttyACM0 params/avatar_micoair.param
"""

import sys
import time
import argparse
from pymavlink import mavutil

sys.path.insert(0, '.')
from connect import connect

# Read-only or instance-specific params — never overwrite these
SKIP_ALWAYS = {
    'SYSID_SW_MREV',
    'SYSID_SW_TYPE',
    'FORMAT_VERSION',
    'STAT_BOOTCNT',
    'STAT_FLTTIME',
    'STAT_RUNTIME',
    'BARO1_GND_PRESS',  # re-sampled at every boot
    'BARO2_GND_PRESS',
    'BARO3_GND_PRESS',
}


def load_param_file(path):
    params = {}
    with open(path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            parts = line.split(',')
            if len(parts) < 2:
                continue
            name, value = parts[0].strip(), parts[1].strip()
            try:
                params[name] = float(value)
            except ValueError:
                print(f"WARNING: skipping unparseable line: {line}", file=sys.stderr)
    return params


def fetch_current_params(mav):
    params = {}
    mav.mav.param_request_list_send(mav.target_system, mav.target_component)
    deadline = time.time() + 30
    total = None
    while time.time() < deadline:
        msg = mav.recv_match(type='PARAM_VALUE', blocking=True, timeout=2)
        if msg is None:
            if params:
                mav.mav.param_request_list_send(mav.target_system, mav.target_component)
                deadline = time.time() + 15
            continue
        params[msg.param_id] = msg.param_value
        if total is None:
            total = msg.param_count
        if total and len(params) >= total:
            break
    return params


def set_param(mav, name, value, retries=3):
    for attempt in range(retries):
        mav.mav.param_set_send(
            mav.target_system,
            mav.target_component,
            name.encode('utf-8'),
            float(value),
            mavutil.mavlink.MAV_PARAM_TYPE_REAL32,
        )
        deadline = time.time() + 3
        while time.time() < deadline:
            msg = mav.recv_match(type='PARAM_VALUE', blocking=True, timeout=1)
            if msg and msg.param_id == name:
                return msg.param_value
    return None


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('param_file', help='.param file to apply')
    parser.add_argument('--port', default='/dev/ttyACM0')
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('--dry-run', action='store_true',
                        help='Show what would change without applying')
    parser.add_argument('--force', action='store_true',
                        help='Set all params even if value already matches')
    args = parser.parse_args()

    desired = load_param_file(args.param_file)
    print(f"Loaded {len(desired)} parameters from {args.param_file}", file=sys.stderr)

    mav = connect(args.port, args.baud)

    print("Reading current parameters...", file=sys.stderr)
    current = fetch_current_params(mav)
    print(f"Read {len(current)} current parameters", file=sys.stderr)

    to_set = []
    skipped = []
    already_correct = []
    unknown = []

    for name, value in sorted(desired.items()):
        if name in SKIP_ALWAYS:
            skipped.append(name)
            continue
        if name not in current:
            unknown.append(name)
            continue
        cur = current[name]
        if not args.force and abs(cur - value) < 1e-5:
            already_correct.append(name)
            continue
        to_set.append((name, value, cur))

    print(f"\nSummary:")
    print(f"  Already correct : {len(already_correct)}")
    print(f"  Will update     : {len(to_set)}")
    print(f"  Skipped (r/o)   : {len(skipped)}")
    print(f"  Not on FC       : {len(unknown)}")

    if to_set:
        print(f"\n{'Parameter':<35} {'Current':>12} {'Desired':>12}")
        print('-' * 62)
        for name, desired_val, cur_val in to_set:
            print(f"  {name:<33} {cur_val:>12.6g} {desired_val:>12.6g}")

    if args.dry_run:
        print("\n[dry-run] No changes applied.")
        return

    if not to_set:
        print("\nNothing to update.")
        return

    print(f"\nApplying {len(to_set)} parameters...")
    failed = []
    for i, (name, value, _) in enumerate(to_set):
        result = set_param(mav, name, value)
        if result is None:
            failed.append(name)
            print(f"  FAILED  {name}")
        else:
            print(f"  [{i+1}/{len(to_set)}] {name} = {result:.6g}")

    print(f"\nDone. {len(to_set) - len(failed)} applied, {len(failed)} failed.")
    if failed:
        print(f"Failed params: {', '.join(failed)}")
    print("Reboot the flight controller to apply all changes.")


if __name__ == '__main__':
    main()
