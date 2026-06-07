#!/usr/bin/env python3 -u
"""
RC input monitor — live display of all 18 RC channels.

Shows raw PWM values (typically 1000–2000 µs) and a visual bar for each
active channel. Use this to verify that SBUS/ELRS input is being received
and that channel assignments are correct.

Usage:
    python3 rc_monitor.py
    python3 rc_monitor.py --port /dev/ttyACM0 --hz 10
"""

import sys
import time
import argparse
from pymavlink import mavutil

sys.path.insert(0, '.')
from connect import connect, request_message_interval

NUM_CHANNELS = 18
PWM_MIN = 1000
PWM_MAX = 2000
BAR_WIDTH = 30
UINT16_MAX = 65535  # ArduPilot uses this for "not available"


def pwm_bar(value):
    if value == 0 or value == UINT16_MAX:
        return '  [------N/A------]'
    clamped = max(PWM_MIN, min(PWM_MAX, value))
    filled = int((clamped - PWM_MIN) / (PWM_MAX - PWM_MIN) * BAR_WIDTH)
    bar = '#' * filled + '-' * (BAR_WIDTH - filled)
    return f'  [{bar}] {value:5d}'


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--port', default='/dev/ttyACM0')
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('--hz', type=float, default=10, help='Update rate in Hz (default: 10)')
    args = parser.parse_args()

    mav = connect(args.port, args.baud)

    # Request RC_CHANNELS at the desired rate
    request_message_interval(mav, mavutil.mavlink.MAVLINK_MSG_ID_RC_CHANNELS, args.hz)

    print("\n--- RC Input Monitor (Ctrl+C to stop) ---")
    print("Values are PWM µs. N/A = channel not active.\n")

    last_msg = None
    try:
        while True:
            msg = mav.recv_match(type='RC_CHANNELS', blocking=True, timeout=2.0)
            if msg is None:
                print("No RC_CHANNELS received — check SERIAL5_PROTOCOL=23 and RC receiver connection.")
                continue

            last_msg = msg
            channels = [
                msg.chan1_raw, msg.chan2_raw, msg.chan3_raw, msg.chan4_raw,
                msg.chan5_raw, msg.chan6_raw, msg.chan7_raw, msg.chan8_raw,
                msg.chan9_raw, msg.chan10_raw, msg.chan11_raw, msg.chan12_raw,
                msg.chan13_raw, msg.chan14_raw, msg.chan15_raw, msg.chan16_raw,
                msg.chan17_raw, msg.chan18_raw,
            ]

            # Move cursor up to overwrite previous output
            if last_msg is not None:
                print(f'\033[{NUM_CHANNELS + 2}A', end='')

            print(f"RSSI: {msg.rssi if msg.rssi != 255 else 'N/A':>4}   "
                  f"Channels active: {msg.chancount:>2}   "
                  f"Time: {time.strftime('%H:%M:%S')}")
            print()
            for i, val in enumerate(channels):
                print(f"  CH{i+1:02d}{pwm_bar(val)}")

    except KeyboardInterrupt:
        print("\nDone.")


if __name__ == '__main__':
    main()
