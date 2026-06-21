#!/usr/bin/env python3 -u
"""
General ArduPilot log monitor.

Shows STATUSTEXT messages (ArduPilot's internal log output) and optionally
any other MAVLink message types. Use this to verify initialization, check
for errors, and observe ArduPilot's runtime state.

Output is always written to logs/monitor_latest.log so it can be inspected
after the fact without relying on terminal scroll.

Usage:
    python3 monitor.py                        # STATUSTEXT only
    python3 monitor.py --types HEARTBEAT      # add specific types
    python3 monitor.py --types ALL            # dump everything
    python3 monitor.py --port /dev/ttyACM0
"""

import sys
import time
import argparse
import os
from pymavlink import mavutil

sys.path.insert(0, '.')
from connect import connect, request_message_interval

LOG_DIR = os.path.join(os.path.dirname(__file__), '..', '..', 'logs')
LOG_FILE = os.path.join(LOG_DIR, 'monitor_latest.log')

SEVERITY = {
    0: 'EMERG',
    1: 'ALERT',
    2: 'CRIT',
    3: 'ERROR',
    4: 'WARN',
    5: 'NOTICE',
    6: 'INFO',
    7: 'DEBUG',
}

COLORS = {
    'EMERG':  '\033[1;31m',
    'ALERT':  '\033[1;31m',
    'CRIT':   '\033[1;31m',
    'ERROR':  '\033[31m',
    'WARN':   '\033[33m',
    'NOTICE': '\033[36m',
    'INFO':   '\033[0m',
    'DEBUG':  '\033[2m',
}
RESET = '\033[0m'


def fmt_statustext(msg):
    sev = SEVERITY.get(msg.severity, f'SEV{msg.severity}')
    color = COLORS.get(sev, '')
    text = msg.text.rstrip('\x00').strip()
    return f"{color}[{sev:6s}] {text}{RESET}"


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--port', default='/dev/ttyACM0')
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('--types', nargs='+', default=[],
                        help='Additional MAVLink message types to print (or ALL)')
    args = parser.parse_args()

    mav = connect(args.port, args.baud)

    show_all = 'ALL' in args.types
    extra_types = set(args.types) - {'ALL'}

    # Request STATUSTEXT at a high rate so we don't miss startup messages
    request_message_interval(mav, mavutil.mavlink.MAVLINK_MSG_ID_STATUSTEXT, 10)
    request_message_interval(mav, mavutil.mavlink.MAVLINK_MSG_ID_SYS_STATUS, 1)

    last_voltage = None

    os.makedirs(LOG_DIR, exist_ok=True)
    print(f"\n--- Listening (Ctrl+C to stop) --- logging to {LOG_FILE}\n")
    try:
        with open(LOG_FILE, 'w') as log:
            while True:
                msg = mav.recv_match(blocking=True, timeout=1.0)
                if msg is None:
                    continue
                t = msg.get_type()
                if t == 'BAD_DATA':
                    continue
                ts = time.strftime('%H:%M:%S')
                if t == 'SYS_STATUS':
                    last_voltage = msg.voltage_battery / 1000.0
                    continue
                if t == 'STATUSTEXT':
                    batt = f"  \033[33m{last_voltage:.2f}V\033[0m" if last_voltage is not None else ''
                    line = f"{ts}  {fmt_statustext(msg)}{batt}"
                    plain = f"{ts}  [{SEVERITY.get(msg.severity, '?'):6s}] {msg.text.rstrip(chr(0)).strip()}  {last_voltage:.2f}V" if last_voltage else f"{ts}  [{SEVERITY.get(msg.severity, '?'):6s}] {msg.text.rstrip(chr(0)).strip()}"
                elif show_all or t in extra_types:
                    line = f"{ts}  [{t}] {msg.to_dict()}"
                    plain = line
                else:
                    continue
                print(line)
                log.write(plain + '\n')
                log.flush()
    except KeyboardInterrupt:
        print(f"\nDone. Log saved to {LOG_FILE}")


if __name__ == '__main__':
    main()
