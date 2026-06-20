#!/usr/bin/env python3 -u
"""
Analyze STABILIZE mode segments in an ArduPilot log for unexpected pitch-forward lurches.

Extracts ATT.Pitch, RCIN.C2, TILT.Tilt, CTUN.NavPitch, and Avatar debug messages,
detects rapid-pitch events, and prints timeline and context around each event.

Usage:
    python3 tools/mavlink/analyze_stabilize.py logs/fc_log_20.BIN
"""

import sys
import os
import argparse
from collections import defaultdict
from pymavlink import DFReader

MODE_NAMES = {
    0: 'MANUAL', 2: 'STABILIZE', 5: 'FBWA', 11: 'RTL', 12: 'LOITER',
    17: 'QSTABILIZE', 18: 'QHOVER', 19: 'QLOITER', 20: 'QLAND', 21: 'QRTL',
}

# RC channel 2 neutral (PWM). Values outside ±DEADBAND from this are "input".
RCIN_C2_NEUTRAL = 1500
RCIN_DEADBAND = 30  # PWM units (~2% of full range)

# Pitch change threshold to flag as a lurch event (degrees in 0.5s window)
LURCH_THRESHOLD_DEG = 5.0


def load_log(path):
    print(f"Loading {path} ...", file=sys.stderr)
    return DFReader.DFReader_binary(path, zero_time_base=True)


def get_mode_segments(log):
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


def collect_stabilize_data(log, t_start, t_end):
    """Collect all relevant streams for a STABILIZE segment."""
    att = []    # (t, roll, pitch, des_roll, des_pitch)
    rcin = []   # (t, c2_pwm)
    tilt = []   # (t, tilt_deg)
    ctun = []   # (t, nav_pitch, pitch)
    msgs = []   # (t, text)

    log.rewind()
    while True:
        msg = log.recv_match(
            type=['ATT', 'RCIN', 'TILT', 'CTUN', 'MSG'],
            blocking=False)
        if msg is None:
            break
        t = msg._timestamp
        if t < t_start or t > t_end:
            continue
        mt = msg.get_type()
        if mt == 'ATT':
            att.append((t, msg.Roll, msg.Pitch, msg.DesRoll, msg.DesPitch))
        elif mt == 'RCIN':
            rcin.append((t, msg.C2))
        elif mt == 'TILT':
            tilt.append((t, msg.Tilt))
        elif mt == 'CTUN':
            ctun.append((t, msg.NavPitch, msg.Pitch))
        elif mt == 'MSG':
            txt = msg.Message
            if any(tag in txt for tag in ('AVC', 'AV6', 'AVB', 'AVC!')):
                msgs.append((t, txt))

    return att, rcin, tilt, ctun, msgs


def interp(series, t):
    """Linear interpolate a (t, v) series at time t. Returns None if out of range."""
    if not series:
        return None
    for i in range(len(series) - 1):
        t0, v0 = series[i][0], series[i][1]
        t1, v1 = series[i + 1][0], series[i + 1][1]
        if t0 <= t <= t1:
            frac = (t - t0) / (t1 - t0) if t1 != t0 else 0
            return v0 + frac * (v1 - v0)
    # clamp to endpoints
    if t <= series[0][0]:
        return series[0][1]
    return series[-1][1]


def detect_lurch_events(att, window=0.5, threshold=LURCH_THRESHOLD_DEG):
    """Find timestamps where pitch changes by >threshold degrees in 'window' seconds."""
    events = []
    for i, (t, _, pitch, _, _) in enumerate(att):
        # look ahead window seconds
        for j in range(i + 1, len(att)):
            t2, _, pitch2, _, _ = att[j]
            if t2 - t > window:
                break
            if abs(pitch2 - pitch) >= threshold:
                events.append((t, t2, pitch, pitch2, pitch2 - pitch))
                break
    # deduplicate: merge events within 2s of each other
    merged = []
    for ev in events:
        if merged and ev[0] - merged[-1][0] < 2.0:
            continue
        merged.append(ev)
    return merged


def print_context(t_event, att, rcin, tilt, ctun, msgs, window=3.0):
    """Print data ±window seconds around a lurch event."""
    t0 = t_event - window
    t1 = t_event + window

    # Build a time-aligned table at ATT resolution
    att_win = [(t, r, p, dr, dp) for t, r, p, dr, dp in att if t0 <= t <= t1]

    print(f"\n  {'t':>7}  {'Pitch':>7}  {'DesPitch':>9}  {'RCIN.C2':>8}  "
          f"{'Tilt':>6}  {'NavPitch':>9}  {'Pilot?':>7}")
    for t, roll, pitch, des_roll, des_pitch in att_win:
        rc2 = interp(rcin, t)
        tilt_v = interp(tilt, t)
        nav = interp([(ct, np) for ct, np, _ in ctun], t) if ctun else None

        pilot = ""
        if rc2 is not None:
            dev = rc2 - RCIN_C2_NEUTRAL
            if abs(dev) > RCIN_DEADBAND:
                pilot = f"YES({dev:+.0f})"

        marker = " <-- LURCH" if abs(t - t_event) < 0.3 else ""

        print(f"  {t:7.2f}  {pitch:7.2f}  {des_pitch:9.2f}  "
              f"{rc2 if rc2 else 0:8.0f}  "
              f"{tilt_v if tilt_v else 0:6.1f}  "
              f"{nav if nav else 0:9.2f}  "
              f"{pilot:>7}{marker}")

    # Avatar debug messages in this window
    msgs_win = [(t, txt) for t, txt in msgs if t0 <= t <= t1]
    if msgs_win:
        print(f"\n  Avatar debug messages:")
        for t, txt in msgs_win:
            print(f"    t={t:.2f}  {txt}")


def analyze_segment(log, seg_num, t_start, t_end, att, rcin, tilt, ctun, msgs):
    dur = t_end - t_start if t_end != float('inf') else 0
    print(f"\n{'='*70}")
    print(f"STABILIZE segment {seg_num}  t={t_start:.1f}..{t_end:.1f}s  ({dur:.1f}s)")
    print(f"{'='*70}")

    if not att:
        print("  (no ATT data)")
        return

    # Overall pitch range
    pitches = [p for _, _, p, _, _ in att]
    print(f"  Pitch range: min={min(pitches):.1f}°  max={max(pitches):.1f}°")

    # RC2 summary
    if rcin:
        c2_vals = [c2 for _, c2 in rcin]
        deviations = [abs(c - RCIN_C2_NEUTRAL) for c in c2_vals]
        max_dev = max(deviations)
        n_active = sum(1 for d in deviations if d > RCIN_DEADBAND)
        print(f"  RCIN.C2: neutral={RCIN_C2_NEUTRAL}  "
              f"max_deviation={max_dev:.0f}  "
              f"samples_outside_deadband={n_active}/{len(rcin)}")
    else:
        print("  RCIN.C2: (no data)")

    # Tilt summary
    if tilt:
        tilt_vals = [tv for _, tv in tilt]
        print(f"  TILT: min={min(tilt_vals):.1f}°  max={max(tilt_vals):.1f}°  "
              f"at_start={tilt_vals[0]:.1f}°  at_end={tilt_vals[-1]:.1f}°")
    else:
        print("  TILT: (no data)")

    # Mode transition: tilt value just before this segment
    print(f"\n  --- Lurch event detection (>{LURCH_THRESHOLD_DEG}° in 0.5s) ---")
    events = detect_lurch_events(att)
    if not events:
        print("  No lurch events detected above threshold.")
    else:
        print(f"  Found {len(events)} lurch event(s):")
        for i, (t_ev, t_ev2, p1, p2, dp) in enumerate(events):
            print(f"\n  Event {i+1}: t={t_ev:.2f}s  pitch {p1:.1f}° -> {p2:.1f}°  "
                  f"(Δ={dp:+.1f}°  forward={'YES' if dp < 0 else 'NO'})")
            print_context(t_ev, att, rcin, tilt, ctun, msgs)

    # Avatar debug messages
    if msgs:
        print(f"\n  --- Avatar debug messages ({len(msgs)} total) ---")
        for t, txt in msgs:
            print(f"    t={t:.2f}  {txt}")
    else:
        print("\n  (no Avatar debug messages in this segment)")

    # Show tilt at mode entry (first 2 seconds)
    tilt_at_entry = [(t, tv) for t, tv in tilt if t <= t_start + 2.0]
    if tilt_at_entry:
        print(f"\n  --- Tilt in first 2s (mode entry) ---")
        for t, tv in tilt_at_entry[:20]:
            rc2 = interp(rcin, t)
            print(f"    t={t:.2f}  tilt={tv:.2f}°  rc2={rc2:.0f}")


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('log', help='Path to .BIN log file')
    parser.add_argument('--lurch-threshold', type=float, default=LURCH_THRESHOLD_DEG,
                        help=f'Pitch change threshold for lurch detection (default {LURCH_THRESHOLD_DEG}°)')
    args = parser.parse_args()

    if not os.path.exists(args.log):
        print(f"ERROR: {args.log} not found")
        sys.exit(1)

    log = load_log(args.log)
    segments = get_mode_segments(log)

    print("\n=== MODE TIMELINE ===")
    for mode, t_start, t_end in segments:
        dur = t_end - t_start if t_end != float('inf') else 0
        name = MODE_NAMES.get(int(mode), f'MODE{int(mode)}')
        print(f"  t={t_start:7.1f}s  {name:<12}  ({dur:.1f}s)")

    stabilize_segs = [(i + 1, t_start, t_end)
                      for i, (mode, t_start, t_end) in enumerate(segments)
                      if mode == 2 and (t_end - t_start if t_end != float('inf') else 0) >= 3.0]

    if not stabilize_segs:
        print("\nNo STABILIZE segments >= 3s found.")
        return

    print(f"\nFound {len(stabilize_segs)} STABILIZE segment(s) >= 3s")

    for seg_num, t_start, t_end in stabilize_segs:
        att, rcin, tilt, ctun, msgs = collect_stabilize_data(log, t_start, t_end)
        analyze_segment(log, seg_num, t_start, t_end, att, rcin, tilt, ctun, msgs)


if __name__ == '__main__':
    main()
