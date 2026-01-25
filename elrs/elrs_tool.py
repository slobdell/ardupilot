#!/usr/bin/env python3
import argparse
import os
import subprocess
import shutil
import sys
import gzip
from datetime import datetime

REPO_URL = "https://github.com/ExpressLRS/ExpressLRS.git"
REPO_DIR = "ExpressLRS"
BACKUP_DIR = "backups"
TARGET_ENV = "Unified_ESP8285_2400_RX_via_UART"

def run_command(command, cwd=None, capture_output=False, env=None):
    """Utility to run shell commands."""
    try:
        result = subprocess.run(
            command,
            cwd=cwd,
            shell=True,
            check=True,
            text=True,
            capture_output=capture_output,
            env=env
        )
        return result
    except subprocess.CalledProcessError as e:
        print(f"Error executing: {command}")
        if e.stdout:
            print(f"Stdout: {e.stdout}")
        if e.stderr:
            print(f"Stderr: {e.stderr}")
        sys.exit(1)

def check_dependencies():
    """Verify that platformio, git, and curl are installed."""
    print("Checking dependencies...")
    # Check if we are in a venv and if pio is there
    pio_path = get_pio_cmd()
    
    deps = [(f"{pio_path} --version", "platformio"), ("git --version", "git"), ("curl --version", "curl")]
    for cmd, name in deps:
        try:
            subprocess.run(cmd.split(), stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, check=True)
        except (subprocess.CalledProcessError, FileNotFoundError):
            print(f"Error: '{name}' is not installed or not in PATH.")
            sys.exit(1)
    print("Dependencies verified.")

def get_pio_cmd():
    venv_pio = os.path.join(os.getcwd(), "venv", "bin", "pio")
    if os.path.exists(venv_pio):
        return venv_pio
    return "pio"

def get_latest_tag():
    """Fetches the latest stable tag from the repository."""
    if not os.path.exists(REPO_DIR):
        print(f"Cloning {REPO_URL} to get tags...")
        run_command(f"git clone --depth 1 {REPO_URL} {REPO_DIR}")

    print("Fetching latest stable tag...")
    run_command("git fetch --tags", cwd=REPO_DIR)
    # Get tags, filtering for standard version patterns
    result = run_command("git tag -l 'v[1-9]*'", cwd=REPO_DIR, capture_output=True)
    tags = result.stdout.strip().split('\n')
    tags = [t for t in tags if t.strip()]
    
    if not tags:
        return "3.5.6" # Proven stable version for this tool
        
    def semver_key(s):
        # Extract digits and return as list of ints for proper numeric comparison
        parts = []
        for part in s.strip('v').split('.'):
            # Take only the numeric part of each segment (handles 3.3.0-RC1 -> 3)
            num = ''.join(filter(str.isdigit, part))
            parts.append(int(num) if num else 0)
        return parts

    tags.sort(key=semver_key)
    latest = tags[-1]
    print(f"Detected latest tag: {latest}")
    return latest

def clean_repo():
    """Discard all local changes in the repository to ensure a fresh start."""
    if os.path.exists(REPO_DIR):
        print(f"Cleaning repository {REPO_DIR}...")
        # Discard untracked files and local changes
        run_command("git reset --hard", cwd=REPO_DIR)
        run_command("git clean -fd", cwd=REPO_DIR)

def build(args):
    """Handles the build process."""
    check_dependencies()
    pio_cmd = get_pio_cmd()
    
    # Clone or Update Repo
    if not os.path.exists(REPO_DIR):
        print(f"Cloning {REPO_URL}...")
        run_command(f"git clone {REPO_URL} {REPO_DIR}")
    else:
        print(f"Updating {REPO_DIR}...")
        run_command("git fetch --all", cwd=REPO_DIR)

    # Discard any local changes from previous runs
    clean_repo()

    # Checkout version
    version = args.version
    if not version:
        version = get_latest_tag()
    print(f"Checking out version {version}...")
    run_command(f"git checkout {version}", cwd=REPO_DIR)

    # Configure user_defines.txt
    print("Configuring user_defines.txt...")
    user_defines_path = os.path.join(REPO_DIR, "src", "user_defines.txt")
    defines = [
        "-DUSE_MAVLINK_PROTOCOL",
        "-DRCVR_UART_BAUD=460800",
        "-DAUTO_WIFI_ON_INTERVAL=20"
    ]
    if args.phrase:
        defines.append(f'-DMY_BINDING_PHRASE="{args.phrase}"')
        
    with open(user_defines_path, "w") as f:
        f.write("\n".join(defines) + "\n")

    # Inject hardware selection to bypass interactive menu
    hw_type = args.hw.lower()
    print(f"Injecting {hw_type.upper()} hardware selection...")
    unified_ini_path = os.path.join(REPO_DIR, "src", "targets", "unified.ini")
    
    try:
        with open(unified_ini_path, "r") as f:
            content = f.read()
        
        target_section = f"[env:{TARGET_ENV}]"
        if target_section in content:
            # Check if board_config is already set in this section
            section_content = content.split(target_section)[1].split("[")[0]
            if "board_config =" not in section_content:
                new_line = f"\nboard_config = radiomaster.rx_2400.{hw_type}"
                updated_content = content.replace(target_section, target_section + new_line)
                with open(unified_ini_path, "w") as f:
                    f.write(updated_content)
        else:
            print(f"Warning: Target section {target_section} not found in unified.ini.")
    except FileNotFoundError:
        print(f"Error: Unified configuration file not found at {unified_ini_path}.")
        print("This tool requires ExpressLRS v3.0 or newer.")
        sys.exit(1)

    # Patch source code to force MAVLink as default if USE_MAVLINK_PROTOCOL is defined
    print("Patching source code for MAVLink defaults...")
    config_cpp_path = os.path.join(REPO_DIR, "src", "lib", "CONFIG", "config.cpp")
    with open(config_cpp_path, "r") as f:
        config_content = f.read()
    
    # We move the patch to the start of the CheckUpdateFlashedUid function.
    # This function runs every boot and detects if a new firmware was just flashed.
    # We force the protocol to MAVLink if the 'discriminator' (flash ID) has changed.
    old_check_start = 'void RxConfig::CheckUpdateFlashedUid(bool skipDescrimCheck)\n{'
    new_check_start = (
        'void RxConfig::CheckUpdateFlashedUid(bool skipDescrimCheck)\n{\n'
        '    if (!skipDescrimCheck && m_config.flash_discriminator == firmwareOptions.flash_discriminator) return;\n'
        '#if defined(USE_MAVLINK_PROTOCOL)\n'
        '    m_config.serialProtocol = PROTOCOL_MAVLINK;\n'
        '#endif'
    )
    
    if old_check_start in config_content and "PROTOCOL_MAVLINK" not in config_content:
        config_content = config_content.replace(old_check_start, new_check_start)
        with open(config_cpp_path, "w") as f:
            f.write(config_content)

    # Compile
    print(f"Compiling for {TARGET_ENV} ({hw_type.upper()} Hardware)...")
    # Force a clean build to ensure the patch is applied
    print("Cleaning build cache...")
    run_command(f"{pio_cmd} run -e {TARGET_ENV} --target clean", cwd=os.path.join(REPO_DIR, "src"))
    run_command(f"{pio_cmd} run -e {TARGET_ENV}", cwd=os.path.join(REPO_DIR, "src"))

    # Archive
    if not os.path.exists(BACKUP_DIR):
        os.makedirs(BACKUP_DIR)
    
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    source_bin = os.path.join(REPO_DIR, "src", ".pio", "build", TARGET_ENV, "firmware.bin")
    
    # Archive original bin
    archive_name = f"elrs_{hw_type}_{version}_{timestamp}.bin"
    archive_path = os.path.join(BACKUP_DIR, archive_name)
    shutil.copy2(source_bin, archive_path)
    
    # Create and archive compressed gz (required for ESP8285 WiFi flash)
    archive_path_gz = archive_path + ".gz"
    print(f"Compressing firmware for WiFi flashing...")
    with open(source_bin, 'rb') as f_in:
        with gzip.open(archive_path_gz, 'wb') as f_out:
            shutil.copyfileobj(f_in, f_out)
            
    print(f"Build complete. Archived to {archive_path} and {archive_path_gz}")

def flash_wifi(args):
    """Handles flashing over WiFi."""
    check_dependencies()
    
    # Check for ELRS WiFi network (Linux specific attempt)
    try:
        print("Checking for ExpressLRS RX network...")
        result = run_command("nmcli -t -f ACTIVE,SSID dev wifi | grep '^yes'", capture_output=True)
        if "ExpressLRS RX" not in result.stdout:
            print("Warning: Could not confirm connection to 'ExpressLRS RX' via nmcli.")
            print("Ensure you are connected to the receiver's WiFi hotspot.")
    except Exception:
        print("Could not verify WiFi connection via nmcli. Proceeding with flash attempt...")

    # Find latest binary (prefer .gz)
    if not os.path.exists(BACKUP_DIR) or not os.listdir(BACKUP_DIR):
        print(f"Error: No binaries found in {BACKUP_DIR}. Run 'build' first.")
        sys.exit(1)
    
    binaries = sorted([f for f in os.listdir(BACKUP_DIR) if f.endswith(".bin.gz")])
    if not binaries:
        print("Warning: No .bin.gz found, falling back to .bin (may fail on ESP8285)")
        binaries = sorted([f for f in os.listdir(BACKUP_DIR) if f.endswith(".bin")])
    
    latest_bin = os.path.join(BACKUP_DIR, binaries[-1])
    file_size = os.path.getsize(latest_bin)
    
    print(f"Flashing {latest_bin} via WiFi (Size: {file_size} bytes)...")
    # -F "upload=@..." matches the field name used by ELRS v3 web UI
    # -H "X-Filesize: ..." tells the receiver exactly how much memory to allocate
    # -H "Expect:" disables the 100-continue header which often breaks small servers
    curl_cmd = (
        f'curl -v '
        f'-H "X-Filesize: {file_size}" '
        f'-H "Expect:" '
        f'-F "upload=@{latest_bin}" '
        f'http://10.0.0.1/update'
    )
    run_command(curl_cmd)

def flash_serial(args):
    """Handles flashing over serial/passthrough."""
    check_dependencies()
    pio_cmd = get_pio_cmd()
    print(f"Flashing for {TARGET_ENV} via Serial...")
    upload_cmd = f"{pio_cmd} run -e {TARGET_ENV} --target upload"
    if args.port:
        upload_cmd += f" --upload-port {args.port}"
    run_command(upload_cmd, cwd=os.path.join(REPO_DIR, "src"))

def main():
    parser = argparse.ArgumentParser(description="ExpressLRS Automation Tool")
    subparsers = parser.add_subparsers(dest="command", required=True)

    # Build command
    build_parser = subparsers.add_parser("build", help="Clone, configure, and compile firmware")
    build_parser.add_argument("--version", help="ExpressLRS version tag (e.g. 3.5.6)")
    build_parser.add_argument("--phrase", help="Binding phrase (optional)")
    build_parser.add_argument("--hw", choices=["rp1", "rp2"], default="rp2", help="Target hardware (default: rp2)")

    # Flash WiFi command
    subparsers.add_parser("flash-wifi", help="Flash firmware via WiFi")

    # Flash Serial command
    serial_parser = subparsers.add_parser("flash-serial", help="Flash firmware via Serial/Passthrough")
    serial_parser.add_argument("--port", help="Serial port (e.g. /dev/ttyACM0)")

    args = parser.parse_args()

    if args.command == "build":
        build(args)
    elif args.command == "flash-wifi":
        flash_wifi(args)
    elif args.command == "flash-serial":
        flash_serial(args)

if __name__ == "__main__":
    main()
