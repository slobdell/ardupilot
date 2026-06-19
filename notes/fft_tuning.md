# FFT Notch Filter Tuning — Avatar Zoh Altus VTOL

**FC:** MicoAir H743  
**RC channel:** RC8 (3-position switch)

> RC8 is temporarily set to option 162 for the tuning flight, then reset to 0 afterward. The golden params store it as 0 when not actively tuning.

---

## Prerequisites

FFT must be enabled and RC8 assigned before the tuning flight. **FFT_ENABLE requires a reboot.**

```bash
python3 tools/mavlink/param_set.py FFT_ENABLE 1
python3 tools/mavlink/param_set.py RC8_OPTION 162
# Reboot FC before flying
```

After reboot, additional `FFT_*` params will appear in GCS. Defaults are fine — no further FFT params need changing before the analysis flight.

---

## Auto-Setup Flight Procedure

1. Take off in QSTABILIZE
2. Switch to QLOITER, achieve stable hover at normal cruise throttle
3. Flip RC8 to HIGH — hold for 30–60 seconds
4. Flip RC8 LOW (this triggers param write — must happen before disarm)
5. Land and disarm

The FC writes `INS_HNTCH_*` params automatically when the switch goes LOW.

> **Note:** Auto-setup writes `INS_HNTCH_MODE=1` (throttle-based scaling), not mode 4 (FFT-driven). It uses FFT to *detect* the noise frequency, then sets up a throttle-scaled notch. This is expected and correct — lower latency than FFT-driven mode.

---

## After the Flight

Reset RC8 and dump params:

```bash
python3 tools/mavlink/param_set.py RC8_OPTION 0
python3 tools/mavlink/param_dump.py -v -o params/avatar_t1ranger_micoair.param
# or via ELRS:
# python3 tools/mavlink/param_set.py --elrs RC8_OPTION 0
# python3 tools/mavlink/param_dump.py --elrs -v -o params/avatar_t1ranger_micoair.param
```

Check `git diff params/` — look for `INS_HNTCH_ENABLE`, `INS_HNTCH_FREQ`, `INS_HNTCH_MODE` changes. If none appear, the auto-setup did not fire (see Troubleshooting below).

---

## Verification Flight

Power cycle, then take off. The notch filter is now active. Verify:

- Attitude control feels the same or better (no new oscillation)
- Download log: `python3 tools/mavlink/log_download.py --elrs`
- Check `FTN` messages — `PkAvg` field shows the FFT-detected noise peak; confirm the notch is tracking near that frequency
- Check `PERF` messages for CPU load

---

## Manual Setup (if auto-setup is unreliable)

If the RC8 auto-setup doesn't reliably write params, set manually after an analysis flight:

```bash
python3 tools/mavlink/param_set.py --elrs INS_HNTCH_ENABLE 1
python3 tools/mavlink/param_set.py --elrs INS_HNTCH_MODE 4      # 4 = FFT-driven
python3 tools/mavlink/param_set.py --elrs INS_HNTCH_REF 1       # 1 = no scaling
python3 tools/mavlink/param_set.py --elrs INS_HNTCH_FREQ <Hz>   # peak from FTN log
```

`INS_HNTCH_FREQ` in FFT mode is a floor, not a fixed center — FFT tracks dynamically above it.

Default `INS_HNTCH_BW` = `INS_HNTCH_FREQ / 2`. Only adjust if needed after verification flight.

---

## Troubleshooting

**`git diff` shows no `INS_HNTCH_*` changes after flight:**
- Most likely cause: `FFT_ENABLE=0` — FFT must be enabled and FC rebooted before the auto-setup flight
- Confirm with: `grep FFT_ENABLE params/avatar_t1ranger_micoair.param`

**Do not use firmware 4.3** — known bug with option 162 auto-setup.

---

## Key Tradeoffs

- FFT mode can lag throttle-based notch since FFT computation takes time — acceptable for this airframe since rotor frequency is fairly stable
- Enabling `INS_HNTCH_OPTS` bit 1 (multi-peak tracking) adds phase lag — only use if single-peak filter leaves residual noise; if used, reduce BW to `FREQ/4`
- Only 1 FFT-driven notch is supported; `INS_HNTC2` can be set to a different mode if a second notch is needed
