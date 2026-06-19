"""Shared MAVLink connection helper used by all monitoring scripts."""

import argparse
import sys
from pymavlink import mavutil

DEFAULT_PORT = '/dev/ttyACM0'
DEFAULT_BAUD = 115200
ELRS_PORT = 'udpin:0.0.0.0:14550'


def get_args(description):
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('--port', default=DEFAULT_PORT, help=f'Serial port or UDP string (default: {DEFAULT_PORT})')
    parser.add_argument('--baud', type=int, default=DEFAULT_BAUD, help=f'Baud rate (default: {DEFAULT_BAUD})')
    parser.add_argument('--elrs', action='store_true', help=f'Connect via ELRS TX Backpack WiFi ({ELRS_PORT})')
    return parser.parse_args()


def connect(port=DEFAULT_PORT, baud=DEFAULT_BAUD, timeout=10, elrs=False):
    """Open a MAVLink connection and wait for the first heartbeat."""
    if elrs:
        port = ELRS_PORT
    is_udp = port.startswith('udp')
    print(f"Connecting to {port}{'' if is_udp else f' @ {baud}'}...")
    mav = mavutil.mavlink_connection(port, baud=baud)
    print("Waiting for heartbeat (arm/disarm switch must be accessible)...")
    hb = mav.wait_heartbeat(timeout=timeout)
    if hb is None:
        print("ERROR: No heartbeat received. Is ArduPilot running?")
        sys.exit(1)
    print(f"Connected — system {mav.target_system}, component {mav.target_component}, "
          f"type {hb.type}, autopilot {hb.autopilot}")
    return mav


def request_message_interval(mav, message_id, hz):
    """Ask ArduPilot to stream a specific message at the given rate."""
    mav.mav.command_long_send(
        mav.target_system,
        mav.target_component,
        mavutil.mavlink.MAV_CMD_SET_MESSAGE_INTERVAL,
        0,
        message_id,
        int(1e6 / hz),  # interval in microseconds
        0, 0, 0, 0, 0,
    )
