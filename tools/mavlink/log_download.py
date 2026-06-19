#!/usr/bin/env python3 -u
"""
Download dataflash logs from a connected ArduPilot flight controller.

By default downloads the most recent log. Use --list to see all available logs,
or --id N to download a specific one. Logs are saved to ../../logs/ by default.

Usage:
    python3 log_download.py                        # download latest log
    python3 log_download.py --list                 # list available logs
    python3 log_download.py --id 3                 # download log #3
    python3 log_download.py --elrs                 # connect via ELRS WiFi
    python3 log_download.py -o /tmp/flight.bin     # custom output path
"""

import sys
import os
import time
import argparse
from pymavlink import mavutil

sys.path.insert(0, os.path.dirname(__file__))
from connect import connect, ELRS_PORT

CHUNK_SIZE   = 90      # MAVLink LOG_DATA payload size
STREAM_TO    = 2.0    # idle timeout before triggering gap fill (seconds)
LOGS_DIR     = os.path.join(os.path.dirname(__file__), '..', '..', 'logs')


def list_logs(mav):
    """Return list of (id, size, time_utc) for all logs on the FC."""
    mav.mav.log_request_list_send(mav.target_system, mav.target_component, 0, 0xFFFF)
    logs = []
    deadline = time.time() + 10
    while time.time() < deadline:
        msg = mav.recv_match(type='LOG_ENTRY', blocking=True, timeout=2)
        if msg is None:
            break
        logs.append((msg.id, msg.size, msg.time_utc))
        if msg.id == msg.last_log_num:
            break
    return logs


def download_log(mav, log_id, log_size, out_path):
    """Download a single log by ID and write to out_path.

    Phase 1: one streaming request for the entire file — the FC sends as fast
             as it can without per-chunk round trips.
    Phase 2: targeted gap-fill requests for any chunks that were dropped.
    """
    print(f"Downloading log {log_id} ({log_size / 1024:.0f} KB) -> {out_path}")
    os.makedirs(os.path.dirname(os.path.abspath(out_path)), exist_ok=True)

    n_chunks = (log_size + CHUNK_SIZE - 1) // CHUNK_SIZE
    got = bytearray(n_chunks)
    n_got = 0
    t_start = time.time()
    last_print = t_start

    with open(out_path, 'wb') as f:
        f.seek(log_size - 1)
        f.write(b'\x00')

    def recv_and_store(f, timeout):
        """Read one LOG_DATA message and write it; return True if something received."""
        nonlocal n_got
        msg = mav.recv_match(type='LOG_DATA', blocking=True, timeout=timeout)
        if not msg or msg.id != log_id or msg.count == 0:
            return False
        i = msg.ofs // CHUNK_SIZE
        if 0 <= i < n_chunks and not got[i]:
            f.seek(msg.ofs)
            f.write(bytes(msg.data[:msg.count]))
            got[i] = 1
            n_got += 1
        return True

    def print_progress():
        nonlocal last_print
        now = time.time()
        if now - last_print >= 1.0:
            elapsed = now - t_start
            bytes_got = n_got * CHUNK_SIZE
            rate_kbs = bytes_got / elapsed / 1024 if elapsed else 0
            pct = n_got * 100 // n_chunks
            eta = (n_chunks - n_got) * CHUNK_SIZE / (rate_kbs * 1024) if rate_kbs else 0
            print(f"  {pct:3d}%  {n_got}/{n_chunks} chunks  "
                  f"{rate_kbs:.0f} KB/s  ETA {eta:.0f}s")
            last_print = now

    with open(out_path, 'r+b') as f:
        # Phase 1: stream the entire log in one request
        mav.mav.log_request_data_send(
            mav.target_system, mav.target_component,
            log_id, 0, 0xFFFFFFFF)

        last_rx = time.time()
        while n_got < n_chunks:
            if recv_and_store(f, timeout=0.05):
                last_rx = time.time()
            elif time.time() - last_rx > STREAM_TO:
                break   # stream dried up — move to gap fill
            print_progress()

        # Phase 2: request any missing chunks individually
        while n_got < n_chunks:
            missing = [i for i in range(n_chunks) if not got[i]]
            if not missing:
                break
            print(f"  Gap fill: {len(missing)} missing chunks")
            for i in missing:
                ofs = i * CHUNK_SIZE
                mav.mav.log_request_data_send(
                    mav.target_system, mav.target_component,
                    log_id, ofs, min(CHUNK_SIZE, log_size - ofs))

            last_rx = time.time()
            while n_got < n_chunks:
                if recv_and_store(f, timeout=0.05):
                    last_rx = time.time()
                elif time.time() - last_rx > STREAM_TO:
                    break
                print_progress()

    elapsed = time.time() - t_start
    rate_kbs = log_size / elapsed / 1024 if elapsed else 0
    print(f"  Done in {elapsed:.1f}s at {rate_kbs:.0f} KB/s  ({n_got}/{n_chunks} chunks)")
    return out_path


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--port', default='/dev/ttyACM0')
    parser.add_argument('--baud', type=int, default=115200)
    parser.add_argument('--elrs', action='store_true',
                        help=f'Connect via ELRS TX Backpack WiFi ({ELRS_PORT})')
    parser.add_argument('--list', action='store_true', help='List available logs and exit')
    parser.add_argument('--id', type=int, default=None, help='Log ID to download (default: latest)')
    parser.add_argument('-o', '--output', help='Output path (default: logs/NNNNN.BIN)')
    args = parser.parse_args()

    mav = connect(args.port, args.baud, elrs=args.elrs)

    print("Requesting log list...")
    logs = list_logs(mav)
    if not logs:
        print("ERROR: No logs found on flight controller.")
        sys.exit(1)

    if args.list:
        print(f"\n{'ID':>4}  {'Size':>10}  {'UTC Time'}")
        print("-" * 40)
        for log_id, size, ts in logs:
            t = time.strftime('%Y-%m-%d %H:%M:%S', time.gmtime(ts)) if ts else 'unknown'
            print(f"{log_id:>4}  {size/1024:>8.0f}K  {t}")
        return

    log_id = args.id if args.id is not None else logs[-1][0]
    match = [(i, s, t) for i, s, t in logs if i == log_id]
    if not match:
        print(f"ERROR: Log {log_id} not found. Available: {[i for i,_,_ in logs]}")
        sys.exit(1)

    _, log_size, _ = match[0]
    if args.output:
        out_path = args.output
    else:
        os.makedirs(LOGS_DIR, exist_ok=True)
        out_path = os.path.join(LOGS_DIR, f'{log_id:08d}.BIN')

    download_log(mav, log_id, log_size, out_path)
    print(f"\nSaved: {out_path}")
    print(f"Analyze: python3 tools/mavlink/log_analyze.py {out_path}")


if __name__ == '__main__':
    main()
