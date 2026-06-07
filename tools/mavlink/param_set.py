#!/usr/bin/env python3 -u
"""
Set one or more ArduPilot parameters directly over MAVLink.

Usage:
    python3 param_set.py WVANE_GAIN 1.0
    python3 param_set.py Q_TILT_RATE_UP 120 WVANE_DIRECTION 1
    python3 param_set.py --port /dev/ttyACM0 ARMING_CHECK 50
"""

import sys
import time
import argparse
from pymavlink import mavutil

sys.path.insert(0, '.')
from connect import connect


def set_param(mav, name, value, retries=3):
    for _ in range(retries):
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


def get_param(mav, name, retries=3):
    for _ in range(retries):
        mav.mav.param_request_read_send(
            mav.target_system,
            mav.target_component,
            name.encode('utf-8'),
            -1,
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
    parser.add_argument('--port', default='/dev/ttyACM0')
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('params', nargs='+',
                        help='Alternating NAME VALUE pairs, e.g. WVANE_GAIN 1.0 WVANE_DIRECTION 1')
    args = parser.parse_args()

    if len(args.params) % 2 != 0:
        print("ERROR: params must be NAME VALUE pairs")
        sys.exit(1)

    pairs = [(args.params[i].upper(), args.params[i+1]) for i in range(0, len(args.params), 2)]

    mav = connect(args.port, args.baud)

    for name, value in pairs:
        before = get_param(mav, name)
        result = set_param(mav, name, value)
        if result is None:
            print(f"FAILED  {name}")
        else:
            before_str = f"{before:.6g}" if before is not None else "?"
            print(f"OK  {name}  {before_str} -> {result:.6g}")


if __name__ == '__main__':
    main()
