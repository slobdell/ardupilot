#!/bin/bash
set -e

# ExpressLRS Tool Setup Script
# This script prepares the environment for the elrs_tool.py automation.

echo "--- Initializing ExpressLRS Automation Environment ---"

# 1. Check for Python 3
if ! command -v python3 &> /dev/null; then
    echo "Error: python3 is not installed."
    exit 1
fi

# 2. Create Virtual Environment
echo "Creating virtual environment in ./venv..."
python3 -m venv venv

# 3. Install PlatformIO
echo "Installing PlatformIO Core..."
./venv/bin/pip install -U platformio --index-url https://pypi.org/simple

# 4. Make automation tool executable
if [ -f "elrs_tool.py" ]; then
    chmod +x elrs_tool.py
    echo "elrs_tool.py is now executable."
else
    echo "Warning: elrs_tool.py not found in current directory."
fi

echo "------------------------------------------------------"
echo "Setup Complete!"
echo "To build firmware, run:"
echo "  ./elrs_tool.py build --version 3.5.6"
echo ""
echo "To flash via WiFi, run:"
echo "  ./elrs_tool.py flash-wifi"
echo "------------------------------------------------------"
