# ExpressLRS Automation Tool

A robust CLI suite to automate the building and flashing of ExpressLRS firmware for RadioMaster RP1/RP2 receivers.

## 🚀 Quick Start

### 1. Setup
Run the setup script on any fresh Linux/macOS machine:
```bash
./setup.sh
```

### 2. Build
Compile firmware with your desired hardware and binding phrase:
```bash
# For RP2 (default)
./elrs_tool.py build --phrase "your secret phrase"

# For RP1
./elrs_tool.py build --hw rp1 --phrase "your secret phrase"
```

### 3. Flash
**Via WiFi:**
1. Connect to the `ExpressLRS RX` network.
2. Run:
```bash
./elrs_tool.py flash-wifi
```

**Via Serial:**
```bash
./elrs_tool.py flash-serial --port /dev/ttyACM0
```

## 🛠 Features
- **Headless Workflow:** No GUI required; perfect for remote or automated environments.
- **Smart Archiving:** Every build is saved with metadata and timestamps for easy rollback.
- **Automatic Configuration:** Hardcoded for high-performance MAVLink (460,800 baud).
- **Dependency Isolation:** Uses Python virtual environments to keep your system clean.

## 📖 Documentation
- [Technical Manual](MANUAL.md) - Deep dive into architecture and configuration.
- [ExpressLRS Official Docs](https://www.expresslrs.org/) - Technical details on the firmware itself.

## ⚖️ License
This automation suite is provided under the MIT License. ExpressLRS itself is licensed under the GPLv3.