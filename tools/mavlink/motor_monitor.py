#!/usr/bin/env python3 -u
"""
Motor/servo output monitor — live display of all servo outputs.

Shows raw PWM values for all 16 servo outputs and the normalized throttle
(0–1) for outputs identified as motors. Use this to verify that motors
initialized correctly and that mixer outputs look sane before arming.

Usage:
    python3 motor_monitor.py
    python3 motor_monitor.py --port /dev/ttyACM0
    python3 motor_monitor.py --motors 1 2 3 4 5 6    # mark specific outputs as motors
"""

import sys
import time
import argparse
from pymavlink import mavutil

sys.path.insert(0, '.')
from connect import connect, request_message_interval

PWM_MIN = 1000
PWM_MAX = 2000
BAR_WIDTH = 30
UINT16_MAX = 65535

# Default outputs treated as motors for the DAKE 24-motor config (M1-M8 = outputs 1-8)
DEFAULT_MOTOR_OUTPUTS = list(range(1, 9))


def pwm_bar(value, is_motor=False):
    if value == 0 or value == UINT16_MAX:
        return '  [------N/A------]      '
    clamped = max(PWM_MIN, min(PWM_MAX, value))
    pct = (clamped - PWM_MIN) / (PWM_MAX - PWM_MIN)
    filled = int(pct * BAR_WIDTH)
    bar = '#' * filled + '-' * (BAR_WIDTH - filled)
    label = f'{value:5d} µs'
    if is_motor:
        label += f'  ({pct*100:5.1f}%)'
    return f'  [{bar}] {label}'


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--port', default='/dev/ttyACM0')
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('--hz', type=float, default=10, help='Update rate in Hz (default: 10)')
    parser.add_argument('--motors', type=int, nargs='+', default=DEFAULT_MOTOR_OUTPUTS,
                        help='Output numbers to treat as motors (shows throttle %%)')
    args = parser.parse_args()

    mav = connect(args.port, args.baud)

    request_message_interval(mav, mavutil.mavlink.MAVLINK_MSG_ID_SERVO_OUTPUT_RAW, args.hz)

    motor_set = set(args.motors)
    num_outputs = 16
    first = True

    print("\n--- Motor/Servo Output Monitor (Ctrl+C to stop) ---")
    print(f"Outputs {sorted(motor_set)} treated as motors.\n")

    try:
        while True:
            msg = mav.recv_match(type='SERVO_OUTPUT_RAW', blocking=True, timeout=2.0)
            if msg is None:
                print("No SERVO_OUTPUT_RAW received.")
                continue

            outputs = [
                msg.servo1_raw, msg.servo2_raw, msg.servo3_raw, msg.servo4_raw,
                msg.servo5_raw, msg.servo6_raw, msg.servo7_raw, msg.servo8_raw,
                msg.servo9_raw, msg.servo10_raw, msg.servo11_raw, msg.servo12_raw,
                msg.servo13_raw, msg.servo14_raw, msg.servo15_raw, msg.servo16_raw,
            ]

            if not first:
                print(f'\033[{num_outputs + 3}A', end='')
            first = False

            armed = bool(mav.motors_armed())
            armed_str = '\033[1;32mARMED\033[0m' if armed else '\033[33mDISARMED\033[0m'
            print(f"Status: {armed_str}   Time: {time.strftime('%H:%M:%S')}")
            print()
            for i, val in enumerate(outputs):
                out_num = i + 1
                is_motor = out_num in motor_set
                tag = 'M' if is_motor else 'S'
                print(f"  {tag}{out_num:02d}{pwm_bar(val, is_motor)}")
            print()

    except KeyboardInterrupt:
        print("\nDone.")


if __name__ == '__main__':
    main()
