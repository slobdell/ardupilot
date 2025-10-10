#include "Copter.h"
#include "custom_main.h"
#include <AP_Vehicle/AP_Vehicle.h>
#include <AP_AHRS/AP_AHRS.h>

// This is your new main entry point when RUN_CUSTOM_LOOP is true.
// ArduPilot's initialization is complete, and all sensors and peripherals are available.
void newMain()
{
    // This is the correct, verified method for getting the vehicle's attitude
    // as used by modules like the OSD.

    float roll_rad = 0;
    float pitch_rad = 0;

    // get_osd_roll_pitch_rad populates the roll and pitch variables by reference
    AP::vehicle()->get_osd_roll_pitch_rad(roll_rad, pitch_rad);

    // Yaw is retrieved separately from the AHRS object, accessed via the AP::ahrs() singleton
    float yaw_rad = AP::ahrs().get_yaw();

    // Convert to degrees for printing
    float roll_deg = degrees(roll_rad);
    float pitch_deg = degrees(pitch_rad);
    float yaw_deg = degrees(yaw_rad);

    // Send the attitude information to the Ground Control Station (GCS)
    gcs().send_text(MAV_SEVERITY_INFO, "Attitude: R:%.1f P:%.1f Y:%.1f", roll_deg, pitch_deg, yaw_deg);
}

