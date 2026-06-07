#!/usr/bin/env python3 -u
"""
Dump all ArduPilot parameters to a .param file.

The output format is plain text (one PARAM_NAME,VALUE per line), compatible
with QGroundControl, Mission Planner, and param_apply.py.

Usage:
    python3 param_dump.py                          # dump to stdout
    python3 param_dump.py -o golden.param          # dump to file
    python3 param_dump.py --port /dev/ttyACM0 -o golden.param
"""

import sys
import time
import argparse
from pymavlink import mavutil

sys.path.insert(0, '.')
from connect import connect

def dump_params(mav, verbose=False):
    """Request all parameters and return as ordered list of (name, value) tuples."""
    params = {}
    total = None

    mav.mav.param_request_list_send(mav.target_system, mav.target_component)

    deadline = time.time() + 30
    last_progress = 0

    while time.time() < deadline:
        msg = mav.recv_match(type='PARAM_VALUE', blocking=True, timeout=2)
        if msg is None:
            # Re-request if we stalled
            if params:
                print(f"  stalled at {len(params)}/{total}, re-requesting...", file=sys.stderr)
                mav.mav.param_request_list_send(mav.target_system, mav.target_component)
                deadline = time.time() + 15
            continue

        params[msg.param_id] = msg.param_value
        if total is None:
            total = msg.param_count

        if verbose:
            pct = int(len(params) / total * 100) if total else 0
            if pct >= last_progress + 10:
                last_progress = pct
                print(f"  {pct}% ({len(params)}/{total})", file=sys.stderr)

        if total and len(params) >= total:
            break

    if total and len(params) < total:
        print(f"WARNING: only received {len(params)}/{total} parameters", file=sys.stderr)

    return sorted(params.items())


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--port', default='/dev/ttyACM0')
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('-o', '--output', help='Output .param file (default: stdout)')
    parser.add_argument('-v', '--verbose', action='store_true', help='Show progress')
    args = parser.parse_args()

    mav = connect(args.port, args.baud)
    print("Dumping parameters...", file=sys.stderr)
    params = dump_params(mav, verbose=args.verbose or bool(args.output))

    lines = [f"{name},{value:.9g}" for name, value in params]
    output = '\n'.join(lines) + '\n'

    if args.output:
        with open(args.output, 'w') as f:
            f.write(output)
        print(f"Saved {len(params)} parameters to {args.output}", file=sys.stderr)
    else:
        print(output, end='')


if __name__ == '__main__':
    main()
