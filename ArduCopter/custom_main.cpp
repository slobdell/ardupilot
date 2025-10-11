#include "Copter.h"
#include "custom_main.h"
#include <AP_Vehicle/AP_Vehicle.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_HAL/AP_HAL.h>

// This is your new main entry point when RUN_CUSTOM_LOOP is true.
void newMain()
{
    // One-time initialization for our debug serial port.
    // We will use SERIAL7 (hal.uartH), which corresponds to UART8 on your board.
    static bool serial_initialized = false;
    if (!serial_initialized) {
        // Begin the serial port at 115200 baud.
        // The second argument 'false' means we are not using it for MAVLink.
        hal.uartH->begin(115200, false);
        serial_initialized = true;
    }

    // This function is called at ~400Hz. We need to slow down our printing
    // to avoid flooding the serial port. A static counter is a simple way to do this.
    static uint16_t counter = 0;

    // This will make the loop print approximately 4 times per second (400Hz / 100).
    if (counter % 100 == 0) {
        // Get attitude data
        float roll_rad = 0;
        float pitch_rad = 0;
        AP::vehicle()->get_osd_roll_pitch_rad(roll_rad, pitch_rad);
        float yaw_rad = AP::ahrs().get_yaw();

        // Convert to degrees
        float roll_deg = degrees(roll_rad);
        float pitch_deg = degrees(pitch_rad);
        float yaw_deg = degrees(yaw_rad);

        // Print to SERIAL7 (hal.uartH).
        hal.uartH->printf("Attitude: R:%.1f P:%.1f Y:%.1f\n", roll_deg, pitch_deg, yaw_deg);
    }

    counter++;
}