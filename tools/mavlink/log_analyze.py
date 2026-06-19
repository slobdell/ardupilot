#!/usr/bin/env python3 -u
"""
Analyze an ArduPilot dataflash (.BIN) log for Avatar QLOITER debugging.

Prints a timeline of mode changes, then for each QLOITER segment shows:
  - Position error (PSCN/PSCE)
  - Attitude demand vs actual (ATT)
  - EKF health (NKF4)
  - Custom Avatar GCS text messages (AVC / AV6)

Usage:
    python3 log_analyze.py logs/00000026.BIN
    python3 log_analyze.py logs/00000026.BIN --mode QLOITER
    python3 log_analyze.py logs/00000026.BIN --dump-types   # list all message types in log
"""

import sys
import os
import argparse
from pymavlink import DFReader

MODE_NAMES = {
    0: 'MANUAL', 2: 'STABILIZE', 5: 'FBWA', 11: 'RTL', 12: 'LOITER',
    17: 'QSTABILIZE', 18: 'QHOVER', 19: 'QLOITER', 20: 'QLAND', 21: 'QRTL',
}


def mode_name(n):
    return MODE_NAMES.get(int(n), f'MODE{int(n)}')


def load_log(path):
    print(f"Loading {path} ...", file=sys.stderr)
    return DFReader.DFReader_binary(path, zero_time_base=True)


def get_mode_segments(log):
    """Return list of (mode_num, t_start, t_end) segments."""
    segments = []
    current_mode = None
    current_start = None

    log.rewind()
    while True:
        msg = log.recv_match(type=['MODE'], blocking=False)
        if msg is None:
            break
        t = msg._timestamp
        m = msg.Mode
        if current_mode is not None:
            segments.append((current_mode, current_start, t))
        current_mode = m
        current_start = t

    if current_mode is not None:
        segments.append((current_mode, current_start, float('inf')))
    return segments


def print_mode_timeline(segments):
    print("\n=== MODE TIMELINE ===")
    for mode, t_start, t_end in segments:
        dur = t_end - t_start if t_end != float('inf') else 0
        print(f"  t={t_start:7.1f}s  {mode_name(mode):<12}  ({dur:.1f}s)")


def analyze_segment(log, mode_num, t_start, t_end, label):
    """Print key metrics for one flight segment."""
    print(f"\n=== {label} (t={t_start:.1f}..{t_end:.1f}s) ===")

    # Collect all relevant messages in this time window
    psc_n, psc_e, att, qtun, text = [], [], [], [], []

    log.rewind()
    while True:
        msg = log.recv_match(
            type=['PSCN', 'PSCE', 'ATT', 'QTUN', 'MSG'],
            blocking=False)
        if msg is None:
            break
        t = msg._timestamp
        if t < t_start or t > t_end:
            continue
        mtype = msg.get_type()
        if mtype == 'PSCN':
            # PN=actual, DPN=desired; error = actual - desired
            psc_n.append((t, msg.PN, msg.DPN))
        elif mtype == 'PSCE':
            psc_e.append((t, msg.PE, msg.DPE))
        elif mtype == 'ATT':
            att.append((t, msg.Roll, msg.Pitch, msg.DesRoll, msg.DesPitch))
        elif mtype == 'QTUN':
            # ThO=throttle out, Alt=actual alt, DAlt=desired alt, Trn=transition
            qtun.append((t, msg.ThO, msg.Alt, msg.DAlt,
                         getattr(msg, 'Trn', 0), getattr(msg, 'TMix', 0)))
        elif mtype == 'MSG':
            txt = msg.Message
            if any(tag in txt for tag in ('AVC', 'AV6', 'AVC!')):
                text.append((t, txt))

    # Position error (actual - desired)
    if psc_n and psc_e:
        errs_n = [(t, pn - dpn) for t, pn, dpn in psc_n]
        errs_e = [(t, pe - dpe) for t, pe, dpe in psc_e]
        max_n = max(abs(e) for _, e in errs_n)
        max_e = max(abs(e) for _, e in errs_e)
        print(f"  Position error — max N={max_n:.1f}m  max E={max_e:.1f}m  "
              f"final N={errs_n[-1][1]:.1f}m  E={errs_e[-1][1]:.1f}m")
        print(f"  {'t':>6}  {'ErrN(m)':>8}  {'ErrE(m)':>8}  {'ActN':>7}  {'ActE':>7}")
        step = max(1, len(errs_n) // 12)
        for i in range(0, len(errs_n), step):
            tn, en = errs_n[i]
            ee = errs_e[i][1] if i < len(errs_e) else 0
            pn = psc_n[i][1]; pe = psc_e[i][1] if i < len(psc_e) else 0
            print(f"  {tn:6.1f}  {en:8.2f}  {ee:8.2f}  {pn:7.1f}  {pe:7.1f}")
    else:
        print("  No PSCN/PSCE data (check LOG_BITMASK includes PosCtrl)")

    # QTUN: altitude and throttle
    if qtun:
        print(f"\n  {'t':>6}  {'ThO':>5}  {'Alt':>6}  {'DAlt':>6}  {'Trn':>4}  {'TMix':>5}")
        step = max(1, len(qtun) // 12)
        for i in range(0, len(qtun), step):
            t, tho, alt, dalt, trn, tmix = qtun[i]
            print(f"  {t:6.1f}  {tho:5.2f}  {alt:6.1f}  {dalt:6.1f}  {trn:4}  {tmix:5.2f}")

    # Attitude demand vs actual
    if att:
        print(f"\n  {'t':>6}  {'Roll':>6}  {'DesRoll':>8}  {'Pitch':>6}  {'DesPitch':>9}")
        step = max(1, len(att) // 12)
        for i in range(0, len(att), step):
            t, r, p, dr, dp = att[i]
            print(f"  {t:6.1f}  {r:6.1f}  {dr:8.1f}  {p:6.1f}  {dp:9.1f}")

    # Avatar custom messages
    if text:
        print(f"\n  Custom Avatar logs:")
        for t, txt in text:
            print(f"    t={t:.1f}  {txt}")

    if not psc_n and not att and not text:
        print("  (no data found in this segment)")


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('log', help='Path to .BIN log file')
    parser.add_argument('--mode', default=None,
                        help='Only analyze segments of this mode (e.g. QLOITER)')
    parser.add_argument('--dump-types', action='store_true',
                        help='List all message types present in the log and exit')
    args = parser.parse_args()

    if not os.path.exists(args.log):
        print(f"ERROR: {args.log} not found")
        sys.exit(1)

    log = load_log(args.log)

    if args.dump_types:
        types = set()
        log.rewind()
        while True:
            msg = log.recv_match(blocking=False)
            if msg is None:
                break
            types.add(msg.get_type())
        print("Message types in log:")
        for t in sorted(types):
            print(f"  {t}")
        return

    segments = get_mode_segments(log)
    print_mode_timeline(segments)

    filter_mode = None
    if args.mode:
        rev = {v: k for k, v in MODE_NAMES.items()}
        filter_mode = rev.get(args.mode.upper())
        if filter_mode is None:
            print(f"Unknown mode '{args.mode}'. Known: {list(rev.keys())}")
            sys.exit(1)

    for i, (mode, t_start, t_end) in enumerate(segments):
        if filter_mode is not None and mode != filter_mode:
            continue
        dur = t_end - t_start if t_end != float('inf') else 0
        if dur < 1.0:
            continue
        label = f"{mode_name(mode)} segment {i+1}"
        analyze_segment(log, mode, t_start, t_end, label)


if __name__ == '__main__':
    main()
