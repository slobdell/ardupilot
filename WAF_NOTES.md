# ArduPilot Waf Build System Notes

## Library Source Discovery

The ArduPilot `waf` build system (implemented in `Tools/ardupilotwaf/ap_library.py`) uses an automatic discovery mechanism to find source files within the `libraries/` directory.

### Key Finding: Non-Recursive Globbing
The `ap_library` function performs a glob for source files (`*.cpp`, `*.c`, `*.S`) using the following logic:
1.  It searches the **root** of the specific library directory (e.g., `libraries/AP_Motors/*.cpp`).
2.  It searches the **`utility/`** subdirectory if it exists.
3.  **Crucially:** it does **NOT** recursively search any other subdirectories (e.g., `libraries/AP_Motors/TVC/`).

### Impact on Build Failures
*   **Header Resolution:** If you include a header with a path (e.g., `#include "TVC/TVC_Core.h"`), the compiler will find the file, and the compilation of individual objects (like `AP_Motors6DOF.cpp.o`) will succeed.
*   **Linking Errors:** Because the build system doesn't know about the `.cpp` files inside the custom subdirectory, they are never compiled into object files. When the final binary is linked, you will get **"undefined reference"** errors for any symbols defined in those hidden source files.

### Standard Practice
To ensure new files are compiled and linked correctly in ArduPilot libraries:
*   Place all implementation (`.cpp`) and header (`.h`) files in the **root** of the library directory.
*   Alternatively, place them in the `utility/` subdirectory if you want to follow that specific ArduPilot convention.
*   Avoid creating new custom subdirectories for source files unless you are prepared to modify the `wscript` or build tools to explicitly include them.
