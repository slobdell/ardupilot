# QGroundControl Setup Guide (Linux)

**Date:** June 7, 2026
**Platform:** Ubuntu 24.04 LTS
**Version Installed:** v5.0.8

## Installation

### 1. System Dependencies
```bash
sudo apt install -y libxcb-xinerama0 libxkbcommon-x11-0 libxcb-cursor0 fuse
```

### 2. Download AppImage
Check the latest release at: https://github.com/mavlink/qgroundcontrol/releases

```bash
# Example for v5.0.8 (update version as needed)
wget -P ~/Downloads https://github.com/mavlink/qgroundcontrol/releases/download/v5.0.8/QGroundControl-x86_64.AppImage
chmod +x ~/Downloads/QGroundControl-x86_64.AppImage
```

### 3. USB/Serial Permissions
Required to connect to flight controllers over USB without sudo:
```bash
sudo usermod -a -G dialout $USER
sudo usermod -a -G plugdev $USER
# Log out and back in for group changes to take effect
```

### 4. Launch
```bash
~/Downloads/QGroundControl-x86_64.AppImage
```

## Connecting a Flight Controller

QGC auto-detects flight controllers on USB. Plug in the DAKE or MicoAir board and it will appear automatically. Connection settings (baud rate, port) are configured under **Application Settings → Comm Links** if auto-detection fails.

## Key Differences from Mission Planner

| Task | Mission Planner | QGroundControl |
| :--- | :--- | :--- |
| Parameter editor | Config/Tuning → Full Parameter List | Vehicle Setup → Parameters |
| Motor test | Optional Hardware → Motor Test | (not built-in — use MAVLink console) |
| MAVLink console | Terminal | Analyze Tools → MAVLink Console |
| Servo output config | Config/Tuning → Servo Output | Vehicle Setup → Power (limited) |
| Flight modes | Config/Tuning → Flight Modes | Vehicle Setup → Flight Modes |

**Note:** QGC has a more limited servo/output configuration UI than Mission Planner. For initial hardware setup (servo function assignment, DShot masks), Mission Planner may be easier. Once configured, QGC works well for parameter tuning and flight monitoring.

## ArduPilot-Specific Notes

- QGC fully supports ArduPlane/ArduCopter/QuadPlane parameter sets.
- Parameter names are identical to Mission Planner — all values in `Blimp_Design.md` apply directly.
- For custom firmware (our builds), QGC will prompt to download the latest stable firmware on connect — **decline this** and select "Skip" to keep your custom binary.
