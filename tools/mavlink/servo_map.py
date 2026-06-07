#!/usr/bin/env python3 -u
"""
Query and optionally update ArduPilot servo output function mapping.

Reads all SERVOn_FUNCTION parameters and displays them in a table with
human-readable function names. Optionally sets one or more mappings.

Usage:
    python3 servo_map.py                          # show current mapping
    python3 servo_map.py --set 1=33 3=34 4=35    # set servo functions
    python3 servo_map.py --port /dev/ttyACM0
"""

import sys
import time
import argparse
from pymavlink import mavutil

sys.path.insert(0, '.')
from connect import connect

# ArduPilot SERVOn_FUNCTION values (common subset)
FUNCTION_NAMES = {
    0:   'Disabled',
    1:   'RCPassThru',
    4:   'Aileron',
    6:   'Mount Pan',
    7:   'Mount Tilt',
    9:   'Camera Trigger',
    10:  'Camera Gimbal',
    12:  'Mount Roll',
    16:  'Ignition',
    19:  'Elevator',
    21:  'Rudder',
    22:  'Steering',
    23:  'Parachute',
    24:  'EPM',
    25:  'HeliRSC',
    26:  'HeliTailRSC',
    27:  'Motor1',
    28:  'Motor2',
    29:  'Motor3',
    30:  'Motor4',
    31:  'Motor5',
    32:  'Motor6',
    33:  'Motor1',   # QuadPlane motor 1
    34:  'Motor2',   # QuadPlane motor 2
    35:  'Motor3',   # QuadPlane motor 3
    36:  'Motor4',   # QuadPlane motor 4
    37:  'Tilt Motor Front',
    38:  'Tilt Motor Rear',
    39:  'Tilt Motor Front Left',
    40:  'Tilt Motor Front Right',
    41:  'Elevator (tailsitter)',
    51:  'RCIN1',
    52:  'RCIN2',
    53:  'RCIN3',
    54:  'RCIN4',
    55:  'RCIN5',
    56:  'RCIN6',
    57:  'RCIN7',
    58:  'RCIN8',
    59:  'RCIN9',
    60:  'RCIN10',
    61:  'RCIN11',
    62:  'RCIN12',
    70:  'Throttle',
    73:  'Throttle Left',
    74:  'Throttle Right',
    94:  'Scripting1',
    95:  'Scripting2',
    96:  'Scripting3',
    97:  'Scripting4',
    98:  'Scripting5',
    99:  'Scripting6',
}


def fn_name(n):
    return FUNCTION_NAMES.get(int(n), f'({int(n)})')


def fetch_servo_params(mav, count=16):
    """Request all SERVOn_FUNCTION params and return as {n: value} dict."""
    results = {}
    needed = {f'SERVO{i}_FUNCTION' for i in range(1, count + 1)}

    mav.mav.param_request_list_send(mav.target_system, mav.target_component)

    deadline = time.time() + 10
    while needed and time.time() < deadline:
        msg = mav.recv_match(type='PARAM_VALUE', blocking=True, timeout=1)
        if msg and msg.param_id in needed:
            needed.discard(msg.param_id)
            n = int(msg.param_id.replace('SERVO', '').replace('_FUNCTION', ''))
            results[n] = int(msg.param_value)

    if needed:
        print(f"WARNING: did not receive: {', '.join(sorted(needed))}")

    return results


def set_servo_function(mav, servo_n, function_val):
    """Set SERVOn_FUNCTION via MAVLink PARAM_SET."""
    param_id = f'SERVO{servo_n}_FUNCTION'
    mav.mav.param_set_send(
        mav.target_system,
        mav.target_component,
        param_id.encode('utf-8'),
        float(function_val),
        mavutil.mavlink.MAV_PARAM_TYPE_INT16,
    )
    # Wait for ACK
    deadline = time.time() + 5
    while time.time() < deadline:
        msg = mav.recv_match(type='PARAM_VALUE', blocking=True, timeout=1)
        if msg and msg.param_id == param_id:
            print(f"  SET {param_id} = {int(msg.param_value)} ({fn_name(msg.param_value)})")
            return True
    print(f"  WARNING: no ACK for {param_id}")
    return False


def parse_set_args(set_args):
    """Parse ['1=33', '3=34'] into [(1, 33), (3, 34)]."""
    pairs = []
    for s in set_args:
        try:
            n, v = s.split('=')
            pairs.append((int(n), int(v)))
        except ValueError:
            print(f"ERROR: invalid --set argument '{s}', expected format N=VALUE")
            sys.exit(1)
    return pairs


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--port', default='/dev/ttyACM0')
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('--set', nargs='+', metavar='N=FUNC',
                        help='Set one or more servo functions, e.g. --set 1=33 3=34')
    parser.add_argument('--count', type=int, default=16,
                        help='Number of servo outputs to query (default: 16)')
    args = parser.parse_args()

    mav = connect(args.port, args.baud)

    if args.set:
        pairs = parse_set_args(args.set)
        print("\nApplying updates...")
        for servo_n, func_val in pairs:
            set_servo_function(mav, servo_n, func_val)
        print()

    print("Fetching servo mapping...")
    mapping = fetch_servo_params(mav, args.count)

    print(f"\n{'Output':<8} {'Function ID':<13} {'Function Name'}")
    print('-' * 45)
    for n in sorted(mapping):
        fid = mapping[n]
        name = fn_name(fid)
        marker = ' ◄' if fid != 0 else ''
        print(f"SERVO{n:<3}  {fid:<13} {name}{marker}")
    print()
    print("Re-run with --set N=FUNC to change a mapping. Example:")
    print("  python3 servo_map.py --set 1=33 3=34 4=35")


if __name__ == '__main__':
    main()
